#pragma once

#include <zmesh/core/handles.h>
#include <zmesh/core/smart_handles.h>

namespace zmesh {
namespace core {

template<typename HandleType>
class BaseIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using reference = const HandleType&;
    using pointer = const HandleType*;

    BaseIterator() = default;
    
    BaseIterator(HandleType handle) : handle_(handle) { }

    reference operator*() const {
        return handle_;
    }

    pointer operator->() const {
        return &handle_;
    }

    bool operator==(const BaseIterator& rhs) const {
        return handle_ == rhs.handle_;
    }

    bool operator!=(const BaseIterator& rhs) const {
        return !operator==(rhs);
    }

    BaseIterator& operator++() {
        handle_.__increment();
        return *this;
    }

    BaseIterator operator++(int) {
        auto tmp = *this;
        handle_.__increment();
        return tmp;
    }

    BaseIterator& operator--() {
        handle_.__decrement();
        return *this;
    }

    BaseIterator operator--(int) {
        auto tmp = *this;
        handle_.__decrement();
        reutrn tmp;
    }

protected: 
    HandleType handle_;
};

using VertexIterator = BaseIterator<SmartVertexHandle>;
using EdgeIterator = BaseIterator<SmartEdgeHandle>;
using HalfedgeIterator = BaseIterator<SmartHalfedgeHandle>;
using FaceIterator = BaseIterator<SmartFaceHandle>;

using ConstVertexIterator = BaseIterator<SmartVertexHandle>;
using ConstEdgeIterator = BaseIterator<SmartEdgeHandle>;
using ConstHalfedgeIterator = BaseIterator<SmartHalfedgeHandle>;
using ConstFaceIterator = BaseIterator<SmartFaceHandle>;

template<typename IteratorType>
class BaseRange {
public:
    BaseRange(IteratorType begin, IteratorType end) : begin_(begin), end_(end) { }

    IteratorType begin() const {
        return begin_;
    }

    IteratorType end() const {
        return end_;
    }

private:
    IteratorType begin_;
    IteratorType end_;
};

using VertexRange = BaseRange<VertexIterator>;
using EdgeRange = BaseRange<EdgeIterator>;
using HalfedgeRange = BaseRange<HalfedgeIterator>;
using FaceRange = BaseRange<FaceIterator>;

using ConstVertexRange = BaseRange<ConstVertexIterator>;
using ConstEdgeRange = BaseRange<ConstEdgeIterator>;
using ConstHalfedgeRange = BaseRange<ConstHalfedgeIterator>;
using ConstFaceRange = BaseRange<ConstFaceIterator>;

}
}