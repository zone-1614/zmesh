/**
 * @file mesh.h
 * @author zone-1614 (you@domain.com)
 * @brief Mesh数据结构的实现
 * 本文件实现了: <p>
 * 1. 较高级别的拓扑操作 <p>
 * 2. 迭代器 <p>
 * 3. Circulators(这个不会翻译)
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <memory>

#include <zmesh/core/mesh_kernel.h>
#include <zmesh/core/iterators.h>
#include <zmesh/core/circulators.h>
#include <zmesh/core/smart_handles.h>

namespace zmesh {
namespace core {

//! @class Mesh
//! @brief Mesh类提供了用户常用的操作
class Mesh : public MeshKernel {
public:
    Mesh() = default;

    virtual ~Mesh() {
        
    }

    // Mesh(const Mesh& rhs) { 
    //     operator=(rhs);
    // }

    // also copy all the properties
    // Mesh& operator=(const Mesh& rhs) {

    // }

    // does not copy any custom properties
    // Mesh& assign(const Mesh& rhs);

    /**
     * High Level Topological Operations
    */

    //! 找到从start开始, 到end结束的一条半边, 如果不存在就返回一个invalid的handle
    HalfedgeHandle find_halfedge(VertexHandle start, VertexHandle end) const;

    //! 找到连接v0, v1的边, 如果不存在就返回一个invalid的handle
    EdgeHandle find_edge(VertexHandle v0, VertexHandle v1) const;

    //! 调整顶点v的halfedge, 当v是边界的时候, halfedge也是边界
    void Mesh::adjust_outgoing_halfedge(VertexHandle v);

    //! 添加一个顶点, 同时赋予其坐标
    SmartVertexHandle add_vertex(const Point& p);

    //! 添加一个顶点, 同时赋予其坐标
    SmartVertexHandle add_vertex(float x, float y, float z);

    //! 通过参数传入的顶点, 添加一个面
    SmartFaceHandle add_face(const std::vector<VertexHandle>& vertices);

    //! 添加一个三角形
    SmartFaceHandle add_triangle(VertexHandle v0, VertexHandle v1, VertexHandle v2);

    //! 添加一个三角形
    SmartFaceHandle add_triangle(const std::array<VertexHandle, 3>& vertices);

    //! 添加一个四边形
    SmartFaceHandle add_quad(VertexHandle v0, VertexHandle v1, VertexHandle v2, VertexHandle v3);

    //! 添加一个四边形
    SmartFaceHandle add_quad(const std::array<VertexHandle, 4>& vertices);

    //! 顶点v的邻接顶点个数
    int valence(VertexHandle v) const; // number of 1 ring

    //! 面f邻接的顶点个数
    int valence(FaceHandle f) const; // number of vertices that incident with this face

    //! 是不是三角形网格
    bool is_triangle_mesh() const;

    //! 是不是四边形网格
    bool is_quad_mesh() const;

    //! 网格是否为空
    bool is_empty() const {
        return n_vertices() == 0;
    }

    // remove all vertices, edges, faces
    // virtual void clear();

    /**
     * Iterators
    */

    VertexIterator vertices_begin() const {
        return VertexIterator(make_smart(VertexHandle(0), this));
    }

    VertexIterator vertices_end() const {
        return VertexIterator(make_smart(VertexHandle(n_vertices()), this));
    }

    //! 用来遍历所有点
    VertexRange vertices() const {
        return VertexRange(vertices_begin(), vertices_end());
    }

    EdgeIterator edges_begin() const {
        return EdgeIterator(make_smart(EdgeHandle(0), this));
    }

    EdgeIterator edges_end() const {
        return EdgeIterator(make_smart(EdgeHandle(n_edges()), this));
    }

    //! 用来遍历所有边
    EdgeRange edges() const {
        return EdgeRange(edges_begin(), edges_end());
    }

    HalfedgeIterator halfedges_begin() const {
        return HalfedgeIterator(make_smart(HalfedgeHandle(0), this));
    }

    HalfedgeIterator halfedges_end() const {
        return HalfedgeIterator(make_smart(HalfedgeHandle(n_halfedges()), this));
    }

    //! 用来遍历所有半边
    HalfedgeRange halfedges() const {
        return HalfedgeRange(halfedges_begin(), halfedges_end());
    }

    FaceIterator faces_begin() const {
        return FaceIterator(make_smart(FaceHandle(0), this));
    }

    FaceIterator faces_end() const {
        return FaceIterator(make_smart(FaceHandle(n_faces()), this));
    }

    //! 用来遍历所有面
    FaceRange faces() const {
        return FaceRange(faces_begin(), faces_end());
    }

    
    /**
     * Circulators
    */

    //! @brief 
    //! @param vertex 中心
    VertexAroundVertexCirculator vertices(VertexHandle vertex) const {
        return VertexAroundVertexCirculator(this, vertex);
    }

    //! @brief 
    //! @param vertex 中心
    EdgeAroundVertexCirculator edges(VertexHandle vertex) const {
        return EdgeAroundVertexCirculator(this, vertex);
    }


    //! @brief 
    //! @param vertex 中心
    HalfedgeAroundVertexCirculator halfedges(VertexHandle vertex) const {
        return HalfedgeAroundVertexCirculator(this, vertex);
    }


    //! @brief 
    //! @param vertex 中心
    FaceAroundVertexCirculator faces(VertexHandle vertex) const {
        return FaceAroundVertexCirculator(this, vertex);
    }


    //! @brief 
    //! @param face 中心
    VertexAroundFaceCirculator vertices(FaceHandle face) const {
        return VertexAroundFaceCirculator(this, face);
    }


    //! @brief 
    //! @param face 中心
    EdgeAroundFaceCirculator edges(FaceHandle face) const {
        return EdgeAroundFaceCirculator(this, face);
    }


    //! @brief 
    //! @param face 中心
    HalfedgeAroundFaceCirculator halfedges(FaceHandle face) const {
        return HalfedgeAroundFaceCirculator(this, face);
    }


    //! @brief 
    //! @param face 中心
    FaceAroundFaceCirculator faces(FaceHandle face) const {
        return FaceAroundFaceCirculator(this, face);
    }

    // TODO 还可以添加很多其他种类的Circulator, 不过上面的比较常用

private:
};

}
}