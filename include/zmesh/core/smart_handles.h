/**
 * @file smart_handles.h
 * @author zone-1614 (you@domain.com)
 * @brief SmartHandle 可以简化用户的操作
 * 用户并不需要了解SmartHandle就可以享受它带来的方便
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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

//! @class SmartVertexHandle
//! @brief Smart handle implementation
class SmartVertexHandle : public VertexHandle {
public:
    explicit SmartVertexHandle(Index idx = INDEX_MAX, const MeshKernel* mesh = nullptr)
        : VertexHandle(idx), mesh_(mesh) { }

    //! 返回所持有的MeshKernel指针
    const MeshKernel* mesh() const {
        return mesh_;
    }

    /**
     * Topology
    */

    //! 是否被标记为删除
    bool is_deleted() const;

    //! 是否是边界点
    bool is_boundary() const;

    //! 返回定点对应的三维坐标
    const Point& point() const;

    // SmartHandle只访问数据, 操作数据相关的函数只能用Mesh本身

    //! 返回一条outgoing halfedge
    SmartHalfedgeHandle halfedge() const;

    //! 与 halfedge() 相同
    SmartHalfedgeHandle out() const;

    //! 返回一条incoming halfedge
    SmartHalfedgeHandle in() const;

    /**
     * Circulators, 默认是顺时针
    */

    //! 遍历这个顶点的1-ring
    VertexAroundVertexCirculator vertices() const; // 默认是顺时针版本, 以下不再注释

    //! 遍历这个顶点的1-ring, 顺时针版本
    VertexAroundVertexCWCirculator vertices_cw() const;

    //! 遍历这个顶点的1-ring, 逆时针版本
    VertexAroundVertexCCWCirculator vertices_ccw() const;

    //! 遍历这个顶点相接的边
    EdgeAroundVertexCirculator edges() const;

    //! 遍历这个顶点相接的边, 顺时针版本
    EdgeAroundVertexCWCirculator edges_cw() const;

    //! 遍历这个顶点相接的边, 逆时针版本
    EdgeAroundVertexCCWCirculator edges_ccw() const;

    //! 遍历这个顶点相接的半边
    HalfedgeAroundVertexCirculator halfedges() const;

    //! 遍历这个顶点相接的outgoing半边
    OutgoingHalfedgeAroundVertexCirculator outgoing_halfedges() const;

    //! 遍历这个顶点相接的outgoing半边, 顺时针版本
    OutgoingHalfedgeAroundVertexCWCirculator outgoing_halfedges_cw() const;

    //! 遍历这个顶点相接的outgoing半边, 逆时针版本
    OutgoingHalfedgeAroundVertexCCWCirculator outgoing_halfedges_ccw() const;

    //! 遍历这个顶点相接的incoming半边
    IncomingHalfedgeAroundVertexCirculator incoming_halfedges() const;

    //! 遍历这个顶点相接的incoming半边, 顺时针版本
    IncomingHalfedgeAroundVertexCWCirculator incoming_halfedges_cw() const;

    //! 遍历这个顶点相接的incoming半边, 逆时针版本
    IncomingHalfedgeAroundVertexCCWCirculator incoming_halfedges_ccw() const;

    //! 遍历这个顶点相接的面
    FaceAroundVertexCirculator faces() const;

    //! 遍历这个顶点相接的面, 顺时针版本
    FaceAroundVertexCWCirculator faces_cw() const;

    //! 遍历这个顶点相接的面, 逆时针版本
    FaceAroundVertexCCWCirculator faces_ccw() const;

    //! valence就是这个顶点相接的边的个数
    unsigned int valence() const;

private:
    const MeshKernel* mesh_;
};

//! @class SmartEdgeHandle
//! @brief Smart handle implementation
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

    //! 是否被标记为删除
    bool is_deleted() const;

    //! 是否是边界点
    bool is_boundary() const;

    //! 返回该边对应的两条半边之一
    //! @param i 必须是0或1
    SmartHalfedgeHandle halfedge(int i) const;

    //! 等价于halfedge(i)
    //! @param i 必须是0或1
    SmartHalfedgeHandle h(int i) const;

    //! 等价于h(0)
    SmartHalfedgeHandle h0() const;

    //! 等价于h(1)
    SmartHalfedgeHandle h1() const;

    //! 返回该边对应的两个顶点之一
    //! @param i 必须是0或1
    SmartVertexHandle vertex(int i) const;

    //! 等价于vertex(i)
    SmartVertexHandle v(int i) const;

    //! 等价于v(0)
    SmartVertexHandle v0() const;

    //! 等价于v(1)
    SmartVertexHandle v1() const;

private:
    const MeshKernel* mesh_;
};

//! @class SmartHalfedgeHandle
//! @brief Smart handle implementation
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

    //! 是否被标记为删除
    bool is_deleted() const;

    //! 是否是边界点
    bool is_boundary() const;

    //! 返回next半边
    SmartHalfedgeHandle next() const;

    //! 返回prev半边
    SmartHalfedgeHandle prev() const;

    //! 返回反方向的半边
    SmartHalfedgeHandle opp() const;

    //! 返回from顶点
    SmartVertexHandle from() const;

    //! 返回to顶点
    SmartVertexHandle to() const;

    //! 返回对应的edge
    SmartEdgeHandle edge() const;

    //! 返回相接的面
    SmartFaceHandle face() const;

private:
    const MeshKernel* mesh_;
};

//! @class SmartFaceHandle
//! @brief Smart handle implementation
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

    //! 是否被标记为删除
    bool is_deleted() const;

    //! 是否是边界点
    bool is_boundary() const ;

    //! 返回相邻的一条半边
    SmartHalfedgeHandle halfedge() const;

    /**
     * Circulators
    */

    //! 遍历这个面周围的顶点
    VertexAroundFaceCirculator vertices() const;

    //! 遍历这个面周围的顶点, 顺时针版本
    VertexAroundFaceCWCirculator vertices_cw() const;

    //! 遍历这个面周围的顶点, 逆时针版本
    VertexAroundFaceCCWCirculator vertices_ccw() const;

    //! 遍历这个面周围的边
    EdgeAroundFaceCirculator edges() const;

    //! 遍历这个面周围的边, 顺时针版本
    EdgeAroundFaceCWCirculator edges_cw() const;

    //! 遍历这个面周围的边, 逆时针版本
    EdgeAroundFaceCCWCirculator edges_ccw() const;

    //! 遍历这个面周围的半边
    HalfedgeAroundFaceCirculator haledges() const;

    //! 遍历这个面周围的半边, 顺时针版本
    HalfedgeAroundFaceCWCirculator halfedges_cw() const;

    //! 遍历这个面周围的半边, 逆时针版本
    HalfedgeAroundFaceCCWCirculator halfedges_ccw() const;

    //! 遍历这个面周围的面
    FaceAroundFaceCirculator faces() const;

    //! 遍历这个面周围的面, 顺时针版本
    FaceAroundFaceCWCirculator faces_cw() const;

    //! 遍历这个面周围的面, 逆时针版本
    FaceAroundFaceCCWCirculator faces_ccw() const;

    //! valence就是这个面周围的顶点个数
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