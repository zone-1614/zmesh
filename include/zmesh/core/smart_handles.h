#pragma once

#include <zmesh/core/mesh_kernel.h>
#include <zmesh/core/circulators.h>

namespace zmesh {
namespace core {
// Forward declaration
class SmartVertexHandle;
class SmartEdgeHandle;
class SmartHalfedgeHandle;
class SmartFaceHandle;

// Smart handle implementation
class SmartVertexHandle : public VertexHandle {
public:
    explicit SmartVertexHandle(Index idx = INDEX_MAX, const MeshKernel* mesh = nullptr)
        : VertexHandle(idx), mesh_(mesh) { }

    const MeshKernel* mesh() const {
        return mesh_;
    }

    /**
     * Topology
    */

    bool is_deleted() const;

    bool is_boundary() const;

    // Returns the point of vertex
    const Point& point() const;

    // Returns the reference point of vertex
    // Point& point();

    // void set_point(const Point& p);

    // void set_point(double x, double y, double z);

    // Returns an outgoing halfedge of this vertex
    SmartHalfedgeHandle halfedge() const;

    // alias for halfedge()
    SmartHalfedgeHandle out() const;

    // Returns an incoming halfedge of this vertex
    SmartHalfedgeHandle in() const;

    /**
     * Circulators
    */

    VertexAroundVertexCirculator vertices() const;

    VertexAroundVertexCWCirculator vertices_cw() const;

    VertexAroundVertexCCWCirculator vertices_ccw() const;

    EdgeAroundVertexCirculator edges() const;

    EdgeAroundVertexCWCirculator edges_cw() const;

    EdgeAroundVertexCCWCirculator edges_ccw() const;

    HalfedgeAroundVertexCirculator halfedges() const;

    OutgoingHalfedgeAroundVertexCirculator outgoing_halfedges() const;

    OutgoingHalfedgeAroundVertexCWCirculator outgoing_halfedges_cw() const;

    OutgoingHalfedgeAroundVertexCCWCirculator outgoing_halfedges_ccw() const;

    IncomingHalfedgeAroundVertexCirculator incoming_halfedges() const;

    IncomingHalfedgeAroundVertexCWCirculator incoming_halfedges_cw() const;

    IncomingHalfedgeAroundVertexCCWCirculator incoming_halfedges_ccw() const;

    FaceAroundVertexCirculator faces() const;

    FaceAroundVertexCWCirculator faces_cw() const;

    FaceAroundVertexCCWCirculator faces_ccw() const;

    // return the valence of this vertex
    unsigned int valence() const;

private:
    const MeshKernel* mesh_;
};

class SmartEdgeHandle : public EdgeHandle {
public:
    explicit SmartEdgeHandle(Index idx = INDEX_MAX, const MeshKernel* mesh = nullptr)
        : EdgeHandle(idx), mesh_(mesh) { }

    const MeshKernel* mesh() const {
        return mesh_;
    }

    /**
     * Topology
    */

    bool is_deleted() const;

    bool is_boundary() const;

    // returns one of the two incident halfedges of this edge
    SmartHalfedgeHandle halfedge(int i) const;

    // alias for halfedge(i)
    SmartHalfedgeHandle h(int i) const;

    // alias for h(0)
    SmartHalfedgeHandle h0() const;

    // alias for h(1)
    SmartHalfedgeHandle h1() const;

    // returns one of the two incident vertices of this edge
    // i should be 0 or 1
    SmartVertexHandle vertex(int i) const;

    // alias for vertex(i)
    SmartVertexHandle v(int i) const;

    // alias for v(0)
    SmartVertexHandle v0() const;

    // alias for v(1)
    SmartVertexHandle v1() const;

private:
    const MeshKernel* mesh_;
};

class SmartHalfedgeHandle : public HalfedgeHandle {
public:
    explicit SmartHalfedgeHandle(Index idx = INDEX_MAX, const MeshKernel* mesh = nullptr)
        : HalfedgeHandle(idx), mesh_(mesh) { }

    const MeshKernel* mesh() const {
        return mesh_;
    }

    /**
     * Topology
    */

    bool is_deleted() const;

    bool is_boundary() const;

    // Returns the next halfedge 
    SmartHalfedgeHandle next() const;

    SmartHalfedgeHandle prev() const;

    SmartHalfedgeHandle opp() const;

    SmartVertexHandle from() const;

    SmartVertexHandle to() const;

    SmartEdgeHandle edge() const;

    SmartFaceHandle face() const;

private:
    const MeshKernel* mesh_;
};

class SmartFaceHandle : public FaceHandle {
public:
    explicit SmartFaceHandle(Index idx = INDEX_MAX, const MeshKernel* mesh = nullptr)
        : FaceHandle(idx), mesh_(mesh) { }

    const MeshKernel* mesh() const {
        return mesh_;
    }

    /**
     * Topology
    */

    bool is_deleted() const;

    bool is_boundary() const ;

    SmartHalfedgeHandle halfedge() const;

    /**
     * Circulators
    */

    VertexAroundFaceCirculator vertices() const;

    VertexAroundFaceCWCirculator vertices_cw() const;

    VertexAroundFaceCCWCirculator vertices_ccw() const;

    EdgeAroundFaceCirculator edges() const;

    EdgeAroundFaceCWCirculator edges_cw() const;

    EdgeAroundFaceCCWCirculator edges_ccw() const;

    HalfedgeAroundFaceCirculator haledges() const;

    HalfedgeAroundFaceCWCirculator halfedges_cw() const;

    HalfedgeAroundFaceCCWCirculator halfedges_ccw() const;

    FaceAroundFaceCirculator faces() const;

    FaceAroundFaceCWCirculator faces_cw() const;

    FaceAroundFaceCCWCirculator faces_ccw() const;

    // return the valence of this vertex
    unsigned int valence() const;

private:
    const MeshKernel* mesh_;
};


/**
 * Create a smart handle from a handle and a mesh kernel
*/

inline SmartVertexHandle make_smart(VertexHandle v, const MeshKernel* mesh_kernel) {
    return SmartVertexHandle(v.idx(), mesh_kernel);
}

inline SmartVertexHandle make_smart(VertexHandle v, const MeshKernel& mesh_kernel) {
    return SmartVertexHandle(v.idx(), &mesh_kernel);
}

inline SmartEdgeHandle make_smart(EdgeHandle e, const MeshKernel* mesh_kernel) {
    return SmartEdgeHandle(e.idx(), mesh_kernel);
}

inline SmartEdgeHandle make_smart(EdgeHandle e, const MeshKernel& mesh_kernel) {
    return SmartEdgeHandle(e.idx(), &mesh_kernel);
}

inline SmartHalfedgeHandle make_smart(HalfedgeHandle h, const MeshKernel* mesh_kernel) {
    return SmartHalfedgeHandle(h.idx(), mesh_kernel);
}

inline SmartHalfedgeHandle make_smart(HalfedgeHandle h, const MeshKernel& mesh_kernel) {
    return SmartHalfedgeHandle(h.idx(), &mesh_kernel);
}

inline SmartFaceHandle make_smart(FaceHandle f, const MeshKernel* mesh_kernel) {
    return SmartFaceHandle(f.idx(), mesh_kernel);
}

inline SmartFaceHandle make_smart(FaceHandle f, const MeshKernel& mesh_kernel) {
    return SmartFaceHandle(f.idx(), &mesh_kernel);
}

}
}