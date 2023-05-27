/**
 * @file iterators.h
 * @author zone-1614 (you@domain.com)
 * @brief 迭代器
 * 用来遍历Mesh中的所有顶点, 所有边, 所有半边, 所有面.
 * @version 0.1
 * @date 2023-05-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <zmesh/core/handles.h>
#include <zmesh/core/smart_handles.h>

namespace zmesh {
namespace core {

//! @class BaseIterator
//! @brief 所有迭代器的基类
//! 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标
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
    HandleType handle_; //!< 迭代器所拥有的Handle
};

// 具体的迭代器类
using VertexIterator = BaseIterator<SmartVertexHandle>;
using EdgeIterator = BaseIterator<SmartEdgeHandle>;
using HalfedgeIterator = BaseIterator<SmartHalfedgeHandle>;
using FaceIterator = BaseIterator<SmartFaceHandle>;

// Const Iterator 没有用到, 可以忽略这部分
using ConstVertexIterator = BaseIterator<SmartVertexHandle>;
using ConstEdgeIterator = BaseIterator<SmartEdgeHandle>;
using ConstHalfedgeIterator = BaseIterator<SmartHalfedgeHandle>;
using ConstFaceIterator = BaseIterator<SmartFaceHandle>;

//! @class BaseRange
//! @brief 通过Range可以方便使用c++11的 range-based for 语句
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

// Const Range 没有用到, 可以忽略这部分
using ConstVertexRange = BaseRange<ConstVertexIterator>;
using ConstEdgeRange = BaseRange<ConstEdgeIterator>;
using ConstHalfedgeRange = BaseRange<ConstHalfedgeIterator>;
using ConstFaceRange = BaseRange<ConstFaceIterator>;

}
}