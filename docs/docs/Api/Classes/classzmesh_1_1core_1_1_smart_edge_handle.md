---
title: zmesh::core::SmartEdgeHandle
summary: Smart handle implementation. 

---

# zmesh::core::SmartEdgeHandle



Smart handle implementation. 


`#include <smart_handles.h>`

Inherits from [zmesh::core::EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md), [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-smartedgehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max), const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh =nullptr) |
| const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * | **[mesh](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-mesh)**() const |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-is-deleted)**() const<br>是否被标记为删除  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-is-boundary)**() const<br>是否是边界点  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-halfedge)**(int i) const |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[h](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-h)**(int i) const |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[h0](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-h0)**() const<br>等价于h(0)  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[h1](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-h1)**() const<br>等价于h(1)  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[vertex](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-vertex)**(int i) const |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[v](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-v)**(int i) const<br>等价于vertex(i)  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[v0](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-v0)**() const<br>等价于v(0)  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[v1](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md#function-v1)**() const<br>等价于v(1)  |

## Additional inherited members

**Public Functions inherited from [zmesh::core::EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md#function-edgehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |

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

### function SmartEdgeHandle

```cpp
inline explicit SmartEdgeHandle(
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

### function halfedge

```cpp
SmartHalfedgeHandle halfedge(
    int i
) const
```


**Parameters**: 

  * **i** 必须是0或1 


返回该边对应的两条半边之一 


### function h

```cpp
SmartHalfedgeHandle h(
    int i
) const
```


**Parameters**: 

  * **i** 必须是0或1 


等价于halfedge(i) 


### function h0

```cpp
SmartHalfedgeHandle h0() const
```

等价于h(0) 

### function h1

```cpp
SmartHalfedgeHandle h1() const
```

等价于h(1) 

### function vertex

```cpp
SmartVertexHandle vertex(
    int i
) const
```


**Parameters**: 

  * **i** 必须是0或1 


返回该边对应的两个顶点之一 


### function v

```cpp
SmartVertexHandle v(
    int i
) const
```

等价于vertex(i) 

### function v0

```cpp
SmartVertexHandle v0() const
```

等价于v(0) 

### function v1

```cpp
SmartVertexHandle v1() const
```

等价于v(1) 

-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800