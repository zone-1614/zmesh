---
title: zmesh::core::BaseCirculator
summary: Circulator的基类 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能 

---

# zmesh::core::BaseCirculator



Circulator的基类 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能  [More...](#detailed-description)


`#include <circulators.h>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using typename Trait::CenterEntityHandle | **[CenterEntityHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-centerentityhandle)**  |
| using typename Trait::ValueHandle | **[ValueHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-valuehandle)**  |
| using decltype([make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)(std::declval< [ValueHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-valuehandle) >(), std::declval< [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) >())) | **[SmartValueHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-smartvaluehandle)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-basecirculator)**() =default |
| | **[BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-basecirculator)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh, [CenterEntityHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-centerentityhandle) center) |
| [SmartValueHandle](Classes/classzmesh_1_1core_1_1_base_circulator.md#using-smartvaluehandle) | **[operator*](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator*)**() const |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[operator++](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator++)**() |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[operator++](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator++)**(int ) |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[operator--](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator--)**() |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[operator--](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator--)**(int ) |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[operator=](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator=)**(const [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & rhs) |
| bool | **[operator==](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator==)**(const [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & rhs) const |
| bool | **[operator!=](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator!=)**(const [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & rhs) const |
| | **[operator bool](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-operator-bool)**() const<br>这个迭代器是否有效  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-halfedge)**() const |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[begin](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-begin)**()<br>用于c++11的 range-based for  |
| [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md) & | **[end](Classes/classzmesh_1_1core_1_1_base_circulator.md#function-end)**()<br>用于c++11的 range-based for  |

## Detailed Description

```cpp
template <typename Trait ,
bool CW =true>
class zmesh::core::BaseCirculator;
```

Circulator的基类 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能 
## Public Types Documentation

### using CenterEntityHandle

```cpp
using zmesh::core::BaseCirculator< Trait, CW >::CenterEntityHandle =  typename Trait::CenterEntityHandle;
```


### using ValueHandle

```cpp
using zmesh::core::BaseCirculator< Trait, CW >::ValueHandle =  typename Trait::ValueHandle;
```


### using SmartValueHandle

```cpp
using zmesh::core::BaseCirculator< Trait, CW >::SmartValueHandle =  decltype(make_smart(std::declval<ValueHandle>(), std::declval<MeshKernel>()));
```


## Public Functions Documentation

### function BaseCirculator

```cpp
BaseCirculator() =default
```


### function BaseCirculator

```cpp
inline BaseCirculator(
    const MeshKernel * mesh,
    CenterEntityHandle center
)
```


### function operator*

```cpp
inline SmartValueHandle operator*() const
```


### function operator++

```cpp
inline BaseCirculator & operator++()
```


### function operator++

```cpp
inline BaseCirculator & operator++(
    int 
)
```


### function operator--

```cpp
inline BaseCirculator & operator--()
```


### function operator--

```cpp
inline BaseCirculator & operator--(
    int 
)
```


### function operator=

```cpp
inline BaseCirculator & operator=(
    const BaseCirculator & rhs
)
```


### function operator==

```cpp
inline bool operator==(
    const BaseCirculator & rhs
) const
```


### function operator!=

```cpp
inline bool operator!=(
    const BaseCirculator & rhs
) const
```


### function operator bool

```cpp
inline operator bool() const
```

这个迭代器是否有效 

### function halfedge

```cpp
inline HalfedgeHandle halfedge() const
```


### function begin

```cpp
inline BaseCirculator & begin()
```

用于c++11的 range-based for 

### function end

```cpp
inline BaseCirculator & end()
```

用于c++11的 range-based for 

-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800