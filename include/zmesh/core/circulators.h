#pragma once

#include <zmesh/core/handles.h>
#include <zmesh/core/mesh_kernel.h>

namespace zmesh {
namespace core {

/**
 * There are many types of circulators, such as
 *      Vertex Around Vertex
 *      Outgoing Halfedge Around Vertex
 *      Face Around Vertex
 *      Vertex Around Face
 *      Halfedge Around Face
*/

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

    operator bool() const {
        return halfedge_.is_valid();
    }

    HalfedgeHandle halfedge() const {
        return halfedge_;
    }

    /**
     * helper for c++11 range-based for
    */
    BaseCirculator& begin() {
        is_active_ = !halfedge_.is_valid();
        return *this;
    }

    BaseCirculator& end() {
        is_active_ = true;
        return *this;
    }

private:
    const MeshKernel* mesh_kernel_;
    HalfedgeHandle start_;
    HalfedgeHandle halfedge_;
    bool is_active_{true}; // helper for c++11 range-based for
};

// -----------------------------------------
// -----  Vertex-Centered Circulators  -----
// -----------------------------------------

struct VertexCenterTrait {
    static void increment(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->cw_halfedge(halfedge_);
    }

    static void decrement(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->ccw_halfedge(halfedge_);
    }
};

/**
 * Vertex Around Vertex Circulator Trait. 
 * useful to enumerate 1-ring
*/
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
using VertexAroundVertexCWCirculator = BaseCirculator<VertexAroundVertexTrait, true>;
using VertexAroundVertexCCWCirculator = BaseCirculator<VertexAroundVertexTrait, false>;
using VertexAroundVertexCirculator = VertexAroundVertexCWCirculator;
using CW_VV = VertexAroundVertexCWCirculator;
using CCW_VV = VertexAroundVertexCCWCirculator;
using VV = CW_VV;

/**
 * Edge Around Vertex Circulator Trait.
*/
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
using EdgeAroundVertexCWCirculator = BaseCirculator<EdgeAroundVertexTrait, true>;
using EdgeAroundVertexCCWCirculator = BaseCirculator<EdgeAroundVertexTrait, false>;
using EdgeAroundVertexCirculator = EdgeAroundVertexCWCirculator;
using CW_EV = EdgeAroundVertexCWCirculator;
using CCW_EV = EdgeAroundVertexCCWCirculator;
using EV = CW_EV;

/**
 * Outgoing Halfedges Around Vertex Trait.
*/
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
using OutgoingHalfedgeAroundVertexCWCirculator = BaseCirculator<OutgoingHalfedgeAroundVertexTrait, true>;
using OutgoingHalfedgeAroundVertexCCWCirculator = BaseCirculator<OutgoingHalfedgeAroundVertexTrait, false>;
using OutgoingHalfedgeAroundVertexCirculator = OutgoingHalfedgeAroundVertexCWCirculator;
using CW_OHV = OutgoingHalfedgeAroundVertexCWCirculator;
using CCW_OHV = OutgoingHalfedgeAroundVertexCCWCirculator;
using OHV = CW_OHV;

/**
 * Incoming Halfedges Around Vertex Trait.
*/
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
using IncomingHalfedgeAroundVertexCWCirculator = BaseCirculator<IncomingHalfedgeAroundVertexTrait, true>;
using IncomingHalfedgeAroundVertexCCWCirculator = BaseCirculator<IncomingHalfedgeAroundVertexTrait, false>;
using IncomingHalfedgeAroundVertexCirculator = IncomingHalfedgeAroundVertexCWCirculator;
using CW_IHV = IncomingHalfedgeAroundVertexCWCirculator;
using CCW_IHV = IncomingHalfedgeAroundVertexCCWCirculator;
using IHV = CW_IHV;

/**
 * Outgoing Halfedge Around Vertex Circulator is recommended, so there is another alias.
*/
using HalfedgeAroundVertexCirculator = OutgoingHalfedgeAroundVertexCirculator;
using HV = OHV;

/**
 * Face Around Vertex Circulator Trait.
*/
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
using FaceAroundVertexCWCirculator = BaseCirculator<FaceAroundVertexTrait, true>;
using FaceAroundVertexCCWCirculator = BaseCirculator<FaceAroundVertexTrait, false>;
using FaceAroundVertexCirculator = FaceAroundVertexCWCirculator;
using CW_FV = FaceAroundVertexCWCirculator;
using CCW_FV = FaceAroundVertexCCWCirculator;
using FV = CW_FV;


// -----------------------------------------
// -----  Face-Centered Circulators  -----
// -----------------------------------------

struct FaceCenterTrait {
    static void increment(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->next_halfedge(halfedge_);
    }

    static void decrement(const MeshKernel* mesh_kernel_, HalfedgeHandle& halfedge_) {
        halfedge_ = mesh_kernel_->prev_halfedge(halfedge_);
    }
};

/**
 * Vertex Around Face Circulator Trait.
*/
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
using VertexAroundFaceCWCirculator = BaseCirculator<VertexAroundFaceTrait, true>;
using VertexAroundFaceCCWCirculator = BaseCirculator<VertexAroundFaceTrait, false>;
using VertexAroundFaceCirculator = VertexAroundFaceCWCirculator;
using CW_VF = VertexAroundFaceCWCirculator;
using CCW_VF = VertexAroundFaceCCWCirculator;
using VF = CW_VF;

/**
 * Edge Around Face Circulator Trait.
*/
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
using EdgeAroundFaceCWCirculator = BaseCirculator<EdgeAroundFaceTrait, true>;
using EdgeAroundFaceCCWCirculator = BaseCirculator<EdgeAroundFaceTrait, false>;
using EdgeAroundFaceCirculator = EdgeAroundFaceCWCirculator;
using CW_EF = EdgeAroundFaceCWCirculator;
using CCW_EF = EdgeAroundFaceCCWCirculator;
using EF = CW_EF;

/**
 * Halfedge Around Face Circulator Trait.
*/
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
using HalfedgeAroundFaceCWCirculator = BaseCirculator<HalfedgeAroundFaceTrait, true>;
using HalfedgeAroundFaceCCWCirculator = BaseCirculator<HalfedgeAroundFaceTrait, false>;
using HalfedgeAroundFaceCirculator = HalfedgeAroundFaceCWCirculator;
using CW_HF = HalfedgeAroundFaceCWCirculator;
using CCW_HF = HalfedgeAroundFaceCCWCirculator;
using HF = CW_HF;

/**
 * Face Around Face Circulator Trait.
*/
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
using FaceAroundFaceCWCirculator = BaseCirculator<FaceAroundFaceTrait, true>;
using FaceAroundFaceCCWCirculator = BaseCirculator<FaceAroundFaceTrait, false>;
using FaceAroundFaceCirculator = FaceAroundFaceCWCirculator;
using CW_FF = FaceAroundFaceCWCirculator;
using CCW_FF = FaceAroundFaceCCWCirculator;
using FF = CW_FF;

}
}