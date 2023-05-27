---
title: zmesh::core::Mesh
summary: Mesh类提供了用户常用的操作 

---

# zmesh::core::Mesh



Mesh类提供了用户常用的操作 


`#include <mesh.h>`

Inherits from [zmesh::core::MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md), [zmesh::core::PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Mesh](Classes/classzmesh_1_1core_1_1_mesh.md#function-mesh)**() =default |
| virtual | **[~Mesh](Classes/classzmesh_1_1core_1_1_mesh.md#function-~mesh)**() |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[find_halfedge](Classes/classzmesh_1_1core_1_1_mesh.md#function-find-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) start, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) end) const<br>找到从start开始, 到end结束的一条半边, 如果不存在就返回一个invalid的handle  |
| [EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) | **[find_edge](Classes/classzmesh_1_1core_1_1_mesh.md#function-find-edge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v0, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v1) const<br>找到连接v0, v1的边, 如果不存在就返回一个invalid的handle  |
| void | **[Mesh::adjust_outgoing_halfedge](Classes/classzmesh_1_1core_1_1_mesh.md#function-meshadjust-outgoing-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v)<br>调整顶点v的halfedge, 当v是边界的时候, halfedge也是边界  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[add_vertex](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-vertex)**(const [Point](Namespaces/namespacezmesh_1_1core.md#using-point) & p)<br>添加一个顶点, 同时赋予其坐标  |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[add_vertex](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-vertex)**(double x, double y, double z)<br>添加一个顶点, 同时赋予其坐标  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[add_face](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-face)**(const std::vector< [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) > & vertices)<br>通过参数传入的顶点, 添加一个面  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[add_triangle](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-triangle)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v0, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v1, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v2)<br>添加一个三角形  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[add_triangle](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-triangle)**(const std::array< [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md), 3 > & vertices)<br>添加一个三角形  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[add_quad](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-quad)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v0, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v1, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v2, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v3)<br>添加一个四边形  |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[add_quad](Classes/classzmesh_1_1core_1_1_mesh.md#function-add-quad)**(const std::array< [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md), 4 > & vertices)<br>添加一个四边形  |
| int | **[valence](Classes/classzmesh_1_1core_1_1_mesh.md#function-valence)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>顶点v的邻接顶点个数  |
| int | **[valence](Classes/classzmesh_1_1core_1_1_mesh.md#function-valence)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) const<br>面f邻接的顶点个数  |
| bool | **[is_triangle_mesh](Classes/classzmesh_1_1core_1_1_mesh.md#function-is-triangle-mesh)**() const<br>是不是三角形网格  |
| bool | **[is_quad_mesh](Classes/classzmesh_1_1core_1_1_mesh.md#function-is-quad-mesh)**() const<br>是不是四边形网格  |
| bool | **[is_empty](Classes/classzmesh_1_1core_1_1_mesh.md#function-is-empty)**() const<br>网格是否为空  |
| [VertexIterator](Namespaces/namespacezmesh_1_1core.md#using-vertexiterator) | **[vertices_begin](Classes/classzmesh_1_1core_1_1_mesh.md#function-vertices-begin)**() const |
| [VertexIterator](Namespaces/namespacezmesh_1_1core.md#using-vertexiterator) | **[vertices_end](Classes/classzmesh_1_1core_1_1_mesh.md#function-vertices-end)**() const |
| [VertexRange](Namespaces/namespacezmesh_1_1core.md#using-vertexrange) | **[vertices](Classes/classzmesh_1_1core_1_1_mesh.md#function-vertices)**() const<br>用来遍历所有点  |
| [EdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-edgeiterator) | **[edges_begin](Classes/classzmesh_1_1core_1_1_mesh.md#function-edges-begin)**() const |
| [EdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-edgeiterator) | **[edges_end](Classes/classzmesh_1_1core_1_1_mesh.md#function-edges-end)**() const |
| [EdgeRange](Namespaces/namespacezmesh_1_1core.md#using-edgerange) | **[edges](Classes/classzmesh_1_1core_1_1_mesh.md#function-edges)**() const<br>用来遍历所有边  |
| [HalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-halfedgeiterator) | **[halfedges_begin](Classes/classzmesh_1_1core_1_1_mesh.md#function-halfedges-begin)**() const |
| [HalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-halfedgeiterator) | **[halfedges_end](Classes/classzmesh_1_1core_1_1_mesh.md#function-halfedges-end)**() const |
| [HalfedgeRange](Namespaces/namespacezmesh_1_1core.md#using-halfedgerange) | **[halfedges](Classes/classzmesh_1_1core_1_1_mesh.md#function-halfedges)**() const<br>用来遍历所有半边  |
| [FaceIterator](Namespaces/namespacezmesh_1_1core.md#using-faceiterator) | **[faces_begin](Classes/classzmesh_1_1core_1_1_mesh.md#function-faces-begin)**() const |
| [FaceIterator](Namespaces/namespacezmesh_1_1core.md#using-faceiterator) | **[faces_end](Classes/classzmesh_1_1core_1_1_mesh.md#function-faces-end)**() const |
| [FaceRange](Namespaces/namespacezmesh_1_1core.md#using-facerange) | **[faces](Classes/classzmesh_1_1core_1_1_mesh.md#function-faces)**() const<br>用来遍历所有面  |
| [VertexAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcirculator) | **[vertices](Classes/classzmesh_1_1core_1_1_mesh.md#function-vertices)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) vertex) const |
| [EdgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcirculator) | **[edges](Classes/classzmesh_1_1core_1_1_mesh.md#function-edges)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) vertex) const |
| [HalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundvertexcirculator) | **[halfedges](Classes/classzmesh_1_1core_1_1_mesh.md#function-halfedges)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) vertex) const |
| [FaceAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcirculator) | **[faces](Classes/classzmesh_1_1core_1_1_mesh.md#function-faces)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) vertex) const |
| [VertexAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecirculator) | **[vertices](Classes/classzmesh_1_1core_1_1_mesh.md#function-vertices)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) face) const |
| [EdgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecirculator) | **[edges](Classes/classzmesh_1_1core_1_1_mesh.md#function-edges)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) face) const |
| [HalfedgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecirculator) | **[halfedges](Classes/classzmesh_1_1core_1_1_mesh.md#function-halfedges)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) face) const |
| [FaceAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecirculator) | **[faces](Classes/classzmesh_1_1core_1_1_mesh.md#function-faces)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) face) const |

## Additional inherited members

**Public Functions inherited from [zmesh::core::MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md)**

|                | Name           |
| -------------- | -------------- |
| | **[MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-meshkernel)**() |
| virtual | **[~MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-~meshkernel)**() |
| | **[MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-meshkernel)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & rhs) |
| [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & | **[operator=](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-operator=)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & rhs)<br>copy, 包括自定义属性  |
| [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & | **[assign](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-assign)**(const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & rhs)<br>copy, 不包括自定义属性  |
| [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[new_vertex](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-new-vertex)**()<br>添加新的顶点  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[new_edge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-new-edge)**()<br>添加新的边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[new_edge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-new-edge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) start, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) end)<br>添加新的边, 两个端点由参数给定  |
| [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) | **[new_face](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-new-face)**()<br>添加新的面, 不给定任何相邻的边和点  |
| size_t | **[vertices_size](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-vertices-size)**() const<br>顶点的数目, 包括被标记为删除的顶点  |
| size_t | **[edges_size](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-edges-size)**() const<br>边的数目, 包括被标记为删除的边  |
| size_t | **[halfedges_size](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-halfedges-size)**() const<br>半边的数目, 包括被标记为删除的半边  |
| size_t | **[faces_size](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-faces-size)**() const<br>面的数目, 包括被标记为删除的半边  |
| size_t | **[n_vertices](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-n-vertices)**() const<br>顶点的数目, 不包括被标记为删除的顶点  |
| size_t | **[n_edges](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-n-edges)**() const<br>顶点的数目, 不包括被标记为删除的边  |
| size_t | **[n_halfedges](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-n-halfedges)**() const<br>顶点的数目, 不包括被标记为删除的半边  |
| size_t | **[n_faces](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-n-faces)**() const<br>顶点的数目, 不包括被标记为删除的面  |
| void | **[free_memory](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-free-memory)**()<br>释放内存  |
| virtual void | **[clear](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-clear)**()<br>清除所有数据  |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-deleted)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>顶点是否被删除  |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-deleted)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e) const<br>边是否被删除  |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-deleted)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>半边是否被删除  |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-deleted)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) const<br>面是否被删除  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-valid)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>顶点是否有效  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-valid)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e) const<br>边是否有效  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-valid)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>半边是否有效  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-valid)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) const<br>面是否有效  |
| const [Point](Namespaces/namespacezmesh_1_1core.md#using-point) & | **[point](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-point)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>获得顶点对应的三维坐标  |
| [Point](Namespaces/namespacezmesh_1_1core.md#using-point) & | **[point](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-point)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v)<br>获得顶点对应的三维坐标  |
| void | **[set_point](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-point)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v, [Point](Namespaces/namespacezmesh_1_1core.md#using-point) p)<br>设置顶点对应的三维坐标  |
| std::vector< [Point](Namespaces/namespacezmesh_1_1core.md#using-point) > & | **[points](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-points)**()<br>返回所有顶点的三维坐标  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>返回顶点v的一条outgoing halfedge  |
| void | **[set_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h)<br>设置顶点v的outgoing halfedge  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[outgoing_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-outgoing-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>返回顶点v的一条outgoing halfedge  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[incoming_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-incoming-halfedge)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>返回顶点v的一条incoming halfedge  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-boundary)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>判断顶点是不是边界点  |
| bool | **[is_isolated](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-isolated)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) const<br>判断顶点是不是孤立点  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-halfedge)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e, int i) const<br>返回边e的半边, i必须是0或1  |
| [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[vertex](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-vertex)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e, int i) const<br>返回边e的顶点, i必须是0或1  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-boundary)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e) const<br>判断边是不是边界  |
| [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[to_vertex](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-to-vertex)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回半边的to顶点  |
| [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) | **[from_vertex](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-from-vertex)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回半边的from顶点  |
| void | **[set_to_vertex](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-to-vertex)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v)<br>设置半边的to顶点  |
| [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) | **[face](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-face)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回与半边h相接的一个面  |
| [EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) | **[edge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-edge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回与半边h相关的一条边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[opposite](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-opposite)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回半边h的反向半边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[next_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-next-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回h的下一条半边  |
| void | **[set_next_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-next-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) nh)<br>设置h的下一条半边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[prev_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-prev-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回h的上一条半边  |
| void | **[set_prev_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-prev-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) ph)<br>设置h的上一条半边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[cw_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-cw-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回h按顺时针旋转的下一条半边  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[ccw_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-ccw-halfedge)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>返回h按逆时针旋转的下一条半边  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-boundary)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) const<br>判断半边是不是边界  |
| [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-halfedge)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) const<br>返回与f相接的一条半边  |
| void | **[set_halfedge](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-halfedge)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h)<br>设置f相接的半边  |
| void | **[set_face](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-set-face)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f)<br>设置半边相接的面  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-boundary)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) const<br>判断面是不是边界  |

**Protected Attributes inherited from [zmesh::core::MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md)**

|                | Name           |
| -------------- | -------------- |
| [VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< [Point](Namespaces/namespacezmesh_1_1core.md#using-point) > | **[vpoints_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-vpoints-)**  |
| [VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< [VertexTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_vertex_topology.md) > | **[vertices_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-vertices-)**  |
| [EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)< [EdgeTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_edge_topology.md) > | **[edges_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-edges-)**  |
| [HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)< [HalfedgeTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md) > | **[halfedges_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-halfedges-)**  |
| [FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)< [FaceTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_face_topology.md) > | **[faces_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-faces-)**  |
| bool | **[has_garbage_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-has-garbage-)**  |
| [VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< bool > | **[v_deleted_bits_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-v-deleted-bits-)**  |
| [EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)< bool > | **[e_deleted_bits_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-e-deleted-bits-)**  |
| [FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)< bool > | **[f_deleted_bits_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-f-deleted-bits-)**  |
| [Index](Namespaces/namespacezmesh_1_1core.md#using-index) | **[n_deleted_vertices_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-n-deleted-vertices-)**  |
| [Index](Namespaces/namespacezmesh_1_1core.md#using-index) | **[n_deleted_edges_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-n-deleted-edges-)**  |
| [Index](Namespaces/namespacezmesh_1_1core.md#using-index) | **[n_deleted_faces_](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#variable-n-deleted-faces-)**  |

**Public Functions inherited from [zmesh::core::PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)**

|                | Name           |
| -------------- | -------------- |
| | **[PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-propertykernel)**() =default |
| | **[~PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-~propertykernel)**() |
| bool | **[exist_vertex_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-exist-vertex-property)**(const std::string & name) const<br>根据属性名字判断顶点属性是否存在  |
| template <typename T \> <br>[VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< T > | **[add_vertex_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-add-vertex-property)**(const std::string & name, const T defalut_value =T())<br>添加顶点属性, 其名字和默认值由参数给定  |
| template <typename T \> <br>[VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< T > | **[get_vertex_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-vertex-property)**(const std::string & name) const<br>根据参数给定的名字获得顶点属性的Handle  |
| template <typename T \> <br>[VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< T > | **[get_or_add_vertex_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-or-add-vertex-property)**(const std::string & name, const T default_value =T())<br>根据给定的名字获取顶点属性, 如果不存在, 就添加一个新的顶点属性, 它的名字和默认值由参数给定  |
| template <typename T \> <br>void | **[remove_vertex_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-remove-vertex-property)**([VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)< T > & handle)<br>根据顶点属性的Handle删除顶点属性  |
| bool | **[exist_edge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-exist-edge-property)**(const std::string & name) const<br>根据属性名字判断边属性是否存在  |
| template <typename T \> <br>[EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)< T > | **[add_edge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-add-edge-property)**(const std::string & name, const T default_value =T())<br>添加边属性, 其名字和默认值由参数给定  |
| template <typename T \> <br>[EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)< T > | **[get_edge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-edge-property)**(const std::string & name) const<br>根据参数给定的名字获得边属性的Handle  |
| template <typename T \> <br>[EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)< T > | **[get_or_add_edge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-or-add-edge-property)**(const std::string & name, const T default_value =T())<br>根据给定的名字获取边属性, 如果不存在, 就添加一个新的边属性, 它的名字和默认值由参数给定  |
| bool | **[exist_halfedge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-exist-halfedge-property)**(const std::string & name) const<br>根据属性名字判断半边属性是否存在  |
| template <typename T \> <br>[HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)< T > | **[add_halfedge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-add-halfedge-property)**(const std::string & name, const T default_value =T())<br>添加半边属性, 其名字和默认值由参数给定  |
| template <typename T \> <br>[HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)< T > | **[get_halfedge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-halfedge-property)**(const std::string & name) const<br>根据参数给定的名字获得半边属性的Handle  |
| template <typename T \> <br>[HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)< T > | **[get_or_add_halfedge_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-or-add-halfedge-property)**(const std::string & name, const T default_value =T())<br>根据给定的名字获取半边属性, 如果不存在, 就添加一个新的半边属性, 它的名字和默认值由参数给定  |
| bool | **[exist_face_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-exist-face-property)**(const std::string & name) const<br>根据属性名字判断面属性是否存在  |
| template <typename T \> <br>[FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)< T > | **[add_face_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-add-face-property)**(const std::string & name, const T default_value =T())<br>添加面属性, 其名字和默认值由参数给定  |
| template <typename T \> <br>[FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)< T > | **[get_face_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-face-property)**(const std::string & name) const<br>根据参数给定的名字获得面属性的Handle  |
| template <typename T \> <br>[FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)< T > | **[get_or_add_face_property](Classes/classzmesh_1_1core_1_1_property_kernel.md#function-get-or-add-face-property)**(const std::string & name, const T default_value =T())<br>根据给定的名字获取面属性, 如果不存在, 就添加一个新的面属性, 它的名字和默认值由参数给定  |

**Protected Attributes inherited from [zmesh::core::PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)**

|                | Name           |
| -------------- | -------------- |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[vprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-vprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[eprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-eprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[hprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-hprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[fprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-fprops-)**  |


## Public Functions Documentation

### function Mesh

```cpp
Mesh() =default
```


### function ~Mesh

```cpp
inline virtual ~Mesh()
```


### function find_halfedge

```cpp
HalfedgeHandle find_halfedge(
    VertexHandle start,
    VertexHandle end
) const
```

找到从start开始, 到end结束的一条半边, 如果不存在就返回一个invalid的handle 

High Level Topological Operations 


### function find_edge

```cpp
EdgeHandle find_edge(
    VertexHandle v0,
    VertexHandle v1
) const
```

找到连接v0, v1的边, 如果不存在就返回一个invalid的handle 

### function Mesh::adjust_outgoing_halfedge

```cpp
void Mesh::adjust_outgoing_halfedge(
    VertexHandle v
)
```

调整顶点v的halfedge, 当v是边界的时候, halfedge也是边界 

### function add_vertex

```cpp
SmartVertexHandle add_vertex(
    const Point & p
)
```

添加一个顶点, 同时赋予其坐标 

### function add_vertex

```cpp
SmartVertexHandle add_vertex(
    double x,
    double y,
    double z
)
```

添加一个顶点, 同时赋予其坐标 

### function add_face

```cpp
SmartFaceHandle add_face(
    const std::vector< VertexHandle > & vertices
)
```

通过参数传入的顶点, 添加一个面 

### function add_triangle

```cpp
SmartFaceHandle add_triangle(
    VertexHandle v0,
    VertexHandle v1,
    VertexHandle v2
)
```

添加一个三角形 

### function add_triangle

```cpp
SmartFaceHandle add_triangle(
    const std::array< VertexHandle, 3 > & vertices
)
```

添加一个三角形 

### function add_quad

```cpp
SmartFaceHandle add_quad(
    VertexHandle v0,
    VertexHandle v1,
    VertexHandle v2,
    VertexHandle v3
)
```

添加一个四边形 

### function add_quad

```cpp
SmartFaceHandle add_quad(
    const std::array< VertexHandle, 4 > & vertices
)
```

添加一个四边形 

### function valence

```cpp
int valence(
    VertexHandle v
) const
```

顶点v的邻接顶点个数 

### function valence

```cpp
int valence(
    FaceHandle f
) const
```

面f邻接的顶点个数 

### function is_triangle_mesh

```cpp
bool is_triangle_mesh() const
```

是不是三角形网格 

### function is_quad_mesh

```cpp
bool is_quad_mesh() const
```

是不是四边形网格 

### function is_empty

```cpp
inline bool is_empty() const
```

网格是否为空 

### function vertices_begin

```cpp
inline VertexIterator vertices_begin() const
```


Iterators 


### function vertices_end

```cpp
inline VertexIterator vertices_end() const
```


### function vertices

```cpp
inline VertexRange vertices() const
```

用来遍历所有点 

### function edges_begin

```cpp
inline EdgeIterator edges_begin() const
```


### function edges_end

```cpp
inline EdgeIterator edges_end() const
```


### function edges

```cpp
inline EdgeRange edges() const
```

用来遍历所有边 

### function halfedges_begin

```cpp
inline HalfedgeIterator halfedges_begin() const
```


### function halfedges_end

```cpp
inline HalfedgeIterator halfedges_end() const
```


### function halfedges

```cpp
inline HalfedgeRange halfedges() const
```

用来遍历所有半边 

### function faces_begin

```cpp
inline FaceIterator faces_begin() const
```


### function faces_end

```cpp
inline FaceIterator faces_end() const
```


### function faces

```cpp
inline FaceRange faces() const
```

用来遍历所有面 

### function vertices

```cpp
inline VertexAroundVertexCirculator vertices(
    VertexHandle vertex
) const
```


**Parameters**: 

  * **vertex** 中心 


Circulators 


### function edges

```cpp
inline EdgeAroundVertexCirculator edges(
    VertexHandle vertex
) const
```


**Parameters**: 

  * **vertex** 中心 


### function halfedges

```cpp
inline HalfedgeAroundVertexCirculator halfedges(
    VertexHandle vertex
) const
```


**Parameters**: 

  * **vertex** 中心 


### function faces

```cpp
inline FaceAroundVertexCirculator faces(
    VertexHandle vertex
) const
```


**Parameters**: 

  * **vertex** 中心 


### function vertices

```cpp
inline VertexAroundFaceCirculator vertices(
    FaceHandle face
) const
```


**Parameters**: 

  * **face** 中心 


### function edges

```cpp
inline EdgeAroundFaceCirculator edges(
    FaceHandle face
) const
```


**Parameters**: 

  * **face** 中心 


### function halfedges

```cpp
inline HalfedgeAroundFaceCirculator halfedges(
    FaceHandle face
) const
```


**Parameters**: 

  * **face** 中心 


### function faces

```cpp
inline FaceAroundFaceCirculator faces(
    FaceHandle face
) const
```


**Parameters**: 

  * **face** 中心 


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800