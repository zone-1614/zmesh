/**
 * @file handles.h
 * @author zone-1614 (you@domain.com)
 * @brief 包括Handle基类和VertexHandle等具体的Handle
 * @version 0.1
 * @date 2023-05-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <vector>
#include <string>
#include <memory>

#include <zmesh/core/types.h>

namespace zmesh {
namespace core {

/**
 * @class Handle
 * @brief Handle基类. Vertex, Halfedge, Edge, Face都通过Handle来操作
 * zmesh中利用handle来访问各种数据. 可以把handle理解为顶点, 半边, 边, 面的下标
 */
class Handle {
public:
    explicit Handle(Index idx = INDEX_MAX) : idx_(idx) { }

    //! 返回Handle的下标
    Index idx() const {
        return idx_;
    }

    //! 将Handle的下标设置为最大值
    void reset() {
        idx_ = INDEX_MAX;
    }

    //! 判断Handle是否有效. 当Handle的idx达到最大时, 无效.
    bool is_valid() const {
        return idx_ != INDEX_MAX;
    }

    //! 通过判断两个Handle的idx来判断是否相同
    bool operator==(const Handle& rhs) const {
        return idx_ == rhs.idx_;
    }

    //! 与operator==相反
    bool operator!=(const Handle& rhs) const {
        return idx_ != rhs.idx_;
    }

    //! 通过两个Handle的idx来比较大小
    bool operator<(const Handle& rhs) const {
        return idx_ < rhs.idx_;
    }

    //! 只会在Iterator中使用, 其他地方不会使用这个函数
    void __increment() { ++idx_; }

    //! 只会在Iterator中使用, 其他地方不会使用这个函数
    void __decrement() { --idx_; }

private:
    Index idx_; //!< Handle的下标
};

class VertexHandle;
class EdgeHandle;
class HalfedgeHandle;
class FaceHandle;
class Mesh;

//! 用来表示Vertex的Handle
class VertexHandle : public Handle {
public:
    VertexHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

//! 用来表示Edge的Handle
class EdgeHandle : public Handle {
public:
    EdgeHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

//! 用来表示Halfedge的Handle
class HalfedgeHandle : public Handle {
public:
    HalfedgeHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

//! 用来表示Face的Handle
class FaceHandle : public Handle {
public:
    FaceHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};


/**
 * Output operators
*/

inline std::ostream& operator<<(std::ostream& os, VertexHandle v) {
    os << 'v' << v.idx();
    return os;
}

inline std::ostream& operator<<(std::ostream& os, EdgeHandle e) {
    os << 'e' << e.idx();
    return os;
} 

inline std::ostream& operator<<(std::ostream& os, HalfedgeHandle h) {
    os << 'h' << h.idx();
    return os;
}

inline std::ostream& operator<<(std::ostream& os, FaceHandle f) {
    os << 'f' << f.idx();
    return os;
} 

}
}