#pragma once

/**
 * Mesh Kernel provide
 *      1. Functions to get point, set point
 *      2. Low level topological operation
*/

#include <vector>

#include <zmesh/core/property_kernel.h>

namespace zmesh {
namespace core {

class MeshKernel : public PropertyKernel {
private:
    // Mesh Topology Struct
    struct VertexTopology {
        HalfedgeHandle halfedge_;
    };

    struct EdgeTopology {
        HalfedgeHandle halfedges_[2];
    };

    /**
     * No need to store the edge that contain this halfedge,
     * you can get the edge index by >> 1
    */
    struct HalfedgeTopology {
        HalfedgeHandle next_halfedge_;
        HalfedgeHandle prev_halfedge_;
        VertexHandle to_vertex_;
        FaceHandle face_;
    };

    struct FaceTopology {
        HalfedgeHandle halfedge_;
    };

public:
    MeshKernel();

    virtual ~MeshKernel() {
        clear();
    }

    MeshKernel(const MeshKernel& rhs) {
        operator=(rhs);
    }

    // copy all the member
    MeshKernel& operator=(const MeshKernel& rhs);

    // copy all the member except the custom property
    MeshKernel& assign(const MeshKernel& rhs);

    /**
     * Add a new vertex, no need to change vertices_
    */
    VertexHandle new_vertex();

    /**
     * Add an edge and two halfedges without end point.
    */
    HalfedgeHandle new_edge();

    /**
     * Add a new edge and two halfedges with [start] and [end]
    */
    HalfedgeHandle new_edge(VertexHandle start, VertexHandle end);

    /**
     * Add a new face without any incident edges and vertices
    */
    FaceHandle new_face();

public:
    // number of vertices, including the vertices that marked as deleted
    size_t vertices_size() const {
        return vprops_.size();
    }

    // number of edges, including the edges that marked as deleted
    size_t edges_size() const {
        return eprops_.size();
    }

    // number of halfedges, including the halfedges that marked as deleted
    size_t halfedges_size() const {
        return hprops_.size();
    }

    // number of faces, including the faces that marked as deleted
    size_t faces_size() const {
        return fprops_.size();
    }

    // number of vertices, excluding the vertices that marked as deleted
    size_t n_vertices() const {
        return vertices_size() - n_deleted_vertices_;
    }
    
    // number of edges, excluding the edges that marked as deleted
    size_t n_edges() const {
        return edges_size() - n_deleted_edges_;
    }

    // number of halfedges, excluding the halfedges that marked as deleted
    size_t n_halfedges() const {
        return halfedges_size() - n_deleted_edges_ * 2;
    }

    // number of faces, excluding the faces that marked as deleted
    size_t n_faces() const {
        return faces_size() - n_deleted_faces_;
    }

    bool is_empty() const {
        return n_vertices() == 0;
    }

    void free_memory();
    
    virtual void clear();

    bool is_deleted(VertexHandle v) const {
        return v_deleted_bits_[v];
    }

    bool is_deleted(EdgeHandle e) const {
        return e_deleted_bits_[e];
    }

    bool is_deleted(HalfedgeHandle h) const {
        return e_deleted_bits_[edge(h)];
    }

    bool is_deleted(FaceHandle f) const {
        return f_deleted_bits_[f];
    }

    bool is_valid(VertexHandle v) const {
        return v.idx() < vertices_size();
    }

    bool is_valid(EdgeHandle e) const {
        return e.idx() < edges_size();
    }

    bool is_valid(HalfedgeHandle h) const {
        return h.idx() < halfedges_size();
    }

    bool is_valid(FaceHandle f) const {
        return f.idx() < faces_size();
    }

    // --- Point Operation ---
    const Point& point(VertexHandle v) const {
        return vpoints_[v];
    }

    void set_point(VertexHandle v, Point p) {
        vpoints_[v] = p;
    }

    std::vector<Point>& points() {
        return vpoints_.vector();
    }

    // ---  Vertex Connectivity  ---

    // returns an outgoing halfedge of [v]
    HalfedgeHandle halfedge(VertexHandle v) const {
        return vertices_[v].halfedge_;
    }

    // set the outgoing halfedge of [v] to [h]
    void set_halfedge(VertexHandle v, HalfedgeHandle h) {
        vertices_[v].halfedge_ = h;
    }

    HalfedgeHandle outgoing_halfedge(VertexHandle v) const {
        return halfedge(v);
    }

    HalfedgeHandle incoming_halfedge(VertexHandle v) const {
        return opposite(halfedge(v));
    }

    bool is_boundary(VertexHandle v) const {
        auto h = halfedge(v);
        return !(h.is_valid() && face(h).is_valid());
    }

    bool is_isolated(VertexHandle v) const {
        return !halfedge(v).is_valid();
    }

    // --- Edge Connectivity --- 

    // returns a halfedge belong to [e]
    // i should be 0 or 1
    HalfedgeHandle halfedge(EdgeHandle e, int i) const {
        return HalfedgeHandle((e.idx() << 1) + i);
    }

    // returns one of the vertex incident to [e]
    // i should be 0 or 1
    VertexHandle vertex(EdgeHandle e, int i) const {
        return to_vertex(halfedge(e, i));
    }

    bool is_boundary(EdgeHandle e) const {
        auto h0 = halfedge(e, 0);
        auto h1 = halfedge(e, 1);
        return is_boundary(h0) || is_boundary(h1);
    }

    // --- Halfedge Connectivity --- 

    //            h
    // [from] ----------> [to]
    // get the to vertex of [h]
    VertexHandle to_vertex(HalfedgeHandle h) const {
        return halfedges_[h].to_vertex_;
    }

    // get the from vertex of [h]
    VertexHandle from_vertex(HalfedgeHandle h) const {
        auto oh = opposite(h);
        return to_vertex(oh);
    }

    void set_to_vertex(HalfedgeHandle h, VertexHandle v) {
        halfedges_[h].to_vertex_ = v;
    }

    // get the incident face of [h]
    FaceHandle face(HalfedgeHandle h) const {
        return halfedges_[h].face_;
    }

    // get the edge of [h]
    EdgeHandle edge(HalfedgeHandle h) const {
        return EdgeHandle(h.idx() >> 1);
    }

    // returns the oppsite halfedge
    HalfedgeHandle opposite(HalfedgeHandle h) const {
        if (h.idx() & 1) {
            return HalfedgeHandle(h.idx() - 1);
        } else {
            return HalfedgeHandle(h.idx() + 1);
        }
    }

    // get the next halfedge handle of [h]
    HalfedgeHandle next_halfedge(HalfedgeHandle h) const {
        return halfedges_[h].next_halfedge_;
    }

    // [nh] means that next halfedge handle
    void set_next_halfedge(HalfedgeHandle h, HalfedgeHandle nh) {
        halfedges_[h].next_halfedge_ = nh;
        halfedges_[nh].prev_halfedge_ = h;
    }

    // get the previous halfedge handle of [h]
    HalfedgeHandle prev_halfedge(HalfedgeHandle h) const {
        return halfedges_[h].prev_halfedge_;
    }

    // [ph] means that previous halfedge handle
    void set_prev_halfedge(HalfedgeHandle h, HalfedgeHandle ph) {
        halfedges_[h].prev_halfedge_ = ph;
        halfedges_[ph].next_halfedge_ = h;
    }

    // cw means that clockwise
    HalfedgeHandle cw_halfedge(HalfedgeHandle h) const {
        return next_halfedge(opposite(h));
    }

    // ccw means that counterclockwise
    HalfedgeHandle ccw_halfedge(HalfedgeHandle h) const {
        return opposite(prev_halfedge(h));
    }

    bool is_boundary(HalfedgeHandle h) const {
        return !face(h).is_valid();
    }

    // --- Face Connectivity --- 
    // returns a halfedge adjacent to [f]
    HalfedgeHandle halfedge(FaceHandle f) const {
        return faces_[f].halfedge_;
    }

    void set_halfedge(FaceHandle f, HalfedgeHandle h) {
        faces_[f].halfedge_ = h;
    }

    // set the adjacent face of [h] to [f]
    void set_face(HalfedgeHandle h, FaceHandle f) {
        faces_[f].halfedge_ = h;
    }

    bool is_boundary(FaceHandle f) const {
        auto begin = halfedge(f);
        auto curr = next_halfedge(begin);
        while (curr != begin) {
            if (is_boundary(curr)) {
                return true;
            }
            curr = next_halfedge(curr);
        }
        return false;
    }

protected:
    VertexPropertyHandle<Point> vpoints_;

    VertexPropertyHandle<VertexTopology> vertices_;
    EdgePropertyHandle<EdgeTopology> edges_;
    HalfedgePropertyHandle<HalfedgeTopology> halfedges_;
    FacePropertyHandle<FaceTopology> faces_;

    /**
     * Memory management
    */
    bool has_garbage_{false};
    // mark for deleted
    VertexPropertyHandle<bool> v_deleted_bits_;
    EdgePropertyHandle<bool> e_deleted_bits_;
    FacePropertyHandle<bool> f_deleted_bits_;

    // deleted number of Vertex, Edge, Face
    Index n_deleted_vertices_{0};
    Index n_deleted_edges_{0};
    Index n_deleted_faces_{0};

private:
    // helper for property name 
    class PropertyNames {
    public:
        // this feature need c++17
        inline static const std::string vpoints_{"zmesh-vpoints_"};
        inline static const std::string vertices_{"zmesh-vertices_"};
        inline static const std::string edges_{"zmesh-edges_"};
        inline static const std::string halfedges_{"zmesh-halfedges_"};
        inline static const std::string faces_{"zmesh-faces_"};
        inline static const std::string v_deleted_bits_{"zmesh-v_deleted_bits_"};
        inline static const std::string e_deleted_bits_{"zmesh-e_deleted_bits_"};
        inline static const std::string f_deleted_bits_{"zmesh-f_deleted_bits_"};
    };
};

}
}