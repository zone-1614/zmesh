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

class BaseProperty {
public:
    explicit BaseProperty(std::string name) : name_(name) { }

    ~BaseProperty() = default;

    virtual void resize(size_t n) = 0;

    virtual void reserve(size_t n) = 0;

    virtual void push_back() = 0;

    virtual void free_memory() = 0;

    virtual BasePropertyPtr clone() = 0; // deep copy

    const std::string& name() const {
        return name_;
    }

protected:
    std::string name_;
};

template<typename T>
class Property : public BaseProperty {
public:
    using ValueType = T;
    using VectorType = std::vector<T>;
    using reference = typename VectorType::reference;
    using const_reference = typename VectorType::const_reference;

public:
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
    VectorType data_;
    ValueType default_value_;
};

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

class PropertyContainer {
public:
    PropertyContainer() = default;

    ~PropertyContainer() {
        clear();
    }

    PropertyContainer(const PropertyContainer& rhs) {
        *this = rhs;
    }

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

    // returns the names of all properties
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

    // add a property with [name] and [default value]
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

    // returns a property handle with [name]
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

    // get a property with [name], if not exists, add a property with [name] and [default value]
    template<typename T>
    PropertyHandle<T> get_or_add(const std::string& name, const T default_value = T()) {
        for (auto& prop : props_) {
            if (prop->name() == name) {
                return PropertyHandle<T>(dynamic_cast<PropertyPtr<T>>(prop));
            }
        }

        return add<T>(name, default_value);
    }

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

    void free_memory() {
        for (auto& prop : props_) {
            prop->free_memory();
        }
    }

    void clear() {
        size_ = 0;
        for (auto& prop : props_) {
            prop = nullptr;
        }
        props_.clear();
    }

    // returns the number of properties
    size_t n_properties() const {
        return props_.size();
    }

    // returns the size of property
    size_t size() const {
        return size_;
    }

    void push_back() {
        size_++;
        for (auto& prop : props_) {
            prop->push_back();
        }
    }

    void resize(size_t n) {
        size_ = n;
        for (auto& prop : props_) {
            prop->resize(n);
        }
    }

    void reserve(size_t n) {
        for (auto& prop : props_) {
            prop->reserve(n);
        }
    }

private:
    std::vector<BasePropertyPtr> props_;
    size_t size_{0}; // size of every prop
};

}
}