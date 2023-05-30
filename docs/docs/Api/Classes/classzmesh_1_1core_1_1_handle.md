---
title: zmesh::core::Handle
summary: Handle基类. Vertex, Halfedge, Edge, Face都通过Handle来操作 zmesh中利用handle来访问各种数据. 可以把handle理解为顶点, 半边, 边, 面的下标 

---

# zmesh::core::Handle



Handle基类. Vertex, Halfedge, Edge, Face都通过Handle来操作 zmesh中利用handle来访问各种数据. 可以把handle理解为顶点, 半边, 边, 面的下标 


`#include <handles.h>`

Inherited by [zmesh::core::EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md), [zmesh::core::FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md), [zmesh::core::HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md), [zmesh::core::VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Handle](Classes/classzmesh_1_1core_1_1_handle.md#function-handle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |
| [Index](Namespaces/namespacezmesh_1_1core.md#using-index) | **[idx](Classes/classzmesh_1_1core_1_1_handle.md#function-idx)**() const<br>返回Handle的下标  |
| void | **[reset](Classes/classzmesh_1_1core_1_1_handle.md#function-reset)**()<br>将Handle的下标设置为最大值  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_handle.md#function-is-valid)**() const<br>判断Handle是否有效. 当Handle的idx达到最大时, 无效.  |
| bool | **[operator==](Classes/classzmesh_1_1core_1_1_handle.md#function-operator==)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>通过判断两个Handle的idx来判断是否相同  |
| bool | **[operator!=](Classes/classzmesh_1_1core_1_1_handle.md#function-operator!=)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>与operator==相反  |
| bool | **[operator<](Classes/classzmesh_1_1core_1_1_handle.md#function-operator<)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>通过两个Handle的idx来比较大小  |
| void | **[__increment](Classes/classzmesh_1_1core_1_1_handle.md#function---increment)**()<br>只会在Iterator中使用, 其他地方不会使用这个函数  |
| void | **[__decrement](Classes/classzmesh_1_1core_1_1_handle.md#function---decrement)**()<br>只会在Iterator中使用, 其他地方不会使用这个函数  |

## Public Functions Documentation

### function Handle

```cpp
inline explicit Handle(
    Index idx =INDEX_MAX
)
```


### function idx

```cpp
inline Index idx() const
```

返回Handle的下标 

### function reset

```cpp
inline void reset()
```

将Handle的下标设置为最大值 

### function is_valid

```cpp
inline bool is_valid() const
```

判断Handle是否有效. 当Handle的idx达到最大时, 无效. 

### function operator==

```cpp
inline bool operator==(
    const Handle & rhs
) const
```

通过判断两个Handle的idx来判断是否相同 

### function operator!=

```cpp
inline bool operator!=(
    const Handle & rhs
) const
```

与operator==相反 

### function operator<

```cpp
inline bool operator<(
    const Handle & rhs
) const
```

通过两个Handle的idx来比较大小 

### function __increment

```cpp
inline void __increment()
```

只会在Iterator中使用, 其他地方不会使用这个函数 

### function __decrement

```cpp
inline void __decrement()
```

只会在Iterator中使用, 其他地方不会使用这个函数 

-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800