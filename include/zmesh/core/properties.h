/**
 * @file properties.h
 * @author zone-1614 (you@domain.com)
 * @brief 属性系统的实现
 * 在zmesh中, mesh这一数据结构什么数据都没有.
 * 所有的几何信息(Vertex的位置, 法向, 纹理等等), 拓扑信息(Halfedge连接了哪个Vertex, 与哪个Face相邻)都交给属性系统来存储.
 * 此外, 还可以添加自定义属性. 
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
#include <stdexcept>

#include <zmesh/core/handles.h>

namespace zmesh {
namespace core {

class BaseProperty;
template<typename T>
class Property;
template<typename T>
class PropertyHandle;
class PropertyContainer;

using BasePropertyPtr = BaseProperty*;
template<typename T>
using PropertyPtr = Property<T>*;

//! Property的基类
class BaseProperty {
public:
    explicit BaseProperty(std::string name) : name_(name) { }

    virtual ~BaseProperty() = default;

    /**
     * @brief 修改属性的size
     * 当向Mesh中添加Vertex或者Face的时候需要使用
     * @param n 新的property size大小
     */
    virtual void resize(size_t n) = 0;

    /**
     * @brief 为属性的容器预留空间
     * 具体实现就是调用stl容器的reserve而已
     * @param n 预留的空间大小
     */
    virtual void reserve(size_t n) = 0;

    /**
     * @brief 添加一个空元素
     */
    virtual void push_back() = 0;

    /**
     * @brief 释放内存
     */
    virtual void free_memory() = 0;

    /**
     * @brief deep copy
     * 
     * @return BasePropertyPtr 克隆后的属性指针
     */
    virtual BasePropertyPtr clone() = 0; // deep copy

    /**
     * @brief 获得属性的名字
     * @return const std::string& 属性的名字
     */
    const std::string& name() const {
        return name_;
    }

protected:
    std::string name_; /**< 属性的名字 */
};

template<typename T>
class Property : public BaseProperty {
public:
    using ValueType = T;
    using VectorType = std::vector<T>;
    using reference = typename VectorType::reference;
    using const_reference = typename VectorType::const_reference;

public:
    //! @brief 利用属性名和属性的默认值构造一个属性
    //! @param name 属性名
    //! @param default_value 默认值
    Property(std::string name, T default_value = T())
        : BaseProperty(std::move(name)), default_value_(std::move(default_value)) { }

    // virtual ~Property() {

    // }

    void resize(size_t n) override {
        data_.resize(n);
    }

    void reserve(size_t n) override {
        data_.reserve(n);
    }

    void push_back() override {
        data_.push_back(default_value_);
    }

    void free_memory() override {
        data_.shrink_to_fit();
    }

    BasePropertyPtr clone() override {
        PropertyPtr<T> bp = new Property<T>(name_, default_value_);
        bp->data_ = data_;
        return bp;
    }

    /**
     * @brief 返回vector
     * 这个函数会在mesh的assignment中使用
     * @return VectorType& 
     */
    VectorType& vector() {
        return data_;
    }

    const VectorType& vector() const {
        return data_;
    }

    ValueType& default_value() {
        return default_value_;
    }

    const ValueType& default_value() const {
        return default_value_;
    }

    reference operator[](size_t idx) {
        return data_[idx];
    }

    const_reference operator[](size_t idx) const {
        return data_[idx];
    }

private:
    VectorType data_; //!< 存储属性的容器, 这里是vector
    ValueType default_value_; //!< 属性的默认值
};

/**
 * @brief 属性的Handle
 * 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性
 * @tparam T 属性的具体类型
 */
template<typename T>
class PropertyHandle {
public:
    friend class PropertyContainer;
    using ValueType = typename Property<T>::ValueType;
    using VectorType = typename Property<T>::VectorType;
    using reference = typename Property<T>::reference;
    using const_reference = typename Property<T>::const_reference;

public:
    PropertyHandle(PropertyPtr<T> prop = nullptr) : prop_(prop) { }

    // no need to delete the pointer
    // virtual ~PropertyHandle() {
    //     delete prop_;
    // }

    bool is_valid() const {
        return prop_ != nullptr;
    }

    VectorType& vector() {
        return prop_->vector();
    }

    const VectorType& vector() const {
        return prop_->vector();
    }

    ValueType& default_value() {
        return prop_->default_value();
    }

    const ValueType& default_value() const {
        return prop_->default_value();
    }

    std::string name() {
        return prop_->name();
    }
    
    reference operator[](size_t idx) {
        return (*prop_)[idx];
    }

    const_reference operator[](size_t idx) const {
        return (*prop_)[idx];
    }

private:
    void reset() {
        prop_ = nullptr;
    }

private:
    PropertyPtr<T> prop_;
};

/**
 * @brief 顶点属性的Handle
 * 可以用VertexHandle来访问属性
 * @tparam T 属性的具体类型
 */
template<typename T>
class VertexPropertyHandle : public PropertyHandle<T> {
public: 
    explicit VertexPropertyHandle() = default;
    explicit VertexPropertyHandle(PropertyHandle<T> p) : PropertyHandle<T>(p) { }

    reference operator[](VertexHandle v) {
        return PropertyHandle<T>::operator[](v.idx());
    }

    const_reference operator[](VertexHandle v) const {
        return PropertyHandle<T>::operator[](v.idx());
    }
};

/**
 * @brief 边属性的Handle
 * 可以用EdgeHandle来访问属性
 * @tparam T 属性的具体类型
 */
template<typename T>
class EdgePropertyHandle : public PropertyHandle<T> {
public: 
    explicit EdgePropertyHandle() = default;
    explicit EdgePropertyHandle(PropertyHandle<T> p) : PropertyHandle<T>(p) { }

    reference operator[](EdgeHandle e) {
        return PropertyHandle<T>::operator[](e.idx());
    }

    const_reference operator[](EdgeHandle e) const {
        return PropertyHandle<T>::operator[](e.idx());
    }
};

/**
 * @brief 半边属性的Handle
 * 可以用HalfedgeHandle来访问属性
 * @tparam T 属性的具体类型
 */
template<typename T>
class HalfedgePropertyHandle : public PropertyHandle<T> {
public: 
    explicit HalfedgePropertyHandle() = default;
    explicit HalfedgePropertyHandle(PropertyHandle<T> p) : PropertyHandle<T>(p) { }

    reference operator[](HalfedgeHandle h) {
        return PropertyHandle<T>::operator[](h.idx());
    }

    const_reference operator[](HalfedgeHandle h) const {
        return PropertyHandle<T>::operator[](h.idx());
    }
};

/**
 * @brief 面属性的Handle
 * 可以用FaceHandle来访问属性
 * @tparam T 属性的具体类型
 */
template<typename T>
class FacePropertyHandle : public PropertyHandle<T> {
public: 
    explicit FacePropertyHandle() = default;
    explicit FacePropertyHandle(PropertyHandle<T> p) : PropertyHandle<T>(p) { }

    reference operator[](FaceHandle f) {
        return PropertyHandle<T>::operator[](f.idx());
    }

    const_reference operator[](FaceHandle f) const {
        return PropertyHandle<T>::operator[](f.idx());
    }
};

/**
 * @brief 属性的容器, 可以包含多个容器
 * 提供对属性的添加删除获取等操作
 */
class PropertyContainer {
public:
    PropertyContainer() = default;

    ~PropertyContainer() {
        clear();
    }

    PropertyContainer(const PropertyContainer& rhs) {
        *this = rhs;
    }

    //! deep copy
    PropertyContainer& operator=(const PropertyContainer& rhs) {
        if (this != &rhs) { // avoid self assignment 
            size_ = rhs.size_;
            clear();
            props_.resize(rhs.n_properties());
            for (size_t i = 0; i < props_.size(); i++) {
                props_[i] = rhs.props_[i]->clone();
            }
        }
        return *this;
    }

    //! 返回所有属性的名字
    std::vector<std::string> properties() const {
        std::vector<std::string> names;
        names.reserve(props_.size());
        for (auto& prop : props_) {
            names.push_back(prop->name());
        }
        return names;
    }
    
    bool exists(const std::string& name) const {
        for (auto& prop : props_) {
            if (prop->name() == name) {
                return true;
            }
        }
        return false;
    }

    //! 通过名字和默认值添加一个属性, 如果属性已经存在, 就抛出异常
    template<typename T>
    PropertyHandle<T> add(const std::string& name, const T default_value = T()) {
        // throw an invalid argument exception if a property with [name] is already exists
        for (auto& prop : props_) {
            if (prop->name() == name) {
                throw std::invalid_argument("a property with name " + name + " is already exists.");
            }
        }

        PropertyPtr<T> p = new Property<T>(name, default_value);
        p->resize(size_);
        props_.push_back(p);
        return PropertyHandle<T>(p);
    }

    //! 通过名字查找属性, 如果存在, 就返回该属性的Handle, 如果不存在, 就抛出异常
    template<typename T>
    PropertyHandle<T> get(const std::string& name) const {
        for (auto& prop : props_) {
            if (prop->name() == name) {
                return PropertyHandle<T>(dynamic_cast<PropertyPtr<T>>(prop));
            }
        }

        // does not exist a property with this [name], throw an exception
        throw std::invalid_argument("does not exists a property with name " + name + ".");
    }

    //! 通过名字获取属性, 如果属性不存在, 就用参数给定的名字和默认值添加一个属性, 并返回属性的Handle
    template<typename T>
    PropertyHandle<T> get_or_add(const std::string& name, const T default_value = T()) {
        for (auto& prop : props_) {
            if (prop->name() == name) {
                return PropertyHandle<T>(dynamic_cast<PropertyPtr<T>>(prop));
            }
        }

        return add<T>(name, default_value);
    }

    //! 根据属性的Handle删除一个属性
    template<typename T>
    void remove(PropertyHandle<T>& handle) {
        for (auto it = props_.begin(); it != props_.end(); ++it) {
            if (*it == handle.prop_) {
                props_.erase(it);
                it->reset();
                handle.reset();
                break;
            }
        }
    }

    //! 释放内存
    void free_memory() {
        for (auto& prop : props_) {
            prop->free_memory();
        }
    }

    //! 删除所有属性
    void clear() {
        size_ = 0;
        for (auto& prop : props_) {
            prop = nullptr;
        }
        props_.clear();
    }

    //! 返回这个容器里有多少个属性
    size_t n_properties() const {
        return props_.size();
    }

    //! 返回每个属性的大小(所有属性都是一样大的)
    size_t size() const {
        return size_;
    }

    //! 对所有属性添加一个元素
    void push_back() {
        size_++;
        for (auto& prop : props_) {
            prop->push_back();
        }
    }

    //! 调整所有属性的大小
    void resize(size_t n) {
        size_ = n;
        for (auto& prop : props_) {
            prop->resize(n);
        }
    }

    //! 为属性预留空间
    void reserve(size_t n) {
        for (auto& prop : props_) {
            prop->reserve(n);
        }
    }

private:
    std::vector<BasePropertyPtr> props_; //!< 所有属性的指针
    size_t size_{0}; //!< 每个属性的大小
};

}
}