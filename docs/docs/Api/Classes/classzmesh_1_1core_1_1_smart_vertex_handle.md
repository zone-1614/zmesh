---
title: zmesh::core::SmartVertexHandle
summary: Smart handle implementation. 

---

# zmesh::core::SmartVertexHandle



Smart handle implementation. 


`#include <smart_handles.h>`

Inherits from [zmesh::core::VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md), [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-smartvertexhandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max), const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh =nullptr) |
| const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * | **[mesh](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-mesh)**() const<br>返回所持有的MeshKernel指针  |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-is-deleted)**() const<br>是否被标记为删除  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-is-boundary)**() const<br>是否是边界点  |
| const [Point](Namespaces/namespacezmesh_1_1core.md#using-point) & | **[point](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-point)**() const<br>返回定点对应的三维坐标  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-halfedge)**() const<br>返回一条outgoing halfedge  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[out](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-out)**() const<br>与 [halfedge()](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-halfedge) 相同  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[in](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-in)**() const<br>返回一条incoming halfedge  |
| [VertexAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcirculator) | **[vertices](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-vertices)**() const<br>遍历这个顶点的1-ring  |
| [VertexAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcwcirculator) | **[vertices_cw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-vertices-cw)**() const<br>遍历这个顶点的1-ring, 顺时针版本  |
| [VertexAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexccwcirculator) | **[vertices_ccw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-vertices-ccw)**() const<br>遍历这个顶点的1-ring, 逆时针版本  |
| [EdgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcirculator) | **[edges](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-edges)**() const<br>遍历这个顶点相接的边  |
| [EdgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcwcirculator) | **[edges_cw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-edges-cw)**() const<br>遍历这个顶点相接的边, 顺时针版本  |
| [EdgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexccwcirculator) | **[edges_ccw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-edges-ccw)**() const<br>遍历这个顶点相接的边, 逆时针版本  |
| [HalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundvertexcirculator) | **[halfedges](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-halfedges)**() const<br>遍历这个顶点相接的半边  |
| [OutgoingHalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcirculator) | **[outgoing_halfedges](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-outgoing-halfedges)**() const<br>遍历这个顶点相接的outgoing半边  |
| [OutgoingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcwcirculator) | **[outgoing_halfedges_cw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-outgoing-halfedges-cw)**() const<br>遍历这个顶点相接的outgoing半边, 顺时针版本  |
| [OutgoingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexccwcirculator) | **[outgoing_halfedges_ccw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-outgoing-halfedges-ccw)**() const<br>遍历这个顶点相接的outgoing半边, 逆时针版本  |
| [IncomingHalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcirculator) | **[incoming_halfedges](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-incoming-halfedges)**() const<br>遍历这个顶点相接的incoming半边  |
| [IncomingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcwcirculator) | **[incoming_halfedges_cw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-incoming-halfedges-cw)**() const<br>遍历这个顶点相接的incoming半边, 顺时针版本  |
| [IncomingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexccwcirculator) | **[incoming_halfedges_ccw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-incoming-halfedges-ccw)**() const<br>遍历这个顶点相接的incoming半边, 逆时针版本  |
| [FaceAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcirculator) | **[faces](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-faces)**() const<br>遍历这个顶点相接的面  |
| [FaceAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcwcirculator) | **[faces_cw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-faces-cw)**() const<br>遍历这个顶点相接的面, 顺时针版本  |
| [FaceAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexccwcirculator) | **[faces_ccw](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-faces-ccw)**() const<br>遍历这个顶点相接的面, 逆时针版本  |
| unsigned int | **[valence](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-valence)**() const<br>valence就是这个顶点相接的边的个数  |

## Additional inherited members

**Public Functions inherited from [zmesh::core::VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md#function-vertexhandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |

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

### function SmartVertexHandle

```cpp
inline explicit SmartVertexHandle(
    Index idx =INDEX_MAX,
    const MeshKernel * mesh =nullptr
)
```


### function mesh

```cpp
inline const MeshKernel * mesh() const
```

返回所持有的MeshKernel指针 

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

### function point

```cpp
const Point & point() const
```

返回定点对应的三维坐标 

### function halfedge

```cpp
SmartHalfedgeHandle halfedge() const
```

返回一条outgoing halfedge 

### function out

```cpp
SmartHalfedgeHandle out() const
```

与 [halfedge()](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md#function-halfedge) 相同 

### function in

```cpp
SmartHalfedgeHandle in() const
```

返回一条incoming halfedge 

### function vertices

```cpp
VertexAroundVertexCirculator vertices() const
```

遍历这个顶点的1-ring 

Circulators, 默认是顺时针 


### function vertices_cw

```cpp
VertexAroundVertexCWCirculator vertices_cw() const
```

遍历这个顶点的1-ring, 顺时针版本 

### function vertices_ccw

```cpp
VertexAroundVertexCCWCirculator vertices_ccw() const
```

遍历这个顶点的1-ring, 逆时针版本 

### function edges

```cpp
EdgeAroundVertexCirculator edges() const
```

遍历这个顶点相接的边 

### function edges_cw

```cpp
EdgeAroundVertexCWCirculator edges_cw() const
```

遍历这个顶点相接的边, 顺时针版本 

### function edges_ccw

```cpp
EdgeAroundVertexCCWCirculator edges_ccw() const
```

遍历这个顶点相接的边, 逆时针版本 

### function halfedges

```cpp
HalfedgeAroundVertexCirculator halfedges() const
```

遍历这个顶点相接的半边 

### function outgoing_halfedges

```cpp
OutgoingHalfedgeAroundVertexCirculator outgoing_halfedges() const
```

遍历这个顶点相接的outgoing半边 

### function outgoing_halfedges_cw

```cpp
OutgoingHalfedgeAroundVertexCWCirculator outgoing_halfedges_cw() const
```

遍历这个顶点相接的outgoing半边, 顺时针版本 

### function outgoing_halfedges_ccw

```cpp
OutgoingHalfedgeAroundVertexCCWCirculator outgoing_halfedges_ccw() const
```

遍历这个顶点相接的outgoing半边, 逆时针版本 

### function incoming_halfedges

```cpp
IncomingHalfedgeAroundVertexCirculator incoming_halfedges() const
```

遍历这个顶点相接的incoming半边 

### function incoming_halfedges_cw

```cpp
IncomingHalfedgeAroundVertexCWCirculator incoming_halfedges_cw() const
```

遍历这个顶点相接的incoming半边, 顺时针版本 

### function incoming_halfedges_ccw

```cpp
IncomingHalfedgeAroundVertexCCWCirculator incoming_halfedges_ccw() const
```

遍历这个顶点相接的incoming半边, 逆时针版本 

### function faces

```cpp
FaceAroundVertexCirculator faces() const
```

遍历这个顶点相接的面 

### function faces_cw

```cpp
FaceAroundVertexCWCirculator faces_cw() const
```

遍历这个顶点相接的面, 顺时针版本 

### function faces_ccw

```cpp
FaceAroundVertexCCWCirculator faces_ccw() const
```

遍历这个顶点相接的面, 逆时针版本 

### function valence

```cpp
unsigned int valence() const
```

valence就是这个顶点相接的边的个数 

-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800