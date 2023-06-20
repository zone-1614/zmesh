#include <zmesh/core/mesh.h>

namespace zmesh {
namespace core {

HalfedgeHandle Mesh::find_halfedge(VertexHandle start, VertexHandle end) const {
    // assert(is_valid(start) && is_valid(end));

    const HalfedgeHandle first = halfedge(start); // first outgoing halfedge
    HalfedgeHandle curr = first;
    
    if (!first.is_valid()) return { };

    do {
        if (to_vertex(curr) == end) {
            return curr;
        }
        curr = cw_halfedge(curr);
    } while (curr != first);

    // can not found that halfedge, return a invalid halfedge handle
    return { };
}

EdgeHandle Mesh::find_edge(VertexHandle v0, VertexHandle v1) const {
    const auto h = find_halfedge(v0, v1);

    // if h is in valid, return a invalid edge handle
    if (h.is_valid()) {
        return edge(h);
    } else {
        return { };
    }
}

void Mesh::adjust_outgoing_halfedge(VertexHandle v) {
    const HalfedgeHandle first = halfedge(v);  // first outgoing halfedge
    HalfedgeHandle curr = first;

    if (!first.is_valid()) return;

    do {
        if (is_boundary(curr)) {
            set_halfedge(v, curr);
            return;
        }
        curr = cw_halfedge(curr);
    } while (curr != first);
}

SmartVertexHandle Mesh::add_vertex(const Point& p) {
    auto v = new_vertex();
    vpoints_[v] = p;
    return make_smart(v, this);
}

SmartVertexHandle Mesh::add_vertex(float x, float y, float z) {
    auto v = new_vertex();
    Point p{x, y, z};
    vpoints_[v] = p;
    return make_smart(v, this);
}

SmartFaceHandle Mesh::add_face(const std::vector<VertexHandle>& vertices) {
    // vertices.size() should greater than 2
    const size_t n = vertices.size();
    assert(n > 2);

    std::vector<HalfedgeHandle> _halfedges(n); // halfedges that connect v[i] and v[i+1]  (auto mod by 2)
    std::vector<bool> _is_new_halfedge(n); // the edge is new ?
    std::vector<bool> _need_adjust(n, false);
    std::vector< std::pair<HalfedgeHandle, HalfedgeHandle> > _next_cache;
    _next_cache.reserve(6 * n);

    HalfedgeHandle 
        inner_prev, inner_next,
        outer_prev, outer_next,
        boundary_prev, boundary_next,
        patch_start, patch_end;

    // for each halfedge: v[i] --> v[i+1],  (auto mod by n)
    for (size_t i = 0, j = 1; i < n; i++, j++, j %= n) {
        // if v[i] is boundary, the new face will make the mesh to a non-manifold mesh
        if (!is_boundary(vertices[i])) {
            throw std::invalid_argument("the operation will make the mesh to a non-manifold mesh");
        }

        _halfedges[i] = find_halfedge(vertices[i], vertices[j]);
        _is_new_halfedge[i] = !_halfedges[i].is_valid();

        // if the halfedge is already exist and is not a boundary halfedge, 
        // the new face will make the mesh a non-manifold mesh.
        if (!_is_new_halfedge[i] && !is_boundary(_halfedges[i])) {
            throw std::invalid_argument("the operation will make the mesh to a non-manifold mesh");
        }
    }

    // Changing the topology
    // I don't know how to write comment, these code is so ugly.....   :(
    // TODO 下面这一个循环没读懂, 直接抄 OpenMesh 了
    for (size_t i = 0, j = 1; i < n; i++, j++, j %= n) {
        if (_is_new_halfedge[i] || _is_new_halfedge[j]) continue;

        inner_prev = _halfedges[i];
        inner_next = _halfedges[j];
        if (next_halfedge(inner_prev) == inner_next) continue;

        outer_next = opposite(inner_prev);
        outer_prev = opposite(inner_next);
        // find the next boundary halfedge, just like a IncomingHalfedgeAroundVertexCirculator
        boundary_prev = outer_prev;
        do {
            boundary_prev = opposite(next_halfedge(boundary_prev));
        } while (!is_boundary(boundary_prev));
        boundary_next = next_halfedge(boundary_prev);

        assert(is_boundary(boundary_prev));
        assert(is_boundary(boundary_next));

        if (boundary_next == inner_next) {
            throw std::invalid_argument("Error in Mesh::add_face");
        }

        // other halfedges' handles
        patch_start = next_halfedge(inner_prev);
        patch_end = prev_halfedge(inner_next);

        // relink
        _next_cache.emplace_back(boundary_prev, patch_start);
        _next_cache.emplace_back(patch_end, boundary_next);
        _next_cache.emplace_back(inner_prev, inner_next);

    }

    // create missing edges
    for (size_t i = 0, j = 1; i < n; i++, j++, j %= n) {
        if (_is_new_halfedge[i]) {
            _halfedges[i] = new_edge(vertices[i], vertices[j]);
        }
    }

    // create the face
    FaceHandle f = new_face();
    set_halfedge(f, _halfedges.back());

    // setup halfedges
    // TODO 这个循环也没读懂, 抄OpenMesh
    VertexHandle v;
    for (size_t i = 0, j = 1; i < n; i++, j++, j %= n) {
        v = vertices[j];
        inner_prev = _halfedges[i];
        inner_next = _halfedges[j];

        size_t id = 0;
        if (_is_new_halfedge[i]) id |= 1;
        if (_is_new_halfedge[j]) id |= 2;

        if (id) {
            outer_prev = opposite(inner_next);
            outer_next = opposite(inner_prev);

            // set outer links
            switch (id) {
                case 1: // prev is new, next is old
                    boundary_prev = prev_halfedge(inner_next);
                    _next_cache.emplace_back(boundary_prev, outer_next);
                    set_halfedge(v, outer_next);
                    break;

                case 2: // next is new, prev is old
                    boundary_next = next_halfedge(inner_prev);
                    _next_cache.emplace_back(outer_prev, boundary_next);
                    set_halfedge(v, boundary_next);
                    break;

                case 3: // both are new
                    if (!halfedge(v).is_valid()) {
                        set_halfedge(v, outer_next);
                        _next_cache.emplace_back(outer_prev, outer_next);
                    } else {
                        boundary_next = halfedge(v);
                        boundary_prev = prev_halfedge(boundary_next);
                        _next_cache.emplace_back(boundary_prev, outer_next);
                        _next_cache.emplace_back(outer_prev, boundary_next);
                    }
                    break;
            }

            // set inner link
            _next_cache.emplace_back(inner_prev, inner_next);
        } else {
            _need_adjust[j] = (halfedge(v) == inner_next);
        }
    }

    for (auto [h0, h1] : _next_cache) {
        set_next_halfedge(h0, h1);
    }

    for (size_t i = 0; i < n; i++) {
        if (_need_adjust[i]) {
            adjust_outgoing_halfedge(vertices[i]);
        }
    }

    return make_smart(f, this);
}

SmartFaceHandle Mesh::add_triangle(VertexHandle v0, VertexHandle v1, VertexHandle v2) {
    std::vector<VertexHandle> vertices(3);
    vertices[0] = v0;
    vertices[1] = v1;
    vertices[2] = v2;
    return add_face(vertices);
}

SmartFaceHandle Mesh::add_triangle(const std::array<VertexHandle, 3>& vertices) {
    std::vector<VertexHandle> v(vertices.begin(), vertices.end());
    return add_face(v);
}

SmartFaceHandle Mesh::add_quad(VertexHandle v0, VertexHandle v1, VertexHandle v2, VertexHandle v3) {
    std::vector<VertexHandle> vertices(4);
    vertices[0] = v0;
    vertices[1] = v1;
    vertices[2] = v2;
    vertices[3] = v3;
    return add_face(vertices);
}

SmartFaceHandle Mesh::add_quad(const std::array<VertexHandle, 4>& vertices) {
    std::vector<VertexHandle> v(vertices.begin(), vertices.end());
    return add_face(v);
}

int Mesh::valence(VertexHandle v) const {
    int val = 0;
    for (auto vv : vertices(v)) {
        val++;
    }
    return val;
}

int Mesh::valence(FaceHandle f) const {
    int val = 0;
    for (auto vf : vertices(f)) {
        val++;
    }
    return val;
}

bool Mesh::is_triangle_mesh() const {
    for (auto f : faces())
        if (valence(f) != 3)
            return false;

    return true;
}

bool Mesh::is_quad_mesh() const {
    for (auto f : faces())
        if (valence(f) != 4)
            return false;

    return true;
}

}
}