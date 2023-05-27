---
title: zmesh::core::FaceCenterTrait
summary: 以Face做中心的Circulator Trait 

---

# zmesh::core::FaceCenterTrait



以Face做中心的Circulator Trait 


`#include <circulators.h>`

Inherited by [zmesh::core::EdgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_edge_around_face_trait.md), [zmesh::core::FaceAroundFaceTrait](Classes/structzmesh_1_1core_1_1_face_around_face_trait.md), [zmesh::core::HalfedgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_halfedge_around_face_trait.md), [zmesh::core::VertexAroundFaceTrait](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[increment](Classes/structzmesh_1_1core_1_1_face_center_trait.md#function-increment)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |
| void | **[decrement](Classes/structzmesh_1_1core_1_1_face_center_trait.md#function-decrement)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |

## Public Functions Documentation

### function increment

```cpp
static inline void increment(
    const MeshKernel * mesh_kernel_,
    HalfedgeHandle & halfedge_
)
```


### function decrement

```cpp
static inline void decrement(
    const MeshKernel * mesh_kernel_,
    HalfedgeHandle & halfedge_
)
```


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800