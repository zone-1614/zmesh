---
title: zmesh::core

---

# zmesh::core



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[zmesh::core::BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)** <br>Circulator的基类 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能  |
| class | **[zmesh::core::BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)** <br>所有迭代器的基类 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标  |
| class | **[zmesh::core::BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md)** <br>Property的基类  |
| class | **[zmesh::core::BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)** <br>通过Range可以方便使用c++11的 range-based for 语句  |
| class | **[zmesh::core::EdgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_edge_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是边的Circulator Trait  |
| class | **[zmesh::core::EdgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_edge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是边的Circulator Trait  |
| class | **[zmesh::core::EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md)** <br>用来表示Edge的Handle  |
| class | **[zmesh::core::EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)** <br>边属性的Handle 可以用EdgeHandle来访问属性  |
| class | **[zmesh::core::FaceAroundFaceTrait](Classes/structzmesh_1_1core_1_1_face_around_face_trait.md)** <br>中心类型是面, 遍历元素类型也是面的Circulator Trait  |
| class | **[zmesh::core::FaceAroundVertexTrait](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是面的Circulator Trait  |
| class | **[zmesh::core::FaceCenterTrait](Classes/structzmesh_1_1core_1_1_face_center_trait.md)** <br>以Face做中心的Circulator Trait  |
| class | **[zmesh::core::FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md)** <br>用来表示Face的Handle  |
| class | **[zmesh::core::FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)** <br>面属性的Handle 可以用FaceHandle来访问属性  |
| class | **[zmesh::core::HalfedgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_halfedge_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是半边的Circulator Trait  |
| class | **[zmesh::core::HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md)** <br>用来表示Halfedge的Handle  |
| class | **[zmesh::core::HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)** <br>半边属性的Handle 可以用HalfedgeHandle来访问属性  |
| class | **[zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)** <br>Handle基类. Vertex, Halfedge, Edge, Face都通过Handle来操作 zmesh中利用handle来访问各种数据. 可以把handle理解为顶点, 半边, 边, 面的下标  |
| class | **[zmesh::core::IncomingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_incoming_halfedge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是incoming halfedge的Circulator Trait  |
| class | **[zmesh::core::Mesh](Classes/classzmesh_1_1core_1_1_mesh.md)** <br>Mesh类提供了用户常用的操作  |
| class | **[zmesh::core::MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md)** <br>实现了较低级别的拓扑操作和常见的网格操作 低级别的拓扑操作不安全, 不建议用, 一般用Mesh中的较高级的操作  |
| class | **[zmesh::core::OutgoingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_outgoing_halfedge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是outgoing halfedge的Circulator Trait  |
| class | **[zmesh::core::Property](Classes/classzmesh_1_1core_1_1_property.md)**  |
| class | **[zmesh::core::PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md)** <br>属性的容器, 可以包含多个容器 提供对属性的添加删除获取等操作  |
| class | **[zmesh::core::PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)** <br>属性的Handle 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性  |
| class | **[zmesh::core::PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)** <br>实现了属性管理  |
| class | **[zmesh::core::SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md)** <br>Smart handle implementation.  |
| class | **[zmesh::core::SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md)** <br>Smart handle implementation.  |
| class | **[zmesh::core::SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md)** <br>Smart handle implementation.  |
| class | **[zmesh::core::SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md)** <br>Smart handle implementation.  |
| class | **[zmesh::core::VertexAroundFaceTrait](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是顶点的Circulator Trait  |
| class | **[zmesh::core::VertexAroundVertexTrait](Classes/structzmesh_1_1core_1_1_vertex_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型也是顶点的Circulator Trait 常用来遍历顶点的1-ring  |
| class | **[zmesh::core::VertexCenterTrait](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md)** <br>以Vertex做中心的Circulator Trait  |
| class | **[zmesh::core::VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md)** <br>用来表示Vertex的Handle  |
| class | **[zmesh::core::VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)** <br>顶点属性的Handle 可以用VertexHandle来访问属性  |

## Types

|                | Name           |
| -------------- | -------------- |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [VertexAroundVertexTrait](Classes/structzmesh_1_1core_1_1_vertex_around_vertex_trait.md), true > | **[VertexAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [VertexAroundVertexTrait](Classes/structzmesh_1_1core_1_1_vertex_around_vertex_trait.md), false > | **[VertexAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexccwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 逆时针  |
| using [VertexAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcwcirculator) | **[VertexAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcirculator)** <br>与VertexAroundVertexCWCirculator相同  |
| using [VertexAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexcwcirculator) | **[CW_VV](Namespaces/namespacezmesh_1_1core.md#using-cw-vv)**  |
| using [VertexAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundvertexccwcirculator) | **[CCW_VV](Namespaces/namespacezmesh_1_1core.md#using-ccw-vv)**  |
| using [CW_VV](Namespaces/namespacezmesh_1_1core.md#using-cw-vv) | **[VV](Namespaces/namespacezmesh_1_1core.md#using-vv)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [EdgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_edge_around_vertex_trait.md), true > | **[EdgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [EdgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_edge_around_vertex_trait.md), false > | **[EdgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexccwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 逆时针  |
| using [EdgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcwcirculator) | **[EdgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcirculator)** <br>与EdgeAroundVertexCWCirculator相同  |
| using [EdgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexcwcirculator) | **[CW_EV](Namespaces/namespacezmesh_1_1core.md#using-cw-ev)**  |
| using [EdgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundvertexccwcirculator) | **[CCW_EV](Namespaces/namespacezmesh_1_1core.md#using-ccw-ev)**  |
| using [CW_EV](Namespaces/namespacezmesh_1_1core.md#using-cw-ev) | **[EV](Namespaces/namespacezmesh_1_1core.md#using-ev)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [OutgoingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_outgoing_halfedge_around_vertex_trait.md), true > | **[OutgoingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [OutgoingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_outgoing_halfedge_around_vertex_trait.md), false > | **[OutgoingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexccwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针  |
| using [OutgoingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcwcirculator) | **[OutgoingHalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcirculator)** <br>与OutgoingHalfedgeAroundVertexCWCirculator相同  |
| using [OutgoingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcwcirculator) | **[CW_OHV](Namespaces/namespacezmesh_1_1core.md#using-cw-ohv)**  |
| using [OutgoingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexccwcirculator) | **[CCW_OHV](Namespaces/namespacezmesh_1_1core.md#using-ccw-ohv)**  |
| using [CW_OHV](Namespaces/namespacezmesh_1_1core.md#using-cw-ohv) | **[OHV](Namespaces/namespacezmesh_1_1core.md#using-ohv)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [IncomingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_incoming_halfedge_around_vertex_trait.md), true > | **[IncomingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [IncomingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_incoming_halfedge_around_vertex_trait.md), false > | **[IncomingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexccwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针  |
| using [IncomingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcwcirculator) | **[IncomingHalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcirculator)** <br>与IncomingHalfedgeAroundVertexCWCirculator相同  |
| using [IncomingHalfedgeAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexcwcirculator) | **[CW_IHV](Namespaces/namespacezmesh_1_1core.md#using-cw-ihv)**  |
| using [IncomingHalfedgeAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-incominghalfedgearoundvertexccwcirculator) | **[CCW_IHV](Namespaces/namespacezmesh_1_1core.md#using-ccw-ihv)**  |
| using [CW_IHV](Namespaces/namespacezmesh_1_1core.md#using-cw-ihv) | **[IHV](Namespaces/namespacezmesh_1_1core.md#using-ihv)**  |
| using [OutgoingHalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-outgoinghalfedgearoundvertexcirculator) | **[HalfedgeAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundvertexcirculator)** <br>中心类型: 顶点, 遍历元素类型: outgoing半边, 遍历方法: 顺时针  |
| using [OHV](Namespaces/namespacezmesh_1_1core.md#using-ohv) | **[HV](Namespaces/namespacezmesh_1_1core.md#using-hv)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [FaceAroundVertexTrait](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md), true > | **[FaceAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [FaceAroundVertexTrait](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md), false > | **[FaceAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexccwcirculator)** <br>中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 逆时针  |
| using [FaceAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcwcirculator) | **[FaceAroundVertexCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcirculator)** <br>与FaceAroundVertexCWCirculator相同  |
| using [FaceAroundVertexCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexcwcirculator) | **[CW_FV](Namespaces/namespacezmesh_1_1core.md#using-cw-fv)**  |
| using [FaceAroundVertexCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundvertexccwcirculator) | **[CCW_FV](Namespaces/namespacezmesh_1_1core.md#using-ccw-fv)**  |
| using [CW_FV](Namespaces/namespacezmesh_1_1core.md#using-cw-fv) | **[FV](Namespaces/namespacezmesh_1_1core.md#using-fv)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [VertexAroundFaceTrait](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md), true > | **[VertexAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecwcirculator)** <br>中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [VertexAroundFaceTrait](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md), false > | **[VertexAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfaceccwcirculator)** <br>中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 逆时针  |
| using [VertexAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecwcirculator) | **[VertexAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecirculator)** <br>与VertexAroundFaceCWCirculator相同  |
| using [VertexAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecwcirculator) | **[CW_VF](Namespaces/namespacezmesh_1_1core.md#using-cw-vf)**  |
| using [VertexAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfaceccwcirculator) | **[CCW_VF](Namespaces/namespacezmesh_1_1core.md#using-ccw-vf)**  |
| using [CW_VF](Namespaces/namespacezmesh_1_1core.md#using-cw-vf) | **[VF](Namespaces/namespacezmesh_1_1core.md#using-vf)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [EdgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_edge_around_face_trait.md), true > | **[EdgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecwcirculator)** <br>中心类型: 面, 遍历元素类型: 边, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [EdgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_edge_around_face_trait.md), false > | **[EdgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfaceccwcirculator)** <br>中心类型: 面, 遍历元素类型: 边, 遍历方法: 逆时针  |
| using [EdgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecwcirculator) | **[EdgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecirculator)** <br>与EdgeAroundFaceCWCirculator相同  |
| using [EdgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecwcirculator) | **[CW_EF](Namespaces/namespacezmesh_1_1core.md#using-cw-ef)**  |
| using [EdgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfaceccwcirculator) | **[CCW_EF](Namespaces/namespacezmesh_1_1core.md#using-ccw-ef)**  |
| using [CW_EF](Namespaces/namespacezmesh_1_1core.md#using-cw-ef) | **[EF](Namespaces/namespacezmesh_1_1core.md#using-ef)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [HalfedgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_halfedge_around_face_trait.md), true > | **[HalfedgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecwcirculator)** <br>中心类型: 面, 遍历元素类型: 半边, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [HalfedgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_halfedge_around_face_trait.md), false > | **[HalfedgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfaceccwcirculator)** <br>中心类型: 面, 遍历元素类型: 半边, 遍历方法: 逆时针  |
| using [HalfedgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecwcirculator) | **[HalfedgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecirculator)** <br>与HalfedgeAroundFaceCWCirculator相同  |
| using [HalfedgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecwcirculator) | **[CW_HF](Namespaces/namespacezmesh_1_1core.md#using-cw-hf)**  |
| using [HalfedgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfaceccwcirculator) | **[CCW_HF](Namespaces/namespacezmesh_1_1core.md#using-ccw-hf)**  |
| using [CW_HF](Namespaces/namespacezmesh_1_1core.md#using-cw-hf) | **[HF](Namespaces/namespacezmesh_1_1core.md#using-hf)**  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [FaceAroundFaceTrait](Classes/structzmesh_1_1core_1_1_face_around_face_trait.md), true > | **[FaceAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecwcirculator)** <br>中心类型: 面, 遍历元素类型: 面, 遍历方法: 顺时针  |
| using [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)< [FaceAroundFaceTrait](Classes/structzmesh_1_1core_1_1_face_around_face_trait.md), false > | **[FaceAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfaceccwcirculator)** <br>中心类型: 面, 遍历元素类型: 面, 遍历方法: 逆时针  |
| using [FaceAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecwcirculator) | **[FaceAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecirculator)** <br>与FaceAroundFaceCWCirculator相同  |
| using [FaceAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecwcirculator) | **[CW_FF](Namespaces/namespacezmesh_1_1core.md#using-cw-ff)**  |
| using [FaceAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfaceccwcirculator) | **[CCW_FF](Namespaces/namespacezmesh_1_1core.md#using-ccw-ff)**  |
| using [CW_FF](Namespaces/namespacezmesh_1_1core.md#using-cw-ff) | **[FF](Namespaces/namespacezmesh_1_1core.md#using-ff)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) > | **[VertexIterator](Namespaces/namespacezmesh_1_1core.md#using-vertexiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md) > | **[EdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-edgeiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) > | **[HalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-halfedgeiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) > | **[FaceIterator](Namespaces/namespacezmesh_1_1core.md#using-faceiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) > | **[ConstVertexIterator](Namespaces/namespacezmesh_1_1core.md#using-constvertexiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md) > | **[ConstEdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-constedgeiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) > | **[ConstHalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-consthalfedgeiterator)**  |
| using [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)< [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) > | **[ConstFaceIterator](Namespaces/namespacezmesh_1_1core.md#using-constfaceiterator)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [VertexIterator](Namespaces/namespacezmesh_1_1core.md#using-vertexiterator) > | **[VertexRange](Namespaces/namespacezmesh_1_1core.md#using-vertexrange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [EdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-edgeiterator) > | **[EdgeRange](Namespaces/namespacezmesh_1_1core.md#using-edgerange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [HalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-halfedgeiterator) > | **[HalfedgeRange](Namespaces/namespacezmesh_1_1core.md#using-halfedgerange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [FaceIterator](Namespaces/namespacezmesh_1_1core.md#using-faceiterator) > | **[FaceRange](Namespaces/namespacezmesh_1_1core.md#using-facerange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [ConstVertexIterator](Namespaces/namespacezmesh_1_1core.md#using-constvertexiterator) > | **[ConstVertexRange](Namespaces/namespacezmesh_1_1core.md#using-constvertexrange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [ConstEdgeIterator](Namespaces/namespacezmesh_1_1core.md#using-constedgeiterator) > | **[ConstEdgeRange](Namespaces/namespacezmesh_1_1core.md#using-constedgerange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [ConstHalfedgeIterator](Namespaces/namespacezmesh_1_1core.md#using-consthalfedgeiterator) > | **[ConstHalfedgeRange](Namespaces/namespacezmesh_1_1core.md#using-consthalfedgerange)**  |
| using [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)< [ConstFaceIterator](Namespaces/namespacezmesh_1_1core.md#using-constfaceiterator) > | **[ConstFaceRange](Namespaces/namespacezmesh_1_1core.md#using-constfacerange)**  |
| using [BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md) * | **[BasePropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-basepropertyptr)**  |
| template <typename T \> <br>using [Property](Classes/classzmesh_1_1core_1_1_property.md)< T > * | **[PropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-propertyptr)**  |
| using std::uint32_t | **[Index](Namespaces/namespacezmesh_1_1core.md#using-index)**  |
| using double | **[Scalar](Namespaces/namespacezmesh_1_1core.md#using-scalar)**  |
| using Eigen::Vector3d | **[Vector3](Namespaces/namespacezmesh_1_1core.md#using-vector3)**  |
| using [Vector3](Namespaces/namespacezmesh_1_1core.md#using-vector3) | **[Point](Namespaces/namespacezmesh_1_1core.md#using-point)**  |
| using [Vector3](Namespaces/namespacezmesh_1_1core.md#using-vector3) | **[Normal](Namespaces/namespacezmesh_1_1core.md#using-normal)**  |
| using [Vector3](Namespaces/namespacezmesh_1_1core.md#using-vector3) | **[Color](Namespaces/namespacezmesh_1_1core.md#using-color)**  |
| using Eigen::Vector2d | **[Vector2](Namespaces/namespacezmesh_1_1core.md#using-vector2)**  |
| using [Vector2](Namespaces/namespacezmesh_1_1core.md#using-vector2) | **[TexCoord](Namespaces/namespacezmesh_1_1core.md#using-texcoord)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| std::ostream & | **[operator<<](Namespaces/namespacezmesh_1_1core.md#function-operator<<)**(std::ostream & os, [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v) |
| std::ostream & | **[operator<<](Namespaces/namespacezmesh_1_1core.md#function-operator<<)**(std::ostream & os, [EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e) |
| std::ostream & | **[operator<<](Namespaces/namespacezmesh_1_1core.md#function-operator<<)**(std::ostream & os, [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h) |
| std::ostream & | **[operator<<](Namespaces/namespacezmesh_1_1core.md#function-operator<<)**(std::ostream & os, [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f) |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel) |
| [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md) v, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & mesh_kernel) |
| [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel) |
| [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md) e, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & mesh_kernel) |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel) |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md) h, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & mesh_kernel) |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh_kernel) |
| [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md) | **[make_smart](Namespaces/namespacezmesh_1_1core.md#function-make-smart)**([FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md) f, const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) & mesh_kernel) |

## Attributes

|                | Name           |
| -------------- | -------------- |
| const auto | **[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)**  |

## Types Documentation

### using VertexAroundVertexCWCirculator

```cpp
using zmesh::core::VertexAroundVertexCWCirculator = typedef BaseCirculator<VertexAroundVertexTrait, true>;
```

中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Vertex Around Vertex Circulator. [CW_VV(or VV)](Namespaces/namespacezmesh_1_1core.md#using-cw-vv) and CCW_VV in short. 


### using VertexAroundVertexCCWCirculator

```cpp
using zmesh::core::VertexAroundVertexCCWCirculator = typedef BaseCirculator<VertexAroundVertexTrait, false>;
```

中心类型: 顶点, 遍历元素类型: 顶点, 遍历方法: 逆时针 

### using VertexAroundVertexCirculator

```cpp
using zmesh::core::VertexAroundVertexCirculator = typedef VertexAroundVertexCWCirculator;
```

与VertexAroundVertexCWCirculator相同 

### using CW_VV

```cpp
using zmesh::core::CW_VV = typedef VertexAroundVertexCWCirculator;
```


### using CCW_VV

```cpp
using zmesh::core::CCW_VV = typedef VertexAroundVertexCCWCirculator;
```


### using VV

```cpp
using zmesh::core::VV = typedef CW_VV;
```


### using EdgeAroundVertexCWCirculator

```cpp
using zmesh::core::EdgeAroundVertexCWCirculator = typedef BaseCirculator<EdgeAroundVertexTrait, true>;
```

中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Edge Around Vertex Circulator. [CW_EV(or EV)](Namespaces/namespacezmesh_1_1core.md#using-cw-ev) and CCW_EV in short. 


### using EdgeAroundVertexCCWCirculator

```cpp
using zmesh::core::EdgeAroundVertexCCWCirculator = typedef BaseCirculator<EdgeAroundVertexTrait, false>;
```

中心类型: 顶点, 遍历元素类型: 边, 遍历方法: 逆时针 

### using EdgeAroundVertexCirculator

```cpp
using zmesh::core::EdgeAroundVertexCirculator = typedef EdgeAroundVertexCWCirculator;
```

与EdgeAroundVertexCWCirculator相同 

### using CW_EV

```cpp
using zmesh::core::CW_EV = typedef EdgeAroundVertexCWCirculator;
```


### using CCW_EV

```cpp
using zmesh::core::CCW_EV = typedef EdgeAroundVertexCCWCirculator;
```


### using EV

```cpp
using zmesh::core::EV = typedef CW_EV;
```


### using OutgoingHalfedgeAroundVertexCWCirculator

```cpp
using zmesh::core::OutgoingHalfedgeAroundVertexCWCirculator = typedef BaseCirculator<OutgoingHalfedgeAroundVertexTrait, true>;
```

中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Outgoing Halfedge Around Vertex Circulator. [CW_OHV(or OHV)](Namespaces/namespacezmesh_1_1core.md#using-cw-ohv) and CCW_OHV in short. 


### using OutgoingHalfedgeAroundVertexCCWCirculator

```cpp
using zmesh::core::OutgoingHalfedgeAroundVertexCCWCirculator = typedef BaseCirculator<OutgoingHalfedgeAroundVertexTrait, false>;
```

中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针 

### using OutgoingHalfedgeAroundVertexCirculator

```cpp
using zmesh::core::OutgoingHalfedgeAroundVertexCirculator = typedef OutgoingHalfedgeAroundVertexCWCirculator;
```

与OutgoingHalfedgeAroundVertexCWCirculator相同 

### using CW_OHV

```cpp
using zmesh::core::CW_OHV = typedef OutgoingHalfedgeAroundVertexCWCirculator;
```


### using CCW_OHV

```cpp
using zmesh::core::CCW_OHV = typedef OutgoingHalfedgeAroundVertexCCWCirculator;
```


### using OHV

```cpp
using zmesh::core::OHV = typedef CW_OHV;
```


### using IncomingHalfedgeAroundVertexCWCirculator

```cpp
using zmesh::core::IncomingHalfedgeAroundVertexCWCirculator = typedef BaseCirculator<IncomingHalfedgeAroundVertexTrait, true>;
```

中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Incoming Halfedge Around Vertex Circulator. [CW_IHV(or IHV)](Namespaces/namespacezmesh_1_1core.md#using-cw-ihv) and CCW_IHV in short. 


### using IncomingHalfedgeAroundVertexCCWCirculator

```cpp
using zmesh::core::IncomingHalfedgeAroundVertexCCWCirculator = typedef BaseCirculator<IncomingHalfedgeAroundVertexTrait, false>;
```

中心类型: 顶点, 遍历元素类型: 半边, 遍历方法: 逆时针 

### using IncomingHalfedgeAroundVertexCirculator

```cpp
using zmesh::core::IncomingHalfedgeAroundVertexCirculator = typedef IncomingHalfedgeAroundVertexCWCirculator;
```

与IncomingHalfedgeAroundVertexCWCirculator相同 

### using CW_IHV

```cpp
using zmesh::core::CW_IHV = typedef IncomingHalfedgeAroundVertexCWCirculator;
```


### using CCW_IHV

```cpp
using zmesh::core::CCW_IHV = typedef IncomingHalfedgeAroundVertexCCWCirculator;
```


### using IHV

```cpp
using zmesh::core::IHV = typedef CW_IHV;
```


### using HalfedgeAroundVertexCirculator

```cpp
using zmesh::core::HalfedgeAroundVertexCirculator = typedef OutgoingHalfedgeAroundVertexCirculator;
```

中心类型: 顶点, 遍历元素类型: outgoing半边, 遍历方法: 顺时针 

Outgoing Halfedge Around Vertex Circulator is recommended, so there is another alias. 


### using HV

```cpp
using zmesh::core::HV = typedef OHV;
```


### using FaceAroundVertexCWCirculator

```cpp
using zmesh::core::FaceAroundVertexCWCirculator = typedef BaseCirculator<FaceAroundVertexTrait, true>;
```

中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Face Around Vertex Circulator. [CW_FV(or FV)](Namespaces/namespacezmesh_1_1core.md#using-cw-fv) and CCW_FV in short. 


### using FaceAroundVertexCCWCirculator

```cpp
using zmesh::core::FaceAroundVertexCCWCirculator = typedef BaseCirculator<FaceAroundVertexTrait, false>;
```

中心类型: 顶点, 遍历元素类型: 面, 遍历方法: 逆时针 

### using FaceAroundVertexCirculator

```cpp
using zmesh::core::FaceAroundVertexCirculator = typedef FaceAroundVertexCWCirculator;
```

与FaceAroundVertexCWCirculator相同 

### using CW_FV

```cpp
using zmesh::core::CW_FV = typedef FaceAroundVertexCWCirculator;
```


### using CCW_FV

```cpp
using zmesh::core::CCW_FV = typedef FaceAroundVertexCCWCirculator;
```


### using FV

```cpp
using zmesh::core::FV = typedef CW_FV;
```


### using VertexAroundFaceCWCirculator

```cpp
using zmesh::core::VertexAroundFaceCWCirculator = typedef BaseCirculator<VertexAroundFaceTrait, true>;
```

中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Vertex Around Face Circulator. [CW_VF(or VF)](Namespaces/namespacezmesh_1_1core.md#using-cw-vf) and CCW_VF in short. 


### using VertexAroundFaceCCWCirculator

```cpp
using zmesh::core::VertexAroundFaceCCWCirculator = typedef BaseCirculator<VertexAroundFaceTrait, false>;
```

中心类型: 面, 遍历元素类型: 顶点, 遍历方法: 逆时针 

### using VertexAroundFaceCirculator

```cpp
using zmesh::core::VertexAroundFaceCirculator = typedef VertexAroundFaceCWCirculator;
```

与VertexAroundFaceCWCirculator相同 

### using CW_VF

```cpp
using zmesh::core::CW_VF = typedef VertexAroundFaceCWCirculator;
```


### using CCW_VF

```cpp
using zmesh::core::CCW_VF = typedef VertexAroundFaceCCWCirculator;
```


### using VF

```cpp
using zmesh::core::VF = typedef CW_VF;
```


### using EdgeAroundFaceCWCirculator

```cpp
using zmesh::core::EdgeAroundFaceCWCirculator = typedef BaseCirculator<EdgeAroundFaceTrait, true>;
```

中心类型: 面, 遍历元素类型: 边, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Edge Around Face Circulator. [CW_EF(or EF)](Namespaces/namespacezmesh_1_1core.md#using-cw-ef) and CCW_EF in short. 


### using EdgeAroundFaceCCWCirculator

```cpp
using zmesh::core::EdgeAroundFaceCCWCirculator = typedef BaseCirculator<EdgeAroundFaceTrait, false>;
```

中心类型: 面, 遍历元素类型: 边, 遍历方法: 逆时针 

### using EdgeAroundFaceCirculator

```cpp
using zmesh::core::EdgeAroundFaceCirculator = typedef EdgeAroundFaceCWCirculator;
```

与EdgeAroundFaceCWCirculator相同 

### using CW_EF

```cpp
using zmesh::core::CW_EF = typedef EdgeAroundFaceCWCirculator;
```


### using CCW_EF

```cpp
using zmesh::core::CCW_EF = typedef EdgeAroundFaceCCWCirculator;
```


### using EF

```cpp
using zmesh::core::EF = typedef CW_EF;
```


### using HalfedgeAroundFaceCWCirculator

```cpp
using zmesh::core::HalfedgeAroundFaceCWCirculator = typedef BaseCirculator<HalfedgeAroundFaceTrait, true>;
```

中心类型: 面, 遍历元素类型: 半边, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Halfedge Around Face Circulator. [CW_HF(or HF)](Namespaces/namespacezmesh_1_1core.md#using-cw-hf) and CCW_HF in short. 


### using HalfedgeAroundFaceCCWCirculator

```cpp
using zmesh::core::HalfedgeAroundFaceCCWCirculator = typedef BaseCirculator<HalfedgeAroundFaceTrait, false>;
```

中心类型: 面, 遍历元素类型: 半边, 遍历方法: 逆时针 

### using HalfedgeAroundFaceCirculator

```cpp
using zmesh::core::HalfedgeAroundFaceCirculator = typedef HalfedgeAroundFaceCWCirculator;
```

与HalfedgeAroundFaceCWCirculator相同 

### using CW_HF

```cpp
using zmesh::core::CW_HF = typedef HalfedgeAroundFaceCWCirculator;
```


### using CCW_HF

```cpp
using zmesh::core::CCW_HF = typedef HalfedgeAroundFaceCCWCirculator;
```


### using HF

```cpp
using zmesh::core::HF = typedef CW_HF;
```


### using FaceAroundFaceCWCirculator

```cpp
using zmesh::core::FaceAroundFaceCWCirculator = typedef BaseCirculator<FaceAroundFaceTrait, true>;
```

中心类型: 面, 遍历元素类型: 面, 遍历方法: 顺时针 

ClockWise and Counter ClockWise Face Around Face Circulator. [CW_FF(or FF)](Namespaces/namespacezmesh_1_1core.md#using-cw-ff) and CCW_FF in short. 


### using FaceAroundFaceCCWCirculator

```cpp
using zmesh::core::FaceAroundFaceCCWCirculator = typedef BaseCirculator<FaceAroundFaceTrait, false>;
```

中心类型: 面, 遍历元素类型: 面, 遍历方法: 逆时针 

### using FaceAroundFaceCirculator

```cpp
using zmesh::core::FaceAroundFaceCirculator = typedef FaceAroundFaceCWCirculator;
```

与FaceAroundFaceCWCirculator相同 

### using CW_FF

```cpp
using zmesh::core::CW_FF = typedef FaceAroundFaceCWCirculator;
```


### using CCW_FF

```cpp
using zmesh::core::CCW_FF = typedef FaceAroundFaceCCWCirculator;
```


### using FF

```cpp
using zmesh::core::FF = typedef CW_FF;
```


### using VertexIterator

```cpp
using zmesh::core::VertexIterator = typedef BaseIterator<SmartVertexHandle>;
```


### using EdgeIterator

```cpp
using zmesh::core::EdgeIterator = typedef BaseIterator<SmartEdgeHandle>;
```


### using HalfedgeIterator

```cpp
using zmesh::core::HalfedgeIterator = typedef BaseIterator<SmartHalfedgeHandle>;
```


### using FaceIterator

```cpp
using zmesh::core::FaceIterator = typedef BaseIterator<SmartFaceHandle>;
```


### using ConstVertexIterator

```cpp
using zmesh::core::ConstVertexIterator = typedef BaseIterator<SmartVertexHandle>;
```


### using ConstEdgeIterator

```cpp
using zmesh::core::ConstEdgeIterator = typedef BaseIterator<SmartEdgeHandle>;
```


### using ConstHalfedgeIterator

```cpp
using zmesh::core::ConstHalfedgeIterator = typedef BaseIterator<SmartHalfedgeHandle>;
```


### using ConstFaceIterator

```cpp
using zmesh::core::ConstFaceIterator = typedef BaseIterator<SmartFaceHandle>;
```


### using VertexRange

```cpp
using zmesh::core::VertexRange = typedef BaseRange<VertexIterator>;
```


### using EdgeRange

```cpp
using zmesh::core::EdgeRange = typedef BaseRange<EdgeIterator>;
```


### using HalfedgeRange

```cpp
using zmesh::core::HalfedgeRange = typedef BaseRange<HalfedgeIterator>;
```


### using FaceRange

```cpp
using zmesh::core::FaceRange = typedef BaseRange<FaceIterator>;
```


### using ConstVertexRange

```cpp
using zmesh::core::ConstVertexRange = typedef BaseRange<ConstVertexIterator>;
```


### using ConstEdgeRange

```cpp
using zmesh::core::ConstEdgeRange = typedef BaseRange<ConstEdgeIterator>;
```


### using ConstHalfedgeRange

```cpp
using zmesh::core::ConstHalfedgeRange = typedef BaseRange<ConstHalfedgeIterator>;
```


### using ConstFaceRange

```cpp
using zmesh::core::ConstFaceRange = typedef BaseRange<ConstFaceIterator>;
```


### using BasePropertyPtr

```cpp
using zmesh::core::BasePropertyPtr = typedef BaseProperty*;
```


### using PropertyPtr

```cpp
template <typename T >
using zmesh::core::PropertyPtr = typedef Property<T>*;
```


### using Index

```cpp
using zmesh::core::Index = typedef std::uint32_t;
```


### using Scalar

```cpp
using zmesh::core::Scalar = typedef double;
```


### using Vector3

```cpp
using zmesh::core::Vector3 = typedef Eigen::Vector3d;
```


### using Point

```cpp
using zmesh::core::Point = typedef Vector3;
```


### using Normal

```cpp
using zmesh::core::Normal = typedef Vector3;
```


### using Color

```cpp
using zmesh::core::Color = typedef Vector3;
```


### using Vector2

```cpp
using zmesh::core::Vector2 = typedef Eigen::Vector2d;
```


### using TexCoord

```cpp
using zmesh::core::TexCoord = typedef Vector2;
```



## Functions Documentation

### function operator<<

```cpp
inline std::ostream & operator<<(
    std::ostream & os,
    VertexHandle v
)
```


Output operators 


### function operator<<

```cpp
inline std::ostream & operator<<(
    std::ostream & os,
    EdgeHandle e
)
```


### function operator<<

```cpp
inline std::ostream & operator<<(
    std::ostream & os,
    HalfedgeHandle h
)
```


### function operator<<

```cpp
inline std::ostream & operator<<(
    std::ostream & os,
    FaceHandle f
)
```


### function make_smart

```cpp
inline SmartVertexHandle make_smart(
    VertexHandle v,
    const MeshKernel * mesh_kernel
)
```


Create a smart handle from a handle and a mesh kernel 


### function make_smart

```cpp
inline SmartVertexHandle make_smart(
    VertexHandle v,
    const MeshKernel & mesh_kernel
)
```


### function make_smart

```cpp
inline SmartEdgeHandle make_smart(
    EdgeHandle e,
    const MeshKernel * mesh_kernel
)
```


### function make_smart

```cpp
inline SmartEdgeHandle make_smart(
    EdgeHandle e,
    const MeshKernel & mesh_kernel
)
```


### function make_smart

```cpp
inline SmartHalfedgeHandle make_smart(
    HalfedgeHandle h,
    const MeshKernel * mesh_kernel
)
```


### function make_smart

```cpp
inline SmartHalfedgeHandle make_smart(
    HalfedgeHandle h,
    const MeshKernel & mesh_kernel
)
```


### function make_smart

```cpp
inline SmartFaceHandle make_smart(
    FaceHandle f,
    const MeshKernel * mesh_kernel
)
```


### function make_smart

```cpp
inline SmartFaceHandle make_smart(
    FaceHandle f,
    const MeshKernel & mesh_kernel
)
```



## Attributes Documentation

### variable INDEX_MAX

```cpp
const auto INDEX_MAX = UINT32_MAX;
```





-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800