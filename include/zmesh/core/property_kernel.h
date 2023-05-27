/**
 * @file property_kernel.h
 * @author zone-1614 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <zmesh/core/properties.h>

namespace zmesh {
namespace core {

/**
 * @class PropertyKernel
 * @brief 实现了属性管理
 */
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

    //! 根据属性名字判断顶点属性是否存在
    bool exist_vertex_property(const std::string& name) const {
        return vprops_.exists(name);
    }

    //! 添加顶点属性, 其名字和默认值由参数给定
    template<typename T>
    VertexPropertyHandle<T> add_vertex_property(const std::string& name, const T defalut_value = T()) {
        return VertexPropertyHandle<T>(vprops_.add<T>(name, defalut_value));
    }

    //! 根据参数给定的名字获得顶点属性的Handle
    template<typename T>
    VertexPropertyHandle<T> get_vertex_property(const std::string& name) const {
        return VertexPropertyHandle<T>(vprops_.get<T>(name));
    }

    //! 根据给定的名字获取顶点属性, 如果不存在, 就添加一个新的顶点属性, 它的名字和默认值由参数给定
    template<typename T>
    VertexPropertyHandle<T> get_or_add_vertex_property(const std::string& name, const T default_value = T()) {
        return VertexPropertyHandle<T>(vprops_.get_or_add<T>(name, default_value));
    }

    //! 根据顶点属性的Handle删除顶点属性
    template<typename T>
    void remove_vertex_property(VertexPropertyHandle<T>& handle) {
        vprops_.remove(handle);
    }

    // --- Edge Property ---

    //! 根据属性名字判断边属性是否存在
    bool exist_edge_property(const std::string& name) const {
        eprops_.exists(name);
    }

    //! 添加边属性, 其名字和默认值由参数给定
    template<typename T>
    EdgePropertyHandle<T> add_edge_property(const std::string& name, const T default_value = T()) {
        return EdgePropertyHandle<T>(eprops_.add<T>(name, default_value));
    }

    //! 根据参数给定的名字获得边属性的Handle
    template<typename T>
    EdgePropertyHandle<T> get_edge_property(const std::string& name) const {
        return EdgePropertyHandle<T>(eprops_.get<T>(name));
    }

    //! 根据给定的名字获取边属性, 如果不存在, 就添加一个新的边属性, 它的名字和默认值由参数给定
    template<typename T>
    EdgePropertyHandle<T> get_or_add_edge_property(const std::string& name, const T default_value = T()) {
        return EdgePropertyHandle<T>(eprops_.get_or_add<T>(name, default_value));
    }

    // --- Halfedge Property ---

    //! 根据属性名字判断半边属性是否存在
    bool exist_halfedge_property(const std::string& name) const {
        return hprops_.exists(name);
    }

    //! 添加半边属性, 其名字和默认值由参数给定
    template<typename T>
    HalfedgePropertyHandle<T> add_halfedge_property(const std::string& name, const T default_value = T()) {
        return HalfedgePropertyHandle<T>(hprops_.add<T>(name, default_value));
    }

    //! 根据参数给定的名字获得半边属性的Handle
    template<typename T>
    HalfedgePropertyHandle<T> get_halfedge_property(const std::string& name) const {
        return HalfedgePropertyHandle<T>(hprops_.get<T>(name));
    }

    //! 根据给定的名字获取半边属性, 如果不存在, 就添加一个新的半边属性, 它的名字和默认值由参数给定
    template<typename T>
    HalfedgePropertyHandle<T> get_or_add_halfedge_property(const std::string& name, const T default_value = T()) {
        return HalfedgePropertyHandle<T>(hprops_.get_or_add<T>(name, default_value));
    }

    // --- Face Property ---

    //! 根据属性名字判断面属性是否存在
    bool exist_face_property(const std::string& name) const {
        return fprops_.exists(name);
    }

    //! 添加面属性, 其名字和默认值由参数给定
    template<typename T>
    FacePropertyHandle<T> add_face_property(const std::string& name, const T default_value = T()) {
        return FacePropertyHandle<T>(fprops_.add<T>(name, default_value));
    }

    //! 根据参数给定的名字获得面属性的Handle
    template<typename T>
    FacePropertyHandle<T> get_face_property(const std::string& name) const {
        return FacePropertyHandle<T>(fprops_.get<T>(name));
    }

    //! 根据给定的名字获取面属性, 如果不存在, 就添加一个新的面属性, 它的名字和默认值由参数给定
    template<typename T>
    FacePropertyHandle<T> get_or_add_face_property(const std::string& name, const T default_value = T()) {
        return FacePropertyHandle<T>(fprops_.get_or_add<T>(name, default_value));
    }

protected:
    // containers of custom property
    PropertyContainer vprops_; //<! 顶点属性容器
    PropertyContainer eprops_; //<! 边属性容器
    PropertyContainer hprops_; //<! 半边属性容器
    PropertyContainer fprops_; //<! 面属性容器
};

}
}