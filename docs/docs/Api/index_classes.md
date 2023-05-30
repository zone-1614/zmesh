---
title: Classes

---

# Classes




* **namespace [zmesh](Namespaces/namespacezmesh.md)** 
    * **namespace [core](Namespaces/namespacezmesh_1_1core.md)** 
        * **class [BaseCirculator](Classes/classzmesh_1_1core_1_1_base_circulator.md)** <br>Circulator的基类 通过Trait知道中心和遍历元素的类型, 通过CW知道是顺时针旋转还是逆时针旋转 目前还没有实现跳过被删除的元素, 因为Mesh还没有实现删除元素的功能 
        * **class [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md)** <br>所有迭代器的基类 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标 
        * **class [BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md)** <br>Property的基类 
        * **class [BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md)** <br>通过Range可以方便使用c++11的 range-based for 语句 
        * **class [EdgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_edge_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是边的Circulator Trait 
        * **class [EdgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_edge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是边的Circulator Trait 
        * **class [EdgeHandle](Classes/classzmesh_1_1core_1_1_edge_handle.md)** <br>用来表示Edge的Handle 
        * **class [EdgePropertyHandle](Classes/classzmesh_1_1core_1_1_edge_property_handle.md)** <br>边属性的Handle 可以用EdgeHandle来访问属性 
        * **class [FaceAroundFaceTrait](Classes/structzmesh_1_1core_1_1_face_around_face_trait.md)** <br>中心类型是面, 遍历元素类型也是面的Circulator Trait 
        * **class [FaceAroundVertexTrait](Classes/structzmesh_1_1core_1_1_face_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是面的Circulator Trait 
        * **class [FaceCenterTrait](Classes/structzmesh_1_1core_1_1_face_center_trait.md)** <br>以Face做中心的Circulator Trait 
        * **class [FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md)** <br>用来表示Face的Handle 
        * **class [FacePropertyHandle](Classes/classzmesh_1_1core_1_1_face_property_handle.md)** <br>面属性的Handle 可以用FaceHandle来访问属性 
        * **class [HalfedgeAroundFaceTrait](Classes/structzmesh_1_1core_1_1_halfedge_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是半边的Circulator Trait 
        * **class [HalfedgeHandle](Classes/classzmesh_1_1core_1_1_halfedge_handle.md)** <br>用来表示Halfedge的Handle 
        * **class [HalfedgePropertyHandle](Classes/classzmesh_1_1core_1_1_halfedge_property_handle.md)** <br>半边属性的Handle 可以用HalfedgeHandle来访问属性 
        * **class [Handle](Classes/classzmesh_1_1core_1_1_handle.md)** <br>Handle基类. Vertex, Halfedge, Edge, Face都通过Handle来操作 zmesh中利用handle来访问各种数据. 可以把handle理解为顶点, 半边, 边, 面的下标 
        * **class [IncomingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_incoming_halfedge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是incoming halfedge的Circulator Trait 
        * **class [Mesh](Classes/classzmesh_1_1core_1_1_mesh.md)** <br>Mesh类提供了用户常用的操作 
        * **class [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md)** <br>实现了较低级别的拓扑操作和常见的网格操作 低级别的拓扑操作不安全, 不建议用, 一般用Mesh中的较高级的操作 
            * **class [EdgeTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_edge_topology.md)** <br>边拓扑, 存储了属于该边的两个半边 
            * **class [FaceTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_face_topology.md)** <br>面拓扑, 存储了属于该面的一条半边 
            * **class [HalfedgeTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_halfedge_topology.md)** <br>半边拓扑 不用存储半边对应的边, 因为半边下标左移一位就是对应边的下标. 
            * **class [PropertyNames](Classes/classzmesh_1_1core_1_1_mesh_kernel_1_1_property_names.md)** 
            * **class [VertexTopology](Classes/structzmesh_1_1core_1_1_mesh_kernel_1_1_vertex_topology.md)** <br>顶点拓扑, 存储了一条属于该顶点的outgoing halfedge 如果该顶点是isolated的, 则这个半边是invalid的. 如果该顶点是边界点, 则这个半边也是边界的 
        * **class [OutgoingHalfedgeAroundVertexTrait](Classes/structzmesh_1_1core_1_1_outgoing_halfedge_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型是outgoing halfedge的Circulator Trait 
        * **class [Property](Classes/classzmesh_1_1core_1_1_property.md)** 
        * **class [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md)** <br>属性的容器, 可以包含多个容器 提供对属性的添加删除获取等操作 
        * **class [PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)** <br>属性的Handle 直接把Property返回给用户不安全, 所以封装了一个PropertyHandle, 用户只能通过Handle来操作Property. PropertyHandle只能通过下标访问属性 
        * **class [PropertyKernel](Classes/classzmesh_1_1core_1_1_property_kernel.md)** <br>实现了属性管理 
        * **class [SmartEdgeHandle](Classes/classzmesh_1_1core_1_1_smart_edge_handle.md)** <br>Smart handle implementation. 
        * **class [SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md)** <br>Smart handle implementation. 
        * **class [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md)** <br>Smart handle implementation. 
        * **class [SmartVertexHandle](Classes/classzmesh_1_1core_1_1_smart_vertex_handle.md)** <br>Smart handle implementation. 
        * **class [VertexAroundFaceTrait](Classes/structzmesh_1_1core_1_1_vertex_around_face_trait.md)** <br>中心类型是面, 遍历元素类型是顶点的Circulator Trait 
        * **class [VertexAroundVertexTrait](Classes/structzmesh_1_1core_1_1_vertex_around_vertex_trait.md)** <br>中心类型是顶点, 遍历元素类型也是顶点的Circulator Trait 常用来遍历顶点的1-ring 
        * **class [VertexCenterTrait](Classes/structzmesh_1_1core_1_1_vertex_center_trait.md)** <br>以Vertex做中心的Circulator Trait 
        * **class [VertexHandle](Classes/classzmesh_1_1core_1_1_vertex_handle.md)** <br>用来表示Vertex的Handle 
        * **class [VertexPropertyHandle](Classes/classzmesh_1_1core_1_1_vertex_property_handle.md)** <br>顶点属性的Handle 可以用VertexHandle来访问属性 
    * **namespace [io](Namespaces/namespacezmesh_1_1io.md)** 
        * **class [BaseReader](Classes/classzmesh_1_1io_1_1_base_reader.md)** <br>所有Reader的基类 
        * **class [ObjReader](Classes/classzmesh_1_1io_1_1_obj_reader.md)** <br>从obj文件读入网格 
        * **class [io_options](Classes/structzmesh_1_1io_1_1io__options.md)** <br>用来控制是否读/写顶点法向, 顶点纹理坐标, 顶点颜色等等 这个类暂时没啥用 



-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800
