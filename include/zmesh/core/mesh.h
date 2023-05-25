#pragma once

/**
 * Mesh provide
 *      1. High level topological operations
 *      2. Iterators
 *      3. Circulators
*/

#include <memory>

#include <zmesh/core/mesh_kernel.h>
#include <zmesh/core/iterators.h>
#include <zmesh/core/circulators.h>
#include <zmesh/core/smart_handles.h>

namespace zmesh {
namespace core {

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

    // find the halfedge from [start] to [end]. If the halfedge is not exist, return a invalid halfedge handle
    HalfedgeHandle find_halfedge(VertexHandle start, VertexHandle end) const;

    // find the edge by [v0], [v1]. If the edge is not exist, return a invalid edge handle
    EdgeHandle find_edge(VertexHandle v0, VertexHandle v1) const;

    // make sure that halfedge(v) is a boundary halfedge,
    // when v is a boundary vertex
    void Mesh::adjust_outgoing_halfedge(VertexHandle v);

    // add a vertex with position [p] and return its handle
    SmartVertexHandle add_vertex(const Point& p);

    // add a vertex with position [x, y, z] and return its handle
    SmartVertexHandle add_vertex(double x, double y, double z);

    // add a face by connect the vertices one by one, and the handle of new face
    SmartFaceHandle add_face(const std::vector<VertexHandle>& vertices);

    // some convenient functions for adding face
    SmartFaceHandle add_triangle(VertexHandle v0, VertexHandle v1, VertexHandle v2);

    SmartFaceHandle add_triangle(const std::array<VertexHandle, 3>& vertices);

    SmartFaceHandle add_quad(VertexHandle v0, VertexHandle v1, VertexHandle v2, VertexHandle v3);

    SmartFaceHandle add_quad(const std::array<VertexHandle, 4>& vertices);

    int valence(VertexHandle v) const; // number of 1 ring

    int valence(FaceHandle f) const; // number of vertices that incident with this face

    bool Mesh::is_triangle_mesh() const;

    bool Mesh::is_quad_mesh() const;



    bool is_empty() const {
        return n_vertices() == 0;
    }

    // remove all vertices, edges, faces
    // TODO 这个函数分到哪个类型?
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

    VertexRange vertices() const {
        return VertexRange(vertices_begin(), vertices_end());
    }

    EdgeIterator edges_begin() const {
        return EdgeIterator(make_smart(EdgeHandle(0), this));
    }

    EdgeIterator edges_end() const {
        return EdgeIterator(make_smart(EdgeHandle(n_edges()), this));
    }

    EdgeRange edges() const {
        return EdgeRange(edges_begin(), edges_end());
    }

    HalfedgeIterator halfedges_begin() const {
        return HalfedgeIterator(make_smart(HalfedgeHandle(0), this));
    }

    HalfedgeIterator halfedges_end() const {
        return HalfedgeIterator(make_smart(HalfedgeHandle(n_halfedges()), this));
    }

    HalfedgeRange halfedges() const {
        return HalfedgeRange(halfedges_begin(), halfedges_end());
    }

    FaceIterator faces_begin() const {
        return FaceIterator(make_smart(FaceHandle(0), this));
    }

    FaceIterator faces_end() const {
        return FaceIterator(make_smart(FaceHandle(n_faces()), this));
    }

    FaceRange faces() const {
        return FaceRange(faces_begin(), faces_end());
    }

    
    /**
     * Circulators
    */

    /**
     * returns the VertexAroundVertexCirculator
     * @param vertex the center vertex
    */
    VertexAroundVertexCirculator vertices(VertexHandle vertex) const {
        return VertexAroundVertexCirculator(this, vertex);
    }

    /**
     * returns the EdgeAroundVertexCirculator
     * @param vertex the center vertex
    */
    EdgeAroundVertexCirculator edges(VertexHandle vertex) const {
        return EdgeAroundVertexCirculator(this, vertex);
    }

    /**
     * returns the HalfedgeAroundVertexCirculator
     * @param vertex the center vertex
    */
    HalfedgeAroundVertexCirculator halfedges(VertexHandle vertex) const {
        return HalfedgeAroundVertexCirculator(this, vertex);
    }

    /**
     * returns the FaceAroundVertexCirculator
     * @param vertex the center vertex
    */
    FaceAroundVertexCirculator faces(VertexHandle vertex) const {
        return FaceAroundVertexCirculator(this, vertex);
    }

    /**
     * returns the VertexAroundFaceCirculator
     * @param face the center face
    */
    VertexAroundFaceCirculator vertices(FaceHandle face) const {
        return VertexAroundFaceCirculator(this, face);
    }

    /**
     * returns the EdgeAroundFaceCirculator
     * @param face the center face
    */
    EdgeAroundFaceCirculator edges(FaceHandle face) const {
        return EdgeAroundFaceCirculator(this, face);
    }

    /**
     * returns the HalfedgeAroundFaceCirculator
     * @param face the center face
    */
    HalfedgeAroundFaceCirculator halfedges(FaceHandle face) const {
        return HalfedgeAroundFaceCirculator(this, face);
    }

    /**
     * returns the FaceAroundFaceCirculator
     * @param face the center face
    */
    FaceAroundFaceCirculator faces(FaceHandle face) const {
        return FaceAroundFaceCirculator(this, face);
    }

private:
};

}
}