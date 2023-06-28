#pragma once

#include <zmesh/core/mesh.h>
#include <glm/glm.hpp>

namespace zmesh {
namespace algo {

//! 返回bounding box, 第一个返回值是 {min x, min y, min z}, 第二个返回值是 {max x, max y, max z}
std::pair<glm::vec3, glm::vec3> bounding_box(core::Mesh& mesh) {
    glm::vec3 bbmin, bbmax; // boudingbox min, max
    auto points = mesh.points();
    auto first = points.front();
    // 初始化bbmin, bbmax为第一个point
    bbmin[0] = first[0];
    bbmin[1] = first[1];
    bbmin[2] = first[2];
    bbmax[0] = first[0];
    bbmax[1] = first[1];
    bbmax[2] = first[2];
    for (auto p : points) {
        if (p[0] > bbmax[0]) bbmax[0] = p[0];
        if (p[1] > bbmax[1]) bbmax[1] = p[1];
        if (p[2] > bbmax[2]) bbmax[2] = p[2];
        if (p[0] < bbmin[0]) bbmin[0] = p[0];
        if (p[1] < bbmin[1]) bbmin[1] = p[1];
        if (p[2] < bbmin[2]) bbmin[2] = p[2];
    }
    return { bbmin, bbmax };
}

}
}