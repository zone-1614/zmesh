#pragma once
#include <vector>
#include <string>
#include <memory>

#include <zmesh/core/types.h>

namespace zmesh {
namespace core {
    
class Handle {
public:
    explicit Handle(Index idx = INDEX_MAX) : idx_(idx) { }

    Index idx() const {
        return idx_;
    }

    void reset() {
        idx_ = INDEX_MAX;
    }

    bool is_valid() const {
        return idx_ != INDEX_MAX;
    }

    bool operator==(const Handle& rhs) const {
        return idx_ == rhs.idx_;
    }

    bool operator!=(const Handle& rhs) const {
        return idx_ != rhs.idx_;
    }

    bool operator<(const Handle& rhs) const {
        return idx_ < rhs.idx_;
    }

    // this is to be used only by the iterators
    void __increment() { ++idx_; }
    void __decrement() { --idx_; }

private:
    Index idx_;
};

class VertexHandle;
class EdgeHandle;
class HalfedgeHandle;
class FaceHandle;
class Mesh;

class VertexHandle : public Handle {
public:
    VertexHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

class EdgeHandle : public Handle {
public:
    EdgeHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

class HalfedgeHandle : public Handle {
public:
    HalfedgeHandle(Index idx = INDEX_MAX) : Handle(idx) { }
};

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