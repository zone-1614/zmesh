---
title: zmesh::core::MeshKernel::HalfedgeTopology
summary: 半边拓扑 不用存储半边对应的边, 因为半边下标左移一位就是对应边的下标. 

---

# zmesh::core::MeshKernel::HalfedgeTopology



半边拓扑 不用存储半边对应的边, 因为半边下标左移一位就是对应边的下标. 

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[next_halfedge_](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md#variable-next-halfedge-)** <br>下一条半边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[prev_halfedge_](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md#variable-prev-halfedge-)** <br>上一条半边  |
| [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[to_vertex_](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md#variable-to-vertex-)** <br>半边指向的顶点  |
| [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) | **[face_](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md#variable-face-)** <br>半边对应的面  |

## Public Attributes Documentation

### variable next_halfedge_

```cpp
HalfedgeHandle next_halfedge_;
```

下一条半边 

### variable prev_halfedge_

```cpp
HalfedgeHandle prev_halfedge_;
```

上一条半边 

### variable to_vertex_

```cpp
VertexHandle to_vertex_;
```

半边指向的顶点 

### variable face_

```cpp
FaceHandle face_;
```

半边对应的面 

-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800