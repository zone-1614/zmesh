---
title: zmesh::core::MeshKernel::VertexTopology
summary: 顶点拓扑, 存储了一条属于该顶点的outgoing halfedge 如果该顶点是isolated的, 则这个半边是invalid的. 如果该顶点是边界点, 则这个半边也是边界的 

---

# zmesh::core::MeshKernel::VertexTopology



顶点拓扑, 存储了一条属于该顶点的outgoing halfedge 如果该顶点是isolated的, 则这个半边是invalid的. 如果该顶点是边界点, 则这个半边也是边界的 

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[halfedge_](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_vertex_topology.md#variable-halfedge-)**  |

## Public Attributes Documentation

### variable halfedge_

```cpp
HalfedgeHandle halfedge_;
```


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800