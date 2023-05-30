---
title: zmesh::core::VertexAroundFaceTrait
summary: 中心类型是面, 遍历元素类型是顶点的Circulator Trait 

---

# zmesh::core::VertexAroundFaceTrait



中心类型是面, 遍历元素类型是顶点的Circulator Trait 


`#include <circulators.h>`

Inherits from [zmesh::core::FaceCenterTrait](Classes/structzmesh_1_1core_1_1_face_center_trait.md)

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) | **[CenterEntityHandle](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md#using-centerentityhandle)**  |
| using [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[ValueHandle](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md#using-valuehandle)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [ValueHandle](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md#using-valuehandle) | **[to_handle](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md#function-to-handle)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, const [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |

## Additional inherited members

**Public Functions inherited from [zmesh::core::FaceCenterTrait](Classes/structzmesh_1_1core_1_1_face_center_trait.md)**

|                | Name           |
| -------------- | -------------- |
| void | **[increment](Classes/structzmesh_1_1core_1_1_face_center_trait.md#function-increment)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |
| void | **[decrement](Classes/structzmesh_1_1core_1_1_face_center_trait.md#function-decrement)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |


## Public Types Documentation

### using CenterEntityHandle

```cpp
using zmesh::core::VertexAroundFaceTrait::CenterEntityHandle =  FaceHandle;
```


### using ValueHandle

```cpp
using zmesh::core::VertexAroundFaceTrait::ValueHandle =  VertexHandle;
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