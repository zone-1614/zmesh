/**
 * @file circulators.h
 * @author zone-1614 (you@domain.com)
 * @brief Circulator是一种特殊的迭代器
 * 不知道Circulator这个词怎么翻译, 所以保留了英语  <p>
 * Circulator 首先要有一个中心和遍历元素的类型, 通过Circulator可以遍历这个中心附近的元素. <p>
 * 比如遍历一个顶点相邻的顶点
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <zmesh/core/handles.h>
#include <zmesh/core/mesh_kernel.h>

namespace zmesh {
namespace core {

//! @class BaseCirculator
//! @brief Circulator的基类
//! 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 
//! 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能
template<typename Trait, bool CW = true>
class BaseCirculator {
public:
    using CenterEntityHandle = typename Trait::CenterEntityHandle;
    using ValueHandle = typename Trait::ValueHandle;
    using SmartValueHandle = decltype(make_smart(std::declval<ValueHandle>(), std::declval<MeshKernel>()));

    BaseCirculator() = default;

    BaseCirculator(const MeshKernel* mesh, CenterEntityHandle center) 
        : mesh_kernel_(mesh), start_(mesh->halfedge(center)), halfedge_(mesh->halfedge(center)) { }

    SmartValueHandle operator*() const {
        ValueHandle handle = Trait::to_handle(mesh_kernel_, halfedge_);
        return make_smart(handle, mesh_kernel_);
    }

    BaseCirculator& operator++() {
        if constexpr(CW) {
            Trait::increment(mesh_kernel_, halfedge_);
        } else {
            Trait::decrement(mesh_kernel_, halfedge_);
        }
        is_active_ = true;
        return *this;
    }

    BaseCirculator& operator++(int) {
        auto tmp = *this;
        ++(*this);
        return tmp;
    }

    BaseCirculator& operator--() {
        if constexpr(CW) {
            Trait::decrement(mesh_kernel_, halfedge_);
        } else {
            Trait::increment(mesh_kernel_, halfedge_);
        }
        return *this;
    }

    BaseCirculator& operator--(int) {
        auto tmp = *this;
        --(*this);
        return tmp;
    }

    BaseCirculator& operator=(const BaseCirculator& rhs) {
        mesh_kernel_ = rhs.mesh_kernel_;
        start_ = rhs.start_;
        halfedge_ = rhs.halfedge_;
        return *this;
    }

    bool operator==(const BaseCirculator& rhs) const {
        return (is_active_) && (mesh_kernel_ == rhs.mesh_kernel_ && start_ == rhs.start_ && halfedge_ == rhs.halfedge_);
    }

    bool operator!=(const BaseCirculator& rhs) const {
        return !operator==(rhs);
    }

    //! 这个迭代器是否有效
    operator bool() const {
        return halfedge_.is_valid();
    }

    HalfedgeHandle halfedge() const {
        return halfedge_;
    }

    //! 用于c++11的 range-based for
    BaseCirculator& begin() {
        is_active_ = !halfedge_.is_valid();
        return *this;
    }

    //! 用于c++11的 range-based for
    BaseCirculator& end() {
        is_active_ = true;
        return *this;
    }

private:
    const MeshKernel* mesh_kernel_; //! 通过MeshKernel才能使用一些拓扑操作, 比如顺时针旋转, 获取handle
    HalfedgeHandle start_; //! 记录开始的handle用来判断什么时候结束遍历
    HalfedgeHandle halfedge_; //! 半边数据结构存储了最多的拓扑信息, 所以Circulator中只存一个半边就行了
    bool is_active_{true}; //! 辅助变量, 用它来保证只会绕一圈
};

// -----------------------------------------
// -----  Vertex-Centered Circulators  -----
// -----------------------------------------

//! @class VertexCenterTrait
//! @brief 以Vertex做中心的Circulator Trait
struct VertexCenterTrait {
    static void increment(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->cw_halfedge(halfedge_);
    }

    static void decrement(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->ccw_halfedge(halfedge_);
    }
};


//! @class VertexAroundVertexTrait
//! @brief 中心类型是顶点, 遍历元素类型也是顶点的Circulator Trait
//! 常用来遍历顶点的1-ring
struct VertexAroundVertexTrait : public VertexCenterTrait {
    using CenterEntityHandle = VertexHandle;
    using ValueHandle = VertexHandle;
    
    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->to_vertex(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Vertex Around Vertex Circulator.
 * CW_VV(or VV) and CCW_VV in short.
*/
//! 中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 顺时针
using VertexAroundVertexCWCirculator = BaseCirculator<VertexAroundVertexTrait, true>;
//! 中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 逆时针
using VertexAroundVertexCCWCirculator = BaseCirculator<VertexAroundVertexTrait, false>;
//! 与VertexAroundVertexCWCirculator相同
using VertexAroundVertexCirculator = VertexAroundVertexCWCirculator;

using CW_VV = VertexAroundVertexCWCirculator;
using CCW_VV = VertexAroundVertexCCWCirculator;
using VV = CW_VV;


//! @class EdgeAroundVertexTrait
//! @brief 中心类型是顶点, 遍历元素类型是边的Circulator Trait
struct EdgeAroundVertexTrait : public VertexCenterTrait {
    using CenterEntityHandle = VertexHandle;
    using ValueHandle = EdgeHandle;

    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->edge(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Edge Around Vertex Circulator.
 * CW_EV(or EV) and CCW_EV in short.
*/
//! 中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 顺时针
using EdgeAroundVertexCWCirculator = BaseCirculator<EdgeAroundVertexTrait, true>;
//! 中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 逆时针
using EdgeAroundVertexCCWCirculator = BaseCirculator<EdgeAroundVertexTrait, false>;
//! 与EdgeAroundVertexCWCirculator相同
using EdgeAroundVertexCirculator = EdgeAroundVertexCWCirculator;

using CW_EV = EdgeAroundVertexCWCirculator;
using CCW_EV = EdgeAroundVertexCCWCirculator;
using EV = CW_EV;


//! @class OutgoingHalfedgeAroundVertexTrait
//! @brief 中心类型是顶点, 遍历元素类型是outgoing halfedge的Circulator Trait
struct OutgoingHalfedgeAroundVertexTrait : public VertexCenterTrait {
    using CenterEntityHandle = VertexHandle;
    using ValueHandle = HalfedgeHandle;

    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return halfedge_;
    }

};

/**
 * ClockWise and Counter ClockWise Outgoing Halfedge Around Vertex Circulator.
 * CW_OHV(or OHV) and CCW_OHV in short.
*/
//! 中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针
using OutgoingHalfedgeAroundVertexCWCirculator = BaseCirculator<OutgoingHalfedgeAroundVertexTrait, true>;
//! 中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针
using OutgoingHalfedgeAroundVertexCCWCirculator = BaseCirculator<OutgoingHalfedgeAroundVertexTrait, false>;
//! 与OutgoingHalfedgeAroundVertexCWCirculator相同
using OutgoingHalfedgeAroundVertexCirculator = OutgoingHalfedgeAroundVertexCWCirculator;

using CW_OHV = OutgoingHalfedgeAroundVertexCWCirculator;
using CCW_OHV = OutgoingHalfedgeAroundVertexCCWCirculator;
using OHV = CW_OHV;


//! @class IncomingHalfedgeAroundVertexTrait
//! @brief 中心类型是顶点, 遍历元素类型是incoming halfedge的Circulator Trait
struct IncomingHalfedgeAroundVertexTrait : public VertexCenterTrait {
    using CenterEntityHandle = VertexHandle;
    using ValueHandle = HalfedgeHandle;

    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->opposite(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Incoming Halfedge Around Vertex Circulator.
 * CW_IHV(or IHV) and CCW_IHV in short.
*/
//! 中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针
using IncomingHalfedgeAroundVertexCWCirculator = BaseCirculator<IncomingHalfedgeAroundVertexTrait, true>;
//! 中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针
using IncomingHalfedgeAroundVertexCCWCirculator = BaseCirculator<IncomingHalfedgeAroundVertexTrait, false>;
//! 与IncomingHalfedgeAroundVertexCWCirculator相同
using IncomingHalfedgeAroundVertexCirculator = IncomingHalfedgeAroundVertexCWCirculator;

using CW_IHV = IncomingHalfedgeAroundVertexCWCirculator;
using CCW_IHV = IncomingHalfedgeAroundVertexCCWCirculator;
using IHV = CW_IHV;

/**
 * Outgoing Halfedge Around Vertex Circulator is recommended, so there is another alias.
*/
//! 中心类型: 顶点, 遍历元素类型: outgoing半边, 遍历方法: 顺时针
using HalfedgeAroundVertexCirculator = OutgoingHalfedgeAroundVertexCirculator;
using HV = OHV;


//! @class FaceAroundVertexTrait
//! @brief 中心类型是顶点, 遍历元素类型是面的Circulator Trait
struct FaceAroundVertexTrait : public VertexCenterTrait {
    using CenterEntityHandle = VertexHandle;
    using ValueHandle = FaceHandle;

    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->face(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Face Around Vertex Circulator.
 * CW_FV(or FV) and CCW_FV in short.
*/
//! 中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 顺时针
using FaceAroundVertexCWCirculator = BaseCirculator<FaceAroundVertexTrait, true>;
//! 中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 逆时针
using FaceAroundVertexCCWCirculator = BaseCirculator<FaceAroundVertexTrait, false>;
//! 与FaceAroundVertexCWCirculator相同
using FaceAroundVertexCirculator = FaceAroundVertexCWCirculator;

using CW_FV = FaceAroundVertexCWCirculator;
using CCW_FV = FaceAroundVertexCCWCirculator;
using FV = CW_FV;


// -----------------------------------------
// -----  Face-Centered Circulators  -----
// -----------------------------------------

//! @class FaceCenterTrait
//! @brief 以Face做中心的Circulator Trait
struct FaceCenterTrait {
    static void increment(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->next_halfedge(halfedge_);
    }

    static void decrement(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->prev_halfedge(halfedge_);
    }
};


//! @class VertexAroundFaceTrait
//! @brief 中心类型是面, 遍历元素类型是顶点的Circulator Trait
struct VertexAroundFaceTrait : public FaceCenterTrait {
    using CenterEntityHandle = FaceHandle;
    using ValueHandle = VertexHandle;
    // using SmartHandle = decltype(make_smart(std::declval<ValueHandle>(), std::declval<Mesh>()));

    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        // return make_smart(mesh_kernel_->to_vertex(halfedge_), mesh_kernel_);
        return mesh_kernel_->to_vertex(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Vertex Around Face Circulator.
 * CW_VF(or VF) and CCW_VF in short.
*/
//! 中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 顺时针
using VertexAroundFaceCWCirculator = BaseCirculator<VertexAroundFaceTrait, true>;
//! 中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 逆时针
using VertexAroundFaceCCWCirculator = BaseCirculator<VertexAroundFaceTrait, false>;
//! 与VertexAroundFaceCWCirculator相同
using VertexAroundFaceCirculator = VertexAroundFaceCWCirculator;
using CW_VF = VertexAroundFaceCWCirculator;
using CCW_VF = VertexAroundFaceCCWCirculator;
using VF = CW_VF;


//! @class EdgeAroundFaceTrait
//! @brief 中心类型是面, 遍历元素类型是边的Circulator Trait
struct EdgeAroundFaceTrait : public FaceCenterTrait {
    using CenterEntityHandle = FaceHandle;
    using ValueHandle = EdgeHandle;
    
    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->edge(halfedge_);
    }

};

/**
 * ClockWise and Counter ClockWise Edge Around Face Circulator.
 * CW_EF(or EF) and CCW_EF in short.
*/
//! 中心类型: 面, 遍历元素类型: 边, 遍历方法: 顺时针
using EdgeAroundFaceCWCirculator = BaseCirculator<EdgeAroundFaceTrait, true>;
//! 中心类型: 面, 遍历元素类型: 边, 遍历方法: 逆时针
using EdgeAroundFaceCCWCirculator = BaseCirculator<EdgeAroundFaceTrait, false>;
//! 与EdgeAroundFaceCWCirculator相同
using EdgeAroundFaceCirculator = EdgeAroundFaceCWCirculator;
using CW_EF = EdgeAroundFaceCWCirculator;
using CCW_EF = EdgeAroundFaceCCWCirculator;
using EF = CW_EF;


//! @class HalfedgeAroundFaceTrait
//! @brief 中心类型是面, 遍历元素类型是半边的Circulator Trait
struct HalfedgeAroundFaceTrait : public FaceCenterTrait {
    using CenterEntityHandle = FaceHandle;
    using ValueHandle = HalfedgeHandle;
    
    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return halfedge_;
    }

};

/**
 * ClockWise and Counter ClockWise Halfedge Around Face Circulator.
 * CW_HF(or HF) and CCW_HF in short.
*/
//! 中心类型: 面, 遍历元素类型: 半边, 遍历方法: 顺时针
using HalfedgeAroundFaceCWCirculator = BaseCirculator<HalfedgeAroundFaceTrait, true>;
//! 中心类型: 面, 遍历元素类型: 半边, 遍历方法: 逆时针
using HalfedgeAroundFaceCCWCirculator = BaseCirculator<HalfedgeAroundFaceTrait, false>;
//! 与HalfedgeAroundFaceCWCirculator相同
using HalfedgeAroundFaceCirculator = HalfedgeAroundFaceCWCirculator;
using CW_HF = HalfedgeAroundFaceCWCirculator;
using CCW_HF = HalfedgeAroundFaceCCWCirculator;
using HF = CW_HF;


//! @class FaceAroundFaceTrait
//! @brief 中心类型是面, 遍历元素类型也是面的Circulator Trait
struct FaceAroundFaceTrait : public FaceCenterTrait {
    using CenterEntityHandle = FaceHandle;
    using ValueHandle = FaceHandle;
    
    static ValueHandle to_handle(const MeshKernel* mesh_kernel_, const HalfedgeHandle& halfedge_) {
        return mesh_kernel_->face(mesh_kernel_->opposite(halfedge_));
    }

};

/**
 * ClockWise and Counter ClockWise Face Around Face Circulator.
 * CW_FF(or FF) and CCW_FF in short.
*/
//! 中心类型: 面, 遍历元素类型: 面, 遍历方法: 顺时针
using FaceAroundFaceCWCirculator = BaseCirculator<FaceAroundFaceTrait, true>;
//! 中心类型: 面, 遍历元素类型: 面, 遍历方法: 逆时针
using FaceAroundFaceCCWCirculator = BaseCirculator<FaceAroundFaceTrait, false>;
//! 与FaceAroundFaceCWCirculator相同
using FaceAroundFaceCirculator = FaceAroundFaceCWCirculator;
using CW_FF = FaceAroundFaceCWCirculator;
using CCW_FF = FaceAroundFaceCCWCirculator;
using FF = CW_FF;

}
}