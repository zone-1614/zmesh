#include <zmesh/core/smart_handles.h>

namespace zmesh {
namespace core {

/**
 * Implementation of SmartVertexHandle
*/
bool SmartVertexHandle::is_deleted() const {
    return mesh_->is_deleted(static_cast<VertexHandle>(*this));
}

bool SmartVertexHandle::is_boundary() const {
    return mesh_->is_boundary(static_cast<VertexHandle>(*this));
}

const Point& SmartVertexHandle::point() const {
    return mesh_->point(*this);
}

// Point& SmartVertexHandle::point() {
//     return mesh_->point(*this);
// }

// void SmartVertexHandle::set_point(const Point& p) {
    
// }

// void SmartVertexHandle::set_point(double x, double y, double z);

SmartHalfedgeHandle SmartVertexHandle::halfedge() const {
        return make_smart(mesh_->halfedge(static_cast<VertexHandle>(*this)), mesh_);
}

SmartHalfedgeHandle SmartVertexHandle::out() const {
    return make_smart(mesh_->outgoing_halfedge(static_cast<VertexHandle>(*this)), mesh_);
}

SmartHalfedgeHandle SmartVertexHandle::in() const {
    return make_smart(mesh_->incoming_halfedge(static_cast<VertexHandle>(*this)), mesh_);
}

VertexAroundVertexCirculator SmartVertexHandle::vertices() const {
    return VertexAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

VertexAroundVertexCWCirculator SmartVertexHandle::vertices_cw() const {
    return VertexAroundVertexCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

VertexAroundVertexCCWCirculator SmartVertexHandle::vertices_ccw() const {
    return VertexAroundVertexCCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

EdgeAroundVertexCirculator SmartVertexHandle::edges() const {
    return EdgeAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

EdgeAroundVertexCWCirculator SmartVertexHandle::edges_cw() const {
    return EdgeAroundVertexCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

EdgeAroundVertexCCWCirculator SmartVertexHandle::edges_ccw() const {
    return EdgeAroundVertexCCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

HalfedgeAroundVertexCirculator SmartVertexHandle::halfedges() const {
    return HalfedgeAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

OutgoingHalfedgeAroundVertexCirculator SmartVertexHandle::outgoing_halfedges() const {
    return OutgoingHalfedgeAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

OutgoingHalfedgeAroundVertexCWCirculator SmartVertexHandle::outgoing_halfedges_cw() const {
    return OutgoingHalfedgeAroundVertexCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

OutgoingHalfedgeAroundVertexCCWCirculator SmartVertexHandle::outgoing_halfedges_ccw() const {
    return OutgoingHalfedgeAroundVertexCCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

IncomingHalfedgeAroundVertexCirculator SmartVertexHandle::incoming_halfedges() const {
    return IncomingHalfedgeAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

IncomingHalfedgeAroundVertexCWCirculator SmartVertexHandle::incoming_halfedges_cw() const {
    return IncomingHalfedgeAroundVertexCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

IncomingHalfedgeAroundVertexCCWCirculator SmartVertexHandle::incoming_halfedges_ccw() const {
    return IncomingHalfedgeAroundVertexCCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

FaceAroundVertexCirculator SmartVertexHandle::faces() const {
    return FaceAroundVertexCirculator(mesh_, static_cast<VertexHandle>(*this));
}

FaceAroundVertexCWCirculator SmartVertexHandle::faces_cw() const {
    return FaceAroundVertexCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

FaceAroundVertexCCWCirculator SmartVertexHandle::faces_ccw() const {
    return FaceAroundVertexCCWCirculator(mesh_, static_cast<VertexHandle>(*this));
}

/**
 * Implementation of SmartEdgeHandle
*/

bool SmartEdgeHandle::is_deleted() const {
    return mesh_->is_deleted(static_cast<EdgeHandle>(*this));
}

bool SmartEdgeHandle::is_boundary() const {
    return mesh_->is_boundary(static_cast<EdgeHandle>(*this));
}

// returns one of the two incident halfedges of this edge
SmartHalfedgeHandle SmartEdgeHandle::halfedge(int i) const {
    return make_smart(mesh_->halfedge(static_cast<EdgeHandle>(*this), i), mesh_);
}

// alias for halfedge(i)
SmartHalfedgeHandle SmartEdgeHandle::h(int i) const {
    return halfedge(i);
}

// alias for h(0)
SmartHalfedgeHandle SmartEdgeHandle::h0() const {
    return h(0);
}

// alias for h(1)
SmartHalfedgeHandle SmartEdgeHandle::h1() const {
    return h(1);
}

// returns one of the two incident vertices of this edge
// i should be 0 or 1
SmartVertexHandle SmartEdgeHandle::vertex(int i) const {
    return make_smart(mesh_->vertex(static_cast<EdgeHandle>(*this), i), mesh_);
}

// alias for vertex(i)
SmartVertexHandle SmartEdgeHandle::v(int i) const {
    return vertex(i);
}

// alias for v(0)
SmartVertexHandle SmartEdgeHandle::v0() const {
    return v(0);
}

// alias for v(1)
SmartVertexHandle SmartEdgeHandle::v1() const {
    return v(1);
}

/**
 * Implementation of SmartHalfedgeHandle
*/
bool SmartHalfedgeHandle::is_deleted() const {
    return mesh_->is_deleted(static_cast<HalfedgeHandle>(*this));
}

bool SmartHalfedgeHandle::is_boundary() const {
    return mesh_->is_boundary(static_cast<HalfedgeHandle>(*this));
}

// Returns the next halfedge 
SmartHalfedgeHandle SmartHalfedgeHandle::next() const {
    return make_smart(mesh_->next_halfedge(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartHalfedgeHandle SmartHalfedgeHandle::prev() const {
    return make_smart(mesh_->prev_halfedge(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartHalfedgeHandle SmartHalfedgeHandle::opp() const {
    return make_smart(mesh_->opposite(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartVertexHandle SmartHalfedgeHandle::from() const {
    return make_smart(mesh_->from_vertex(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartVertexHandle SmartHalfedgeHandle::to() const {
    return make_smart(mesh_->to_vertex(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartEdgeHandle SmartHalfedgeHandle::edge() const {
    return make_smart(mesh_->edge(static_cast<HalfedgeHandle>(*this)), mesh_);
}

SmartFaceHandle SmartHalfedgeHandle::face() const {
    return make_smart(mesh_->face(static_cast<HalfedgeHandle>(*this)), mesh_);
}


/**
 * Implementation of SmartFaceHandle
*/
bool SmartFaceHandle::is_deleted() const {
    return mesh_->is_deleted(static_cast<FaceHandle>(*this));
}

bool SmartFaceHandle::is_boundary() const {
    return mesh_->is_boundary(static_cast<FaceHandle>(*this));
}

SmartHalfedgeHandle SmartFaceHandle::halfedge() const {
    return make_smart(mesh_->halfedge(static_cast<FaceHandle>(*this)), mesh_);
}

VertexAroundFaceCirculator SmartFaceHandle::vertices() const {
    return VertexAroundFaceCirculator(mesh_, static_cast<FaceHandle>(*this));
}

VertexAroundFaceCWCirculator SmartFaceHandle::vertices_cw() const {
    return VertexAroundFaceCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

VertexAroundFaceCCWCirculator SmartFaceHandle::vertices_ccw() const {
    return VertexAroundFaceCCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

EdgeAroundFaceCirculator SmartFaceHandle::edges() const {
    return EdgeAroundFaceCirculator(mesh_, static_cast<FaceHandle>(*this));
}

EdgeAroundFaceCWCirculator SmartFaceHandle::edges_cw() const {
    return EdgeAroundFaceCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

EdgeAroundFaceCCWCirculator SmartFaceHandle::edges_ccw() const {
    return EdgeAroundFaceCCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

HalfedgeAroundFaceCirculator SmartFaceHandle::haledges() const {
    return HalfedgeAroundFaceCirculator(mesh_, static_cast<FaceHandle>(*this));
}

HalfedgeAroundFaceCWCirculator SmartFaceHandle::halfedges_cw() const {
    return HalfedgeAroundFaceCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

HalfedgeAroundFaceCCWCirculator SmartFaceHandle::halfedges_ccw() const {
    return HalfedgeAroundFaceCCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

FaceAroundFaceCirculator SmartFaceHandle::faces() const {
    return FaceAroundFaceCirculator(mesh_, static_cast<FaceHandle>(*this));
}

FaceAroundFaceCWCirculator SmartFaceHandle::faces_cw() const {
    return FaceAroundFaceCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

FaceAroundFaceCCWCirculator SmartFaceHandle::faces_ccw() const {
    return FaceAroundFaceCCWCirculator(mesh_, static_cast<FaceHandle>(*this));
}

}
}