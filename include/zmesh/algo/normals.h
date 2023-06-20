#pragma once

#include <zmesh/core/Mesh.h>

namespace zmesh {
namespace algo {

core::Normal vertex_normal(core::Mesh& mesh, core::VertexHandle& v) {
    // TODO
    return core::Normal(1, 1, 1);
}

core::VertexPropertyHandle<core::Normal> vertex_normals(core::Mesh& mesh) {
    auto vnormals = mesh.add_vertex_property<core::Normal>(core::PropertyNames::vnormals);
    for (auto v : mesh.vertices()) {
        vnormals[v] = vertex_normal(mesh, v);
    }
    return vnormals;
}

core::Normal face_normal(core::Mesh& mesh, core::FaceHandle& f) {
    // TODO
    return core::Normal(1, 1, 1);
}

core::FacePropertyHandle<core::Normal> face_normals(core::Mesh& mesh) {
    auto fnormals = mesh.add_face_property<core::Normal>(core::PropertyNames::fnormals);
    for (auto f : mesh.faces()) {
        fnormals[f] = face_normal(mesh, f);
    }
    return fnormals;
}

}
}