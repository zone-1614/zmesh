---
title: zmesh::core::FaceAroundVertexTrait
summary: 中心类型是顶点, 遍历元素类型是面的Circulator Trait 

---

# zmesh::core::FaceAroundVertexTrait



中心类型是顶点, 遍历元素类型是面的Circulator Trait 


`#include <circulators.h>`

Inherits from [zmesh::core::VertexCenterTrait](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md)

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[CenterEntityHandle](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md#using-centerentityhandle)**  |
| using [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) | **[ValueHandle](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md#using-valuehandle)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [ValueHandle](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md#using-valuehandle) | **[to_handle](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md#function-to-handle)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, const [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |

## Additional inherited members

**Public Functions inherited from [zmesh::core::VertexCenterTrait](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md)**

|                | Name           |
| -------------- | -------------- |
| void | **[increment](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md#function-increment)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |
| void | **[decrement](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md#function-decrement)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |


## Public Types Documentation

### using CenterEntityHandle

```cpp
using zmesh::core::FaceAroundVertexTrait::CenterEntityHandle =  VertexHandle;
```


### using ValueHandle

```cpp
using zmesh::core::FaceAroundVertexTrait::ValueHandle =  FaceHandle;
```


## Public Functions Documentation

### function to_handle

```cpp
static inline ValueHandle to_handle(
    const MeshKernel * mesh_kernel_,
    const HalfedgeHandle & halfedge_
)
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800