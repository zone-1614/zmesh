---
title: zmesh::core::VertexCenterTrait
summary: 以Vertex做中心的Circulator Trait 

---

# zmesh::core::VertexCenterTrait



以Vertex做中心的Circulator Trait 


`#include <circulators.h>`

Inherited by [zmesh::core::EdgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_edge_around_vertex_trait.md), [zmesh::core::FaceAroundVertexTrait](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md), [zmesh::core::IncomingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_incoming_halfedge_around_vertex_trait.md), [zmesh::core::OutgoingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_outgoing_halfedge_around_vertex_trait.md), [zmesh::core::VertexAroundVertexTrait](Classes/structzmesh_1_1core_1_1_vertex_around_vertex_trait.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[increment](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md#function-increment)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |
| void | **[decrement](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md#function-decrement)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel_, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) & halfedge_) |

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

Updated on 2023-05-30 at 09:04:12 +0800