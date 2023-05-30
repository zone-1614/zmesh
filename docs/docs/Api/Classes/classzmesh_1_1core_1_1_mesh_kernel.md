---
title: zmesh::core::MeshKernel
summary: 实现了较低级别的拓扑操作和常见的网格操作 低级别的拓扑操作不安全, 不建议用, 一般用Mesh中的较高级的操作 

---

# zmesh::core::MeshKernel



实现了较低级别的拓扑操作和常见的网格操作 低级别的拓扑操作不安全, 不建议用, 一般用Mesh中的较高级的操作 


`#include <mesh_kernel.h>`

Inherits from [zmesh::core::PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)

Inherited by [zmesh::core::Mesh](Classes/classzmesh_1_1core_1_1_mesh.md)

## Public Functions

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
| bool | **[is_empty](Classes/classzmesh_1_1core_1_1_mesh_kernel.md#function-is-empty)**() const<br>判断网格是否为空(有没有顶点)  |
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

## Protected Attributes

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

## Additional inherited members

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

### function MeshKernel

```cpp
MeshKernel()
```


### function ~MeshKernel

```cpp
inline virtual ~MeshKernel()
```


### function MeshKernel

```cpp
inline MeshKernel(
    const MeshKernel & rhs
)
```


### function operator=

```cpp
MeshKernel & operator=(
    const MeshKernel & rhs
)
```

copy, 包括自定义属性 

### function assign

```cpp
MeshKernel & assign(
    const MeshKernel & rhs
)
```

copy, 不包括自定义属性 

### function new_vertex

```cpp
VertexHandle new_vertex()
```

添加新的顶点 

### function new_edge

```cpp
HalfedgeHandle new_edge()
```

添加新的边 

### function new_edge

```cpp
HalfedgeHandle new_edge(
    VertexHandle start,
    VertexHandle end
)
```

添加新的边, 两个端点由参数给定 

### function new_face

```cpp
FaceHandle new_face()
```

添加新的面, 不给定任何相邻的边和点 

### function vertices_size

```cpp
inline size_t vertices_size() const
```

顶点的数目, 包括被标记为删除的顶点 

### function edges_size

```cpp
inline size_t edges_size() const
```

边的数目, 包括被标记为删除的边 

### function halfedges_size

```cpp
inline size_t halfedges_size() const
```

半边的数目, 包括被标记为删除的半边 

### function faces_size

```cpp
inline size_t faces_size() const
```

面的数目, 包括被标记为删除的半边 

### function n_vertices

```cpp
inline size_t n_vertices() const
```

顶点的数目, 不包括被标记为删除的顶点 

### function n_edges

```cpp
inline size_t n_edges() const
```

顶点的数目, 不包括被标记为删除的边 

### function n_halfedges

```cpp
inline size_t n_halfedges() const
```

顶点的数目, 不包括被标记为删除的半边 

### function n_faces

```cpp
inline size_t n_faces() const
```

顶点的数目, 不包括被标记为删除的面 

### function is_empty

```cpp
inline bool is_empty() const
```

判断网格是否为空(有没有顶点) 

### function free_memory

```cpp
void free_memory()
```

释放内存 

### function clear

```cpp
virtual void clear()
```

清除所有数据 

### function is_deleted

```cpp
inline bool is_deleted(
    VertexHandle v
) const
```

顶点是否被删除 

### function is_deleted

```cpp
inline bool is_deleted(
    EdgeHandle e
) const
```

边是否被删除 

### function is_deleted

```cpp
inline bool is_deleted(
    HalfedgeHandle h
) const
```

半边是否被删除 

### function is_deleted

```cpp
inline bool is_deleted(
    FaceHandle f
) const
```

面是否被删除 

### function is_valid

```cpp
inline bool is_valid(
    VertexHandle v
) const
```

顶点是否有效 

### function is_valid

```cpp
inline bool is_valid(
    EdgeHandle e
) const
```

边是否有效 

### function is_valid

```cpp
inline bool is_valid(
    HalfedgeHandle h
) const
```

半边是否有效 

### function is_valid

```cpp
inline bool is_valid(
    FaceHandle f
) const
```

面是否有效 

### function point

```cpp
inline const Point & point(
    VertexHandle v
) const
```

获得顶点对应的三维坐标 

### function point

```cpp
inline Point & point(
    VertexHandle v
)
```

获得顶点对应的三维坐标 

### function set_point

```cpp
inline void set_point(
    VertexHandle v,
    Point p
)
```

设置顶点对应的三维坐标 

### function points

```cpp
inline std::vector< Point > & points()
```

返回所有顶点的三维坐标 

### function halfedge

```cpp
inline HalfedgeHandle halfedge(
    VertexHandle v
) const
```

返回顶点v的一条outgoing halfedge 

### function set_halfedge

```cpp
inline void set_halfedge(
    VertexHandle v,
    HalfedgeHandle h
)
```

设置顶点v的outgoing halfedge 

### function outgoing_halfedge

```cpp
inline HalfedgeHandle outgoing_halfedge(
    VertexHandle v
) const
```

返回顶点v的一条outgoing halfedge 

### function incoming_halfedge

```cpp
inline HalfedgeHandle incoming_halfedge(
    VertexHandle v
) const
```

返回顶点v的一条incoming halfedge 

### function is_boundary

```cpp
inline bool is_boundary(
    VertexHandle v
) const
```

判断顶点是不是边界点 

### function is_isolated

```cpp
inline bool is_isolated(
    VertexHandle v
) const
```

判断顶点是不是孤立点 

### function halfedge

```cpp
inline HalfedgeHandle halfedge(
    EdgeHandle e,
    int i
) const
```

返回边e的半边, i必须是0或1 

### function vertex

```cpp
inline VertexHandle vertex(
    EdgeHandle e,
    int i
) const
```

返回边e的顶点, i必须是0或1 

### function is_boundary

```cpp
inline bool is_boundary(
    EdgeHandle e
) const
```

判断边是不是边界 

### function to_vertex

```cpp
inline VertexHandle to_vertex(
    HalfedgeHandle h
) const
```

返回半边的to顶点 

### function from_vertex

```cpp
inline VertexHandle from_vertex(
    HalfedgeHandle h
) const
```

返回半边的from顶点 

### function set_to_vertex

```cpp
inline void set_to_vertex(
    HalfedgeHandle h,
    VertexHandle v
)
```

设置半边的to顶点 

### function face

```cpp
inline FaceHandle face(
    HalfedgeHandle h
) const
```

返回与半边h相接的一个面 

### function edge

```cpp
inline EdgeHandle edge(
    HalfedgeHandle h
) const
```

返回与半边h相关的一条边 

### function opposite

```cpp
inline HalfedgeHandle opposite(
    HalfedgeHandle h
) const
```

返回半边h的反向半边 

### function next_halfedge

```cpp
inline HalfedgeHandle next_halfedge(
    HalfedgeHandle h
) const
```

返回h的下一条半边 

### function set_next_halfedge

```cpp
inline void set_next_halfedge(
    HalfedgeHandle h,
    HalfedgeHandle nh
)
```

设置h的下一条半边 

### function prev_halfedge

```cpp
inline HalfedgeHandle prev_halfedge(
    HalfedgeHandle h
) const
```

返回h的上一条半边 

### function set_prev_halfedge

```cpp
inline void set_prev_halfedge(
    HalfedgeHandle h,
    HalfedgeHandle ph
)
```

设置h的上一条半边 

### function cw_halfedge

```cpp
inline HalfedgeHandle cw_halfedge(
    HalfedgeHandle h
) const
```

返回h按顺时针旋转的下一条半边 

### function ccw_halfedge

```cpp
inline HalfedgeHandle ccw_halfedge(
    HalfedgeHandle h
) const
```

返回h按逆时针旋转的下一条半边 

### function is_boundary

```cpp
inline bool is_boundary(
    HalfedgeHandle h
) const
```

判断半边是不是边界 

### function halfedge

```cpp
inline HalfedgeHandle halfedge(
    FaceHandle f
) const
```

返回与f相接的一条半边 

### function set_halfedge

```cpp
inline void set_halfedge(
    FaceHandle f,
    HalfedgeHandle h
)
```

设置f相接的半边 

### function set_face

```cpp
inline void set_face(
    HalfedgeHandle h,
    FaceHandle f
)
```

设置半边相接的面 

### function is_boundary

```cpp
inline bool is_boundary(
    FaceHandle f
) const
```

判断面是不是边界 

## Protected Attributes Documentation

### variable vpoints_

```cpp
VertexPropertyHandle< Point > vpoints_;
```


### variable vertices_

```cpp
VertexPropertyHandle< VertexTopology > vertices_;
```


### variable edges_

```cpp
EdgePropertyHandle< EdgeTopology > edges_;
```


### variable halfedges_

```cpp
HalfedgePropertyHandle< HalfedgeTopology > halfedges_;
```


### variable faces_

```cpp
FacePropertyHandle< FaceTopology > faces_;
```


### variable has_garbage_

```cpp
bool has_garbage_ {false};
```


### variable v_deleted_bits_

```cpp
VertexPropertyHandle< bool > v_deleted_bits_;
```


### variable e_deleted_bits_

```cpp
EdgePropertyHandle< bool > e_deleted_bits_;
```


### variable f_deleted_bits_

```cpp
FacePropertyHandle< bool > f_deleted_bits_;
```


### variable n_deleted_vertices_

```cpp
Index n_deleted_vertices_ {0};
```


### variable n_deleted_edges_

```cpp
Index n_deleted_edges_ {0};
```


### variable n_deleted_faces_

```cpp
Index n_deleted_faces_ {0};
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800