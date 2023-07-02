/**
 * @file normals.h
 * @author zone-1614 (you@domain.com)
 * @brief 法向相关算法
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// 为什么 normal 相关的函数不集成在mesh里面呢? 因为有时候法向是从文件里面读出来的, 不需要算法

#pragma once

#include <vector>

#include <zmesh/core/Mesh.h>

namespace zmesh {
namespace algo {

//! 定点顺序顺时针代表正面
//! 只适用于三角网格
core::Normal face_normal(core::Mesh& mesh, core::FaceHandle& f) {
    // 面周围的三个点
    std::vector<core::Point> points;
    for (auto v : mesh.vertices(f)) {
        points.push_back(mesh.point(v));
    }

    auto e02 = points[2] - points[0]; // edge from point 0 to point 2
    auto e01 = points[1] - points[0]; // edge from point 0 to point 1

    // 叉乘, 以后提取为常用函数
    // auto n = core::Normal(
    //     e02[1] * e01[2] - e02[2] * e01[1],
    //     e02[2] * e01[0] - e02[0] * e01[2],
    //     e02[0] * e01[1] - e02[1] * e01[0]
    // ); 
    return e01.cross(e02).normalized();
}

core::FacePropertyHandle<core::Normal> face_normals(core::Mesh& mesh) {
    auto fnormals = mesh.get_or_add_face_property<core::Normal>(core::PropertyNames::fnormals);
    for (auto f : mesh.faces()) {
        fnormals[f] = face_normal(mesh, f);
    }
    return fnormals;
}

//! 用周围的面法向来计算顶点法向
core::Normal vertex_normal(core::Mesh& mesh, core::VertexHandle& v) {
    auto fnormals = mesh.get_face_property<core::Normal>(core::PropertyNames::fnormals);
    core::Normal sum{0.0f, 0.0f, 0.0f}; // 邻域法向之和
    for (auto f : mesh.faces(v)) {
        if (!f.is_valid()) continue;
        sum += fnormals[f];
    }
    return sum.normalized();
}

core::VertexPropertyHandle<core::Normal> vertex_normals(core::Mesh& mesh) {
    face_normals(mesh);
    auto vnormals = mesh.get_or_add_vertex_property<core::Normal>(core::PropertyNames::vnormals);
    for (auto v : mesh.vertices()) {
        vnormals[v] = vertex_normal(mesh, v);
    }
    return vnormals;
}

}
}