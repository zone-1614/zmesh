---
title: zmesh::core::PropertyKernel
summary: 实现了属性管理 

---

# zmesh::core::PropertyKernel



实现了属性管理 


`#include <property_kernel.h>`

Inherited by [zmesh::core::MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md)

## Public Functions

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

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[vprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-vprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[eprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-eprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[hprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-hprops-)**  |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) | **[fprops_](Classes/classzmesh_1_1core_1_1_property_kernel.md#variable-fprops-)**  |

## Public Functions Documentation

### function PropertyKernel

```cpp
PropertyKernel() =default
```


### function ~PropertyKernel

```cpp
inline ~PropertyKernel()
```


### function exist_vertex_property

```cpp
inline bool exist_vertex_property(
    const std::string & name
) const
```

根据属性名字判断顶点属性是否存在 

### function add_vertex_property

```cpp
template <typename T >
inline VertexPropertyHandle< T > add_vertex_property(
    const std::string & name,
    const T defalut_value =T()
)
```

添加顶点属性, 其名字和默认值由参数给定 

### function get_vertex_property

```cpp
template <typename T >
inline VertexPropertyHandle< T > get_vertex_property(
    const std::string & name
) const
```

根据参数给定的名字获得顶点属性的Handle 

### function get_or_add_vertex_property

```cpp
template <typename T >
inline VertexPropertyHandle< T > get_or_add_vertex_property(
    const std::string & name,
    const T default_value =T()
)
```

根据给定的名字获取顶点属性, 如果不存在, 就添加一个新的顶点属性, 它的名字和默认值由参数给定 

### function remove_vertex_property

```cpp
template <typename T >
inline void remove_vertex_property(
    VertexPropertyHandle< T > & handle
)
```

根据顶点属性的Handle删除顶点属性 

### function exist_edge_property

```cpp
inline bool exist_edge_property(
    const std::string & name
) const
```

根据属性名字判断边属性是否存在 

### function add_edge_property

```cpp
template <typename T >
inline EdgePropertyHandle< T > add_edge_property(
    const std::string & name,
    const T default_value =T()
)
```

添加边属性, 其名字和默认值由参数给定 

### function get_edge_property

```cpp
template <typename T >
inline EdgePropertyHandle< T > get_edge_property(
    const std::string & name
) const
```

根据参数给定的名字获得边属性的Handle 

### function get_or_add_edge_property

```cpp
template <typename T >
inline EdgePropertyHandle< T > get_or_add_edge_property(
    const std::string & name,
    const T default_value =T()
)
```

根据给定的名字获取边属性, 如果不存在, 就添加一个新的边属性, 它的名字和默认值由参数给定 

### function exist_halfedge_property

```cpp
inline bool exist_halfedge_property(
    const std::string & name
) const
```

根据属性名字判断半边属性是否存在 

### function add_halfedge_property

```cpp
template <typename T >
inline HalfedgePropertyHandle< T > add_halfedge_property(
    const std::string & name,
    const T default_value =T()
)
```

添加半边属性, 其名字和默认值由参数给定 

### function get_halfedge_property

```cpp
template <typename T >
inline HalfedgePropertyHandle< T > get_halfedge_property(
    const std::string & name
) const
```

根据参数给定的名字获得半边属性的Handle 

### function get_or_add_halfedge_property

```cpp
template <typename T >
inline HalfedgePropertyHandle< T > get_or_add_halfedge_property(
    const std::string & name,
    const T default_value =T()
)
```

根据给定的名字获取半边属性, 如果不存在, 就添加一个新的半边属性, 它的名字和默认值由参数给定 

### function exist_face_property

```cpp
inline bool exist_face_property(
    const std::string & name
) const
```

根据属性名字判断面属性是否存在 

### function add_face_property

```cpp
template <typename T >
inline FacePropertyHandle< T > add_face_property(
    const std::string & name,
    const T default_value =T()
)
```

添加面属性, 其名字和默认值由参数给定 

### function get_face_property

```cpp
template <typename T >
inline FacePropertyHandle< T > get_face_property(
    const std::string & name
) const
```

根据参数给定的名字获得面属性的Handle 

### function get_or_add_face_property

```cpp
template <typename T >
inline FacePropertyHandle< T > get_or_add_face_property(
    const std::string & name,
    const T default_value =T()
)
```

根据给定的名字获取面属性, 如果不存在, 就添加一个新的面属性, 它的名字和默认值由参数给定 

## Protected Attributes Documentation

### variable vprops_

```cpp
PropertyContainer vprops_;
```


### variable eprops_

```cpp
PropertyContainer eprops_;
```


### variable hprops_

```cpp
PropertyContainer hprops_;
```


### variable fprops_

```cpp
PropertyContainer fprops_;
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800