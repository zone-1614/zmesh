---
title: zmesh::core::Property

---

# zmesh::core::Property



 [More...](#detailed-description)


`#include <properties.h>`

Inherits from [zmesh::core::BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md)

## Public Types

|                | Name           |
| -------------- | -------------- |
| using T | **[ValueType](Classes/classzmesh_1_1core_1_1_property.md#using-valuetype)**  |
| using std::vector< T > | **[VectorType](Classes/classzmesh_1_1core_1_1_property.md#using-vectortype)**  |
| using typename VectorType::reference | **[reference](Classes/classzmesh_1_1core_1_1_property.md#using-reference)**  |
| using typename VectorType::const_reference | **[const_reference](Classes/classzmesh_1_1core_1_1_property.md#using-const-reference)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Property](Classes/classzmesh_1_1core_1_1_property.md#function-property)**(std::string name, T default_value =T())<br>利用属性名和属性的默认值构造一个属性  |
| virtual void | **[resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize)**(size_t n) override<br>修改属性的size 当向Mesh中添加Vertex或者Face的时候需要使用  |
| virtual void | **[reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve)**(size_t n) override<br>为属性的容器预留空间 具体实现就是调用stl容器的reserve而已  |
| virtual void | **[push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back)**() override<br>添加一个空元素  |
| virtual void | **[free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory)**() override<br>释放内存  |
| virtual [BasePropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-basepropertyptr) | **[clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone)**() override<br>deep copy  |
| [VectorType](Classes/classzmesh_1_1core_1_1_property.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property.md#function-vector)**()<br>返回vector 这个函数会在mesh的assignment中使用  |
| const [VectorType](Classes/classzmesh_1_1core_1_1_property.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property.md#function-vector)**() const |
| [ValueType](Classes/classzmesh_1_1core_1_1_property.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property.md#function-default-value)**() |
| const [ValueType](Classes/classzmesh_1_1core_1_1_property.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property.md#function-default-value)**() const |
| [reference](Classes/classzmesh_1_1core_1_1_property.md#using-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_property.md#function-operator[])**(size_t idx) |
| [const_reference](Classes/classzmesh_1_1core_1_1_property.md#using-const-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_property.md#function-operator[])**(size_t idx) const |

## Additional inherited members

**Public Functions inherited from [zmesh::core::BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md)**

|                | Name           |
| -------------- | -------------- |
| | **[BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md#function-baseproperty)**(std::string name) |
| virtual | **[~BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md#function-~baseproperty)**() =default |
| const std::string & | **[name](Classes/classzmesh_1_1core_1_1_base_property.md#function-name)**() const<br>获得属性的名字  |

**Protected Attributes inherited from [zmesh::core::BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md)**

|                | Name           |
| -------------- | -------------- |
| std::string | **[name_](Classes/classzmesh_1_1core_1_1_base_property.md#variable-name-)**  |


## Detailed Description

```cpp
template <typename T >
class zmesh::core::Property;
```

## Public Types Documentation

### using ValueType

```cpp
using zmesh::core::Property< T >::ValueType =  T;
```


### using VectorType

```cpp
using zmesh::core::Property< T >::VectorType =  std::vector<T>;
```


### using reference

```cpp
using zmesh::core::Property< T >::reference =  typename VectorType::reference;
```


### using const_reference

```cpp
using zmesh::core::Property< T >::const_reference =  typename VectorType::const_reference;
```


## Public Functions Documentation

### function Property

```cpp
inline Property(
    std::string name,
    T default_value =T()
)
```

利用属性名和属性的默认值构造一个属性 

**Parameters**: 

  * **name** 属性名 
  * **default_value** 默认值 


### function resize

```cpp
inline virtual void resize(
    size_t n
) override
```

修改属性的size 当向Mesh中添加Vertex或者Face的时候需要使用 

**Parameters**: 

  * **n** 新的property size大小 


**Reimplements**: [zmesh::core::BaseProperty::resize](Classes/classzmesh_1_1core_1_1_base_property.md#function-resize)


### function reserve

```cpp
inline virtual void reserve(
    size_t n
) override
```

为属性的容器预留空间 具体实现就是调用stl容器的reserve而已 

**Parameters**: 

  * **n** 预留的空间大小 


**Reimplements**: [zmesh::core::BaseProperty::reserve](Classes/classzmesh_1_1core_1_1_base_property.md#function-reserve)


### function push_back

```cpp
inline virtual void push_back() override
```

添加一个空元素 

**Reimplements**: [zmesh::core::BaseProperty::push_back](Classes/classzmesh_1_1core_1_1_base_property.md#function-push-back)


### function free_memory

```cpp
inline virtual void free_memory() override
```

释放内存 

**Reimplements**: [zmesh::core::BaseProperty::free_memory](Classes/classzmesh_1_1core_1_1_base_property.md#function-free-memory)


### function clone

```cpp
inline virtual BasePropertyPtr clone() override
```

deep copy 

**Return**: BasePropertyPtr 克隆后的属性指针 

**Reimplements**: [zmesh::core::BaseProperty::clone](Classes/classzmesh_1_1core_1_1_base_property.md#function-clone)


### function vector

```cpp
inline VectorType & vector()
```

返回vector 这个函数会在mesh的assignment中使用 

**Return**: VectorType& 

### function vector

```cpp
inline const VectorType & vector() const
```


### function default_value

```cpp
inline ValueType & default_value()
```


### function default_value

```cpp
inline const ValueType & default_value() const
```


### function operator[]

```cpp
inline reference operator[](
    size_t idx
)
```


### function operator[]

```cpp
inline const_reference operator[](
    size_t idx
) const
```


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800