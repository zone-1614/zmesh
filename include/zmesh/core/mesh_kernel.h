/**
 * @file mesh_kernel.h
 * @author zone-1614 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */


/*
一些名词解释
半边的两个顶点 to, from.

outgoing halfedge
incoming halfedge 
例子:
    v0 ---h0--->
h0是v0的outgoing halfedge
    v1 <---h1---
h1是v1的incoming halfedge

opposite halfedge: 反向半边

cw: 顺时针(clockwise)
ccw: 逆时针(counterclockwise)
*/

#pragma once

#include <vector>

#include <zmesh/core/property_kernel.h>

namespace zmesh {
namespace core {

/**
 * @class MeshKernel
 * @brief 实现了较低级别的拓扑操作和常见的网格操作
 * 低级别的拓扑操作不安全, 不建议用, 一般用Mesh中的较高级的操作
 */
class MeshKernel : public PropertyKernel {
private:
    // Mesh Topology Struct
    // 半边数据结构的特点就是大多数拓扑关系用半边来存储
    //! @class VertexTopology
    //! @brief 顶点拓扑, 存储了一条属于该顶点的outgoing halfedge
    //! 如果该顶点是isolated的, 则这个半边是invalid的. 如果该顶点是边界点, 则这个半边也是边界的
    struct VertexTopology {
        HalfedgeHandle halfedge_; //<! 属于该顶点的半边. 
    };

    //! @class EdgeTopology
    //! @brief 边拓扑, 存储了属于该边的两个半边
    struct EdgeTopology {
        HalfedgeHandle halfedges_[2]; //<! 属于该边的两个半边
    };

    //! @class HalfedgeTopology
    //! @brief 半边拓扑
    //! 不用存储半边对应的边, 因为半边下标左移一位就是对应边的下标.
    struct HalfedgeTopology {
        HalfedgeHandle next_halfedge_; //!< 下一条半边
        HalfedgeHandle prev_halfedge_; //!< 上一条半边
        VertexHandle to_vertex_; //!< 半边指向的顶点
        FaceHandle face_; //!< 半边对应的面
    };

    //! @class FaceTopology
    //! @brief 面拓扑, 存储了属于该面的一条半边
    struct FaceTopology {
        HalfedgeHandle halfedge_; //!< 属于该面的一条半边
    };

public:
    MeshKernel();

    virtual ~MeshKernel() {
        clear();
    }

    MeshKernel(const MeshKernel& rhs) {
        operator=(rhs);
    }

    //! copy, 包括自定义属性
    MeshKernel& operator=(const MeshKernel& rhs);

    //! copy, 不包括自定义属性
    MeshKernel& assign(const MeshKernel& rhs);

    //! 添加新的顶点
    VertexHandle new_vertex();

    //! 添加新的边
    HalfedgeHandle new_edge();

    //! 添加新的边, 两个端点由参数给定
    HalfedgeHandle new_edge(VertexHandle start, VertexHandle end);

    //! 添加新的面, 不给定任何相邻的边和点
    FaceHandle new_face();

public:
    //! 顶点的数目, 包括被标记为删除的顶点
    size_t vertices_size() const {
        return vprops_.size();
    }

    //! 边的数目, 包括被标记为删除的边
    size_t edges_size() const {
        return eprops_.size();
    }

    //! 半边的数目, 包括被标记为删除的半边
    size_t halfedges_size() const {
        return hprops_.size();
    }

    //! 面的数目, 包括被标记为删除的半边
    size_t faces_size() const {
        return fprops_.size();
    }

    //! 顶点的数目, 不包括被标记为删除的顶点
    size_t n_vertices() const {
        return vertices_size() - n_deleted_vertices_;
    }
    
    //! 顶点的数目, 不包括被标记为删除的边
    size_t n_edges() const {
        return edges_size() - n_deleted_edges_;
    }

    //! 顶点的数目, 不包括被标记为删除的半边
    size_t n_halfedges() const {
        return halfedges_size() - n_deleted_edges_ * 2;
    }

    //! 顶点的数目, 不包括被标记为删除的面
    size_t n_faces() const {
        return faces_size() - n_deleted_faces_;
    }

    //! 判断网格是否为空(有没有顶点)
    bool is_empty() const {
        return n_vertices() == 0;
    }

    //! 释放内存
    void free_memory();
    
    //! 清除所有数据
    virtual void clear();

    //! 顶点是否被删除
    bool is_deleted(VertexHandle v) const {
        return v_deleted_bits_[v];
    }

    //! 边是否被删除
    bool is_deleted(EdgeHandle e) const {
        return e_deleted_bits_[e];
    }

    //! 半边是否被删除
    bool is_deleted(HalfedgeHandle h) const {
        return e_deleted_bits_[edge(h)];
    }

    //! 面是否被删除
    bool is_deleted(FaceHandle f) const {
        return f_deleted_bits_[f];
    }

    //! 顶点是否有效
    bool is_valid(VertexHandle v) const {
        return v.idx() < vertices_size();
    }

    //! 边是否有效
    bool is_valid(EdgeHandle e) const {
        return e.idx() < edges_size();
    }

    //! 半边是否有效
    bool is_valid(HalfedgeHandle h) const {
        return h.idx() < halfedges_size();
    }

    //! 面是否有效
    bool is_valid(FaceHandle f) const {
        return f.idx() < faces_size();
    }

    // --- Point Operation ---
    //! 获得顶点对应的三维坐标
    const Point& point(VertexHandle v) const {
        return vpoints_[v];
    }

    //! 获得顶点对应的三维坐标
    Point& point(VertexHandle v) {
        return vpoints_[v];
    }

    //! 设置顶点对应的三维坐标
    void set_point(VertexHandle v, Point p) {
        vpoints_[v] = p;
    }

    //! 返回所有顶点的三维坐标
    std::vector<Point>& points() {
        return vpoints_.vector();
    }

    // ---  Vertex Connectivity  ---

    //! 返回顶点v的一条outgoing halfedge
    HalfedgeHandle halfedge(VertexHandle v) const {
        return vertices_[v].halfedge_;
    }

    //! 设置顶点v的outgoing halfedge
    void set_halfedge(VertexHandle v, HalfedgeHandle h) {
        vertices_[v].halfedge_ = h;
    }

    //! 返回顶点v的一条outgoing halfedge
    HalfedgeHandle outgoing_halfedge(VertexHandle v) const {
        return halfedge(v);
    }

    //! 返回顶点v的一条incoming halfedge
    HalfedgeHandle incoming_halfedge(VertexHandle v) const {
        return opposite(halfedge(v));
    }

    //! 判断顶点是不是边界点
    bool is_boundary(VertexHandle v) const {
        auto h = halfedge(v);
        return !(h.is_valid() && face(h).is_valid());
    }

    // isolated是孤立的意思, 也就是没有任何其他顶点和它相连
    //! 判断顶点是不是孤立点
    bool is_isolated(VertexHandle v) const {
        return !halfedge(v).is_valid();
    }

    // --- Edge Connectivity --- 

    //! 返回边e的半边, i必须是0或1
    HalfedgeHandle halfedge(EdgeHandle e, int i) const {
        return HalfedgeHandle((e.idx() << 1) + i);
    }

    //! 返回边e的顶点, i必须是0或1
    VertexHandle vertex(EdgeHandle e, int i) const {
        return to_vertex(halfedge(e, i));
    }

    //! 判断边是不是边界
    bool is_boundary(EdgeHandle e) const {
        auto h0 = halfedge(e, 0);
        auto h1 = halfedge(e, 1);
        return is_boundary(h0) || is_boundary(h1);
    }

    // --- Halfedge Connectivity --- 

    //! 返回半边的to顶点
    VertexHandle to_vertex(HalfedgeHandle h) const {
        return halfedges_[h].to_vertex_;
    }

    //! 返回半边的from顶点
    VertexHandle from_vertex(HalfedgeHandle h) const {
        auto oh = opposite(h);
        return to_vertex(oh);
    }

    //! 设置半边的to顶点
    void set_to_vertex(HalfedgeHandle h, VertexHandle v) {
        halfedges_[h].to_vertex_ = v;
    }

    //! 返回与半边h相接的一个面
    FaceHandle face(HalfedgeHandle h) const {
        return halfedges_[h].face_;
    }

    //! 返回与半边h相关的一条边
    EdgeHandle edge(HalfedgeHandle h) const {
        return EdgeHandle(h.idx() >> 1);
    }

    //! 返回半边h的反向半边
    HalfedgeHandle opposite(HalfedgeHandle h) const {
        if (h.idx() & 1) {
            return HalfedgeHandle(h.idx() - 1);
        } else {
            return HalfedgeHandle(h.idx() + 1);
        }
    }

    //! 返回h的下一条半边
    HalfedgeHandle next_halfedge(HalfedgeHandle h) const {
        return halfedges_[h].next_halfedge_;
    }

    //! 设置h的下一条半边
    void set_next_halfedge(HalfedgeHandle h, HalfedgeHandle nh) {
        halfedges_[h].next_halfedge_ = nh;
        halfedges_[nh].prev_halfedge_ = h;
    }

    //! 返回h的上一条半边
    HalfedgeHandle prev_halfedge(HalfedgeHandle h) const {
        return halfedges_[h].prev_halfedge_;
    }

    //! 设置h的上一条半边
    void set_prev_halfedge(HalfedgeHandle h, HalfedgeHandle ph) {
        halfedges_[h].prev_halfedge_ = ph;
        halfedges_[ph].next_halfedge_ = h;
    }

    // cw means that clockwise
    //! 返回h按顺时针旋转的下一条半边
    HalfedgeHandle cw_halfedge(HalfedgeHandle h) const {
        return next_halfedge(opposite(h));
    }

    // ccw means that counterclockwise
    //! 返回h按逆时针旋转的下一条半边
    HalfedgeHandle ccw_halfedge(HalfedgeHandle h) const {
        return opposite(prev_halfedge(h));
    }

    //! 判断半边是不是边界
    bool is_boundary(HalfedgeHandle h) const {
        return !face(h).is_valid();
    }

    // --- Face Connectivity --- 
    //! 返回与f相接的一条半边
    HalfedgeHandle halfedge(FaceHandle f) const {
        return faces_[f].halfedge_;
    }

    //! 设置f相接的半边
    void set_halfedge(FaceHandle f, HalfedgeHandle h) {
        faces_[f].halfedge_ = h;
    }

    //! 设置半边相接的面
    void set_face(HalfedgeHandle h, FaceHandle f) {
        faces_[f].halfedge_ = h;
    }

    //! 判断面是不是边界
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
    VertexPropertyHandle<Point> vpoints_; //<! 网格的三维点属性, 也就是几何信息

    // 下面这几个就是拓扑信息
    VertexPropertyHandle<VertexTopology> vertices_; 
    EdgePropertyHandle<EdgeTopology> edges_;
    HalfedgePropertyHandle<HalfedgeTopology> halfedges_;
    FacePropertyHandle<FaceTopology> faces_;

    // memory management
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