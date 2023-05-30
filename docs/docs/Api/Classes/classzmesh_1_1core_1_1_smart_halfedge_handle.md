---
title: zmesh::core::SmartHalfedgeHandle
summary: Smart handle implementation. 

---

# zmesh::core::SmartHalfedgeHandle



Smart handle implementation. 


`#include <smart_handles.h>`

Inherits from [zmesh::core::HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md), [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-smarthalfedgehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max), const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh =nullptr) |
| const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * | **[mesh](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-mesh)**() const |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-is-deleted)**() const<br>是否被标记为删除  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-is-boundary)**() const<br>是否是边界点  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[next](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-next)**() const<br>返回next半边  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[prev](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-prev)**() const<br>返回prev半边  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[opp](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-opp)**() const<br>返回反方向的半边  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[from](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-from)**() const<br>返回from顶点  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[to](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-to)**() const<br>返回to顶点  |
| [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md) | **[edge](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-edge)**() const<br>返回对应的edge  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[face](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md#function-face)**() const<br>返回相接的面  |

## Additional inherited members

**Public Functions inherited from [zmesh::core::HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md#function-halfedgehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |

**Public Functions inherited from [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)**

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

### function SmartHalfedgeHandle

```cpp
inline explicit SmartHalfedgeHandle(
    Index idx =INDEX_MAX,
    const MeshKernel * mesh =nullptr
)
```


### function mesh

```cpp
inline const MeshKernel * mesh() const
```


### function is_deleted

```cpp
bool is_deleted() const
```

是否被标记为删除 

Topology 


### function is_boundary

```cpp
bool is_boundary() const
```

是否是边界点 

### function next

```cpp
SmartHalfedgeHandle next() const
```

返回next半边 

### function prev

```cpp
SmartHalfedgeHandle prev() const
```

返回prev半边 

### function opp

```cpp
SmartHalfedgeHandle opp() const
```

返回反方向的半边 

### function from

```cpp
SmartVertexHandle from() const
```

返回from顶点 

### function to

```cpp
SmartVertexHandle to() const
```

返回to顶点 

### function edge

```cpp
SmartEdgeHandle edge() const
```

返回对应的edge 

### function face

```cpp
SmartFaceHandle face() const
```

返回相接的面 

-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800