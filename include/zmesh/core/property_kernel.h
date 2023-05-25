#pragma once

#include <zmesh/core/properties.h>

/**
 * Property Kernel provide
 *      1. Property management.
*/

namespace zmesh {
namespace core {
class PropertyKernel {
public:
    PropertyKernel() = default;
    
    ~PropertyKernel() {
        vprops_.clear();
        eprops_.clear();
        hprops_.clear();
        fprops_.clear();
    }

    // --- Vertex Property ---

    bool exist_vertex_property(const std::string& name) const {
        return vprops_.exists(name);
    }

    // add a vertex property with [name] and [default value]
    template<typename T>
    VertexPropertyHandle<T> add_vertex_property(const std::string& name, const T defalut_value = T()) {
        return VertexPropertyHandle<T>(vprops_.add<T>(name, defalut_value));
    }

    // get a vertex proeprty with [name], if it already exists, throwing an invalid_argument exception
    template<typename T>
    VertexPropertyHandle<T> get_vertex_property(const std::string& name) const {
        return VertexPropertyHandle<T>(vprops_.get<T>(name));
    }

    // get a vertex property with [name], if not exists, adding a new vertex property with this [name] and [default value]
    template<typename T>
    VertexPropertyHandle<T> get_or_add_vertex_property(const std::string& name, const T default_value = T()) {
        return VertexPropertyHandle<T>(vprops_.get_or_add<T>(name, default_value));
    }

    // remove the vertex property by a [vertex property handle]
    template<typename T>
    void remove_vertex_property(VertexPropertyHandle<T>& handle) {
        vprops_.remove(handle);
    }

    // --- Edge Property ---

    bool exist_edge_property(const std::string& name) const {
        eprops_.exists(name);
    }

    // add an edge property with [name] and [default value]
    template<typename T>
    EdgePropertyHandle<T> add_edge_property(const std::string& name, const T default_value = T()) {
        return EdgePropertyHandle<T>(eprops_.add<T>(name, default_value));
    }

    // get an edge property with [name], if it already exists, throwing an invalid_argument exception
    template<typename T>
    EdgePropertyHandle<T> get_edge_property(const std::string& name) const {
        return EdgePropertyHandle<T>(eprops_.get<T>(name));
    }

    // get an edge property with [name], if not exists, adding a new edge property with this [name] and [default value]
    template<typename T>
    EdgePropertyHandle<T> get_or_add_edge_property(const std::string& name, const T default_value = T()) {
        return EdgePropertyHandle<T>(eprops_.get_or_add<T>(name, default_value));
    }

    // --- Halfedge Property ---

    bool exist_halfedge_property(const std::string& name) const {
        return hprops_.exists(name);
    }

    // add a halfedge property with [name] and [default value]
    template<typename T>
    HalfedgePropertyHandle<T> add_halfedge_property(const std::string& name, const T default_value = T()) {
        return HalfedgePropertyHandle<T>(hprops_.add<T>(name, default_value));
    }

    // get a halfedge property with [name], if it already exists, throwing an invalid_argument exception
    template<typename T>
    HalfedgePropertyHandle<T> get_halfedge_property(const std::string& name) const {
        return HalfedgePropertyHandle<T>(hprops_.get<T>(name));
    }

    // get a halfedge property with [name], if not exists, adding a new halfedge property with this [name] and [default value]
    template<typename T>
    HalfedgePropertyHandle<T> get_or_add_halfedge_property(const std::string& name, const T default_value = T()) {
        return HalfedgePropertyHandle<T>(hprops_.get_or_add<T>(name, default_value));
    }

    // --- Face Property ---

    bool exist_face_property(const std::string& name) const {
        return fprops_.exists(name);
    }

    // add a face property with [name] and [default value]
    template<typename T>
    FacePropertyHandle<T> add_face_property(const std::string& name, const T default_value = T()) {
        return FacePropertyHandle<T>(fprops_.add<T>(name, default_value));
    }

    // get a face property with [name], if it already exists, throwing an invalid_argument exception
    template<typename T>
    FacePropertyHandle<T> get_face_property(const std::string& name) const {
        return FacePropertyHandle<T>(fprops_.get<T>(name));
    }

    // get a face property with [name], if not exists, adding a new face property with this [name] and [default value]
    template<typename T>
    FacePropertyHandle<T> get_or_add_face_property(const std::string& name, const T default_value = T()) {
        return FacePropertyHandle<T>(fprops_.get_or_add<T>(name, default_value));
    }

protected:
    // containers of custom property
    PropertyContainer vprops_;
    PropertyContainer eprops_;
    PropertyContainer hprops_;
    PropertyContainer fprops_;
};

}
}