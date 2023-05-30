---
title: zmesh::core::HalfedgePropertyHandle
summary: 半边属性的Handle 可以用HalfedgeHandle来访问属性 

---

# zmesh::core::HalfedgePropertyHandle



半边属性的Handle 可以用HalfedgeHandle来访问属性  [More...](#detailed-description)


`#include <properties.h>`

Inherits from [zmesh::core::PropertyHandle< T >](Classes/classzmesh_1_1core_1_1_property_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md#function-halfedgepropertyhandle)**() =default |
| | **[HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md#function-halfedgepropertyhandle)**([PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)< T > p) |
| [reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md#function-operator[])**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) |
| [const_reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-const-reference) | **[operator[]](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md#function-operator[])**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const |

## Additional inherited members

**Public Types inherited from [zmesh::core::PropertyHandle< T >](Classes/classzmesh_1_1core_1_1_property_handle.md)**

|                | Name           |
| -------------- | -------------- |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::ValueType | **[ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::VectorType | **[VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::reference | **[reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-reference)**  |
| using typename [Property](Classes/classzmesh_1_1core_1_1_property.md)< T >::const_reference | **[const_reference](Classes/classzmesh_1_1core_1_1_property_handle.md#using-const-reference)**  |

**Public Functions inherited from [zmesh::core::PropertyHandle< T >](Classes/classzmesh_1_1core_1_1_property_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md#function-propertyhandle)**([PropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-propertyptr)< T > prop =nullptr) |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_property_handle.md#function-is-valid)**() const |
| [VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property_handle.md#function-vector)**() |
| const [VectorType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-vectortype) & | **[vector](Classes/classzmesh_1_1core_1_1_property_handle.md#function-vector)**() const |
| [ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property_handle.md#function-default-value)**() |
| const [ValueType](Classes/classzmesh_1_1core_1_1_property_handle.md#using-valuetype) & | **[default_value](Classes/classzmesh_1_1core_1_1_property_handle.md#function-default-value)**() const |
| std::string | **[name](Classes/classzmesh_1_1core_1_1_property_handle.md#function-name)**() |

**Friends inherited from [zmesh::core::PropertyHandle< T >](Classes/classzmesh_1_1core_1_1_property_handle.md)**

|                | Name           |
| -------------- | -------------- |
| class | **[PropertyContainer](Classes/classzmesh_1_1core_1_1_property_handle.md#friend-propertycontainer)**  |


## Detailed Description

```cpp
template <typename T >
class zmesh::core::HalfedgePropertyHandle;
```

半边属性的Handle 可以用HalfedgeHandle来访问属性 

**Template Parameters**: 

  * **T** 属性的具体类型 

## Public Functions Documentation

### function HalfedgePropertyHandle

```cpp
explicit HalfedgePropertyHandle() =default
```


### function HalfedgePropertyHandle

```cpp
inline explicit HalfedgePropertyHandle(
    PropertyHandle< T > p
)
```


### function operator[]

```cpp
inline reference operator[](
    HalfedgeHandle h
)
```


### function operator[]

```cpp
inline const_reference operator[](
    HalfedgeHandle h
) const
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800