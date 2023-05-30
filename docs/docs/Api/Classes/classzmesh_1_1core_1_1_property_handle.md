---
title: zmesh::core::PropertyHandle
summary: 属性的Handle 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性 

---

# zmesh::core::PropertyHandle



属性的Handle 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性  [More...](#detailed-description)


`#include <properties.h>`

Inherited by [zmesh::core::EdgePropertyHandle< zmesh::core::MeshKernel::EdgeTopology >](Classes/classzmesh_1_1core_1_1_edge_property_handle.md), [zmesh::core::EdgePropertyHandle< bool >](Classes/classzmesh_1_1core_1_1_edge_property_handle.md), [zmesh::core::FacePropertyHandle< zmesh::core::MeshKernel::FaceTopology >](Classes/classzmesh_1_1core_1_1_face_property_handle.md), [zmesh::core::FacePropertyHandle< bool >](Classes/classzmesh_1_1core_1_1_face_property_handle.md), [zmesh::core::HalfedgePropertyHandle< zmesh::core::MeshKernel::HalfedgeTopology >](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md), [zmesh::core::VertexPropertyHandle< Point >](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md), [zmesh::core::VertexPropertyHandle< zmesh::core::MeshKernel::VertexTopology >](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md), [zmesh::core::VertexPropertyHandle< bool >](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md), [zmesh::core::EdgePropertyHandle< T >](Classes/classzmesh_1_1core_1_1_edge_property_handle.md), [zmesh::core::FacePropertyHandle< T >](Classes/classzmesh_1_1core_1_1_face_property_handle.md), [zmesh::core::HalfedgePropertyHandle< T >](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md), [zmesh::core::VertexPropertyHandle< T >](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)

## Public Types

|                | Name           |
| -------------- | -------------- |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::ValueType | **[ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::VectorType | **[VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::reference | **[reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-reference)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::const_reference | **[const_reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-const-reference)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md#function-propertyhandle)**([PropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-propertyptr)< T > prop =nullptr) |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_property_handle.md#function-is-valid)**() const |
| [VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property_handle.md#function-vector)**() |
| const [VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property_handle.md#function-vector)**() const |
| [ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property_handle.md#function-default-value)**() |
| const [ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property_handle.md#function-default-value)**() const |
| std::string | **[name](Classes/classzmesh_1_1core_1_1_property_handle.md#function-name)**() |
| [reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_property_handle.md#function-operator[])**(size_t idx) |
| [const_reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-const-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_property_handle.md#function-operator[])**(size_t idx) const |

## Friends

|                | Name           |
| -------------- | -------------- |
| class | **[PropertyContainer](Classes/classzmesh_1_1core_1_1_property_handle.md#friend-propertycontainer)**  |

## Detailed Description

```cpp
template <typename T >
class zmesh::core::PropertyHandle;
```

属性的Handle 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性 

**Template Parameters**: 

  * **T** 属性的具体类型 

## Public Types Documentation

### using ValueType

```cpp
using zmesh::core::PropertyHandle< T >::ValueType =  typename Property<T>::ValueType;
```


### using VectorType

```cpp
using zmesh::core::PropertyHandle< T >::VectorType =  typename Property<T>::VectorType;
```


### using reference

```cpp
using zmesh::core::PropertyHandle< T >::reference =  typename Property<T>::reference;
```


### using const_reference

```cpp
using zmesh::core::PropertyHandle< T >::const_reference =  typename Property<T>::const_reference;
```


## Public Functions Documentation

### function PropertyHandle

```cpp
inline PropertyHandle(
    PropertyPtr< T > prop =nullptr
)
```


### function is_valid

```cpp
inline bool is_valid() const
```


### function vector

```cpp
inline VectorType & vector()
```


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


### function name

```cpp
inline std::string name()
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


## Friends

### friend PropertyContainer

```cpp
friend class PropertyContainer(
    PropertyContainer 
);
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800