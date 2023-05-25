#include <zmesh/core/mesh_kernel.h>

namespace zmesh {
namespace core { 

MeshKernel::MeshKernel() {
    vpoints_ = add_vertex_property<Point>(PropertyNames::vpoints_);

    vertices_ = add_vertex_property<VertexTopology>(PropertyNames::vertices_);
    edges_ = add_edge_property<EdgeTopology>(PropertyNames::edges_);
    halfedges_ = add_halfedge_property<HalfedgeTopology>(PropertyNames::halfedges_);
    faces_ = add_face_property<FaceTopology>(PropertyNames::faces_);

    v_deleted_bits_ = add_vertex_property<bool>(PropertyNames::v_deleted_bits_, false);
    e_deleted_bits_ = add_edge_property<bool>(PropertyNames::e_deleted_bits_, false);
    f_deleted_bits_ = add_face_property<bool>(PropertyNames::f_deleted_bits_, false);
}

MeshKernel& MeshKernel::operator=(const MeshKernel& rhs) {
    if (this != &rhs) {
        // deep copy of properties
        vprops_ = rhs.vprops_;
        eprops_ = rhs.eprops_;
        hprops_ = rhs.hprops_;
        fprops_ = rhs.fprops_;

        // property handle contain pointer, have to be copy by hand.
        vpoints_ = get_or_add_vertex_property<Point>(PropertyNames::vpoints_);

        vertices_ = get_or_add_vertex_property<VertexTopology>(PropertyNames::vertices_);
        edges_ = get_or_add_edge_property<EdgeTopology>(PropertyNames::edges_);
        halfedges_ = get_or_add_halfedge_property<HalfedgeTopology>(PropertyNames::halfedges_);
        faces_ = get_or_add_face_property<FaceTopology>(PropertyNames::faces_);

        v_deleted_bits_ = get_or_add_vertex_property<bool>(PropertyNames::v_deleted_bits_);
        e_deleted_bits_ = get_or_add_edge_property<bool>(PropertyNames::e_deleted_bits_);
        f_deleted_bits_ = get_or_add_face_property<bool>(PropertyNames::f_deleted_bits_);

        n_deleted_vertices_ = rhs.n_deleted_vertices_;
        n_deleted_edges_ = rhs.n_deleted_edges_;
        n_deleted_faces_ = rhs.n_deleted_faces_;

        has_garbage_ = rhs.has_garbage_;
    }
    return *this;
}

MeshKernel& MeshKernel::assign(const MeshKernel& rhs) {
    if (this != &rhs) {
        vprops_.clear();
        hprops_.clear();
        eprops_.clear();
        fprops_.clear();

        vpoints_ = add_vertex_property<Point>(PropertyNames::vpoints_);

        vertices_ = add_vertex_property<VertexTopology>(PropertyNames::vertices_);
        edges_ = add_edge_property<EdgeTopology>(PropertyNames::edges_);
        halfedges_ = add_halfedge_property<HalfedgeTopology>(PropertyNames::halfedges_);
        faces_ = add_face_property<FaceTopology>(PropertyNames::faces_);

        v_deleted_bits_ = add_vertex_property<bool>(PropertyNames::v_deleted_bits_, false);
        e_deleted_bits_ = add_edge_property<bool>(PropertyNames::e_deleted_bits_, false);
        f_deleted_bits_ = add_face_property<bool>(PropertyNames::f_deleted_bits_, false);

        // copy properties from [rhs]
        vpoints_.vector() = rhs.vpoints_.vector();
        vpoints_.default_value() = rhs.vpoints_.default_value();

        vertices_.vector() = rhs.vertices_.vector();
        vertices_.default_value() = rhs.vertices_.default_value();
        edges_.vector() = rhs.edges_.vector();
        edges_.default_value() = rhs.edges_.default_value();
        halfedges_.vector() = rhs.halfedges_.vector();
        halfedges_.default_value() = rhs.halfedges_.default_value();
        faces_.vector() = rhs.faces_.vector();
        faces_.default_value() = rhs.faces_.default_value();

        v_deleted_bits_.vector() = rhs.v_deleted_bits_.vector();
        v_deleted_bits_.default_value() = rhs.v_deleted_bits_.default_value();
        e_deleted_bits_.vector() = rhs.e_deleted_bits_.vector();
        e_deleted_bits_.default_value() = rhs.e_deleted_bits_.default_value();
        f_deleted_bits_.vector() = rhs.f_deleted_bits_.vector();
        f_deleted_bits_.default_value() = rhs.f_deleted_bits_.default_value();

        vprops_.resize(rhs.vertices_size());
        hprops_.resize(rhs.halfedges_size());
        eprops_.resize(rhs.edges_size());
        fprops_.resize(rhs.faces_size());

        n_deleted_vertices_ = rhs.n_deleted_vertices_;
        n_deleted_edges_ = rhs.n_deleted_edges_;
        n_deleted_faces_ = rhs.n_deleted_faces_;

        has_garbage_ = rhs.has_garbage_;
    }

    return *this;
}

void MeshKernel::free_memory() {
    vprops_.free_memory();
    hprops_.free_memory();
    eprops_.free_memory();
    fprops_.free_memory();
}

void MeshKernel::clear() {
    
    // remove all properties
    vprops_.clear();
    hprops_.clear();
    eprops_.clear();
    fprops_.clear();

    // really free their memory
    free_memory();

    // add the standard properties back
    vpoints_ = add_vertex_property<Point>(PropertyNames::vpoints_);
    vertices_ = add_vertex_property<VertexTopology>(PropertyNames::vertices_);
    edges_ = add_edge_property<EdgeTopology>(PropertyNames::edges_);
    halfedges_ = add_halfedge_property<HalfedgeTopology>(PropertyNames::halfedges_);
    faces_ = add_face_property<FaceTopology>(PropertyNames::faces_);
    v_deleted_bits_ = add_vertex_property<bool>(PropertyNames::v_deleted_bits_, false);
    e_deleted_bits_ = add_edge_property<bool>(PropertyNames::e_deleted_bits_, false);
    f_deleted_bits_ = add_face_property<bool>(PropertyNames::f_deleted_bits_, false);

    // set initial status (as in constructor)
    n_deleted_vertices_ = 0;
    n_deleted_edges_ = 0;
    n_deleted_faces_ = 0;
    has_garbage_ = false;

}

VertexHandle MeshKernel::new_vertex() {
    if (vertices_size() == INDEX_MAX - 1) {
        throw std::runtime_error("can not add vertex, index will exceed INDEX_MAX");
    }

    vprops_.push_back();
    
    return VertexHandle(vertices_size() - 1);
}

HalfedgeHandle MeshKernel::new_edge() {
    if (halfedges_size() >= INDEX_MAX - 2) {
        throw std::runtime_error("can not add edge, index will exceed INDEX_MAX");
    }

    eprops_.push_back();
    hprops_.push_back();
    hprops_.push_back();

    auto h0 = HalfedgeHandle(halfedges_size() - 2);
    auto h1 = HalfedgeHandle(halfedges_size() - 1);

    return h0;
}

HalfedgeHandle MeshKernel::new_edge(VertexHandle start, VertexHandle end) {
    if (start == end) {
        throw std::invalid_argument("start and end are the same Vertex Handle");
    }
    
    if (halfedges_size() >= INDEX_MAX - 2) {
        throw std::runtime_error("can not add edge, index will exceed INDEX_MAX");
    }
    eprops_.push_back();
    hprops_.push_back();
    hprops_.push_back();

    auto h0 = HalfedgeHandle(halfedges_size() - 2);
    auto h1 = HalfedgeHandle(halfedges_size() - 1);

    set_to_vertex(h0, end);
    set_to_vertex(h1, start);

    return h0;
}

FaceHandle MeshKernel::new_face() {
    if (faces_size() == INDEX_MAX - 1) {
        throw std::runtime_error("can not add face, index will exceed INDEX_MAX");
    }

    fprops_.push_back();

    return FaceHandle(faces_size() - 1);
}

}
}