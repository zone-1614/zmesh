---
title: zmesh::core::SmartFaceHandle
summary: Smart handle implementation. 

---

# zmesh::core::SmartFaceHandle



Smart handle implementation. 


`#include <smart_handles.h>`

Inherits from [zmesh::core::FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md), [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-smartfacehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max), const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * mesh =nullptr) |
| const [MeshKernel](Classes/classzmesh_1_1core_1_1_mesh_kernel.md) * | **[mesh](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-mesh)**() const |
| bool | **[is_deleted](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-is-deleted)**() const<br>是否被标记为删除  |
| bool | **[is_boundary](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-is-boundary)**() const<br>是否是边界点  |
| [SmartHalfedgeHandle](Classes/classzmesh_1_1core_1_1_smart_halfedge_handle.md) | **[halfedge](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-halfedge)**() const<br>返回相邻的一条半边  |
| [VertexAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecirculator) | **[vertices](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-vertices)**() const<br>遍历这个面周围的顶点  |
| [VertexAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfacecwcirculator) | **[vertices_cw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-vertices-cw)**() const<br>遍历这个面周围的顶点, 顺时针版本  |
| [VertexAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-vertexaroundfaceccwcirculator) | **[vertices_ccw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-vertices-ccw)**() const<br>遍历这个面周围的顶点, 逆时针版本  |
| [EdgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecirculator) | **[edges](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-edges)**() const<br>遍历这个面周围的边  |
| [EdgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfacecwcirculator) | **[edges_cw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-edges-cw)**() const<br>遍历这个面周围的边, 顺时针版本  |
| [EdgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-edgearoundfaceccwcirculator) | **[edges_ccw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-edges-ccw)**() const<br>遍历这个面周围的边, 逆时针版本  |
| [HalfedgeAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecirculator) | **[haledges](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-haledges)**() const<br>遍历这个面周围的半边  |
| [HalfedgeAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfacecwcirculator) | **[halfedges_cw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-halfedges-cw)**() const<br>遍历这个面周围的半边, 顺时针版本  |
| [HalfedgeAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-halfedgearoundfaceccwcirculator) | **[halfedges_ccw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-halfedges-ccw)**() const<br>遍历这个面周围的半边, 逆时针版本  |
| [FaceAroundFaceCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecirculator) | **[faces](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-faces)**() const<br>遍历这个面周围的面  |
| [FaceAroundFaceCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfacecwcirculator) | **[faces_cw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-faces-cw)**() const<br>遍历这个面周围的面, 顺时针版本  |
| [FaceAroundFaceCCWCirculator](Namespaces/namespacezmesh_1_1core.md#using-facearoundfaceccwcirculator) | **[faces_ccw](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-faces-ccw)**() const<br>遍历这个面周围的面, 逆时针版本  |
| unsigned int | **[valence](Classes/classzmesh_1_1core_1_1_smart_face_handle.md#function-valence)**() const<br>valence就是这个面周围的顶点个数  |

## Additional inherited members

**Public Functions inherited from [zmesh::core::FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md#function-facehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |

**Public Functions inherited from [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)**

|                | Name           |
| -------------- | -------------- |
| | **[Handle](Classes/classzmesh_1_1core_1_1_handle.md#function-handle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |
| [Index](Namespaces/namespacezmesh_1_1core.md#using-index) | **[idx](Classes/classzmesh_1_1core_1_1_handle.md#function-idx)**() const<br>返回Handle的下标  |
| void | **[reset](Classes/classzmesh_1_1core_1_1_handle.md#function-reset)**()<br>将Handle的下标设置为最大值  |
| bool | **[is_valid](Classes/classzmesh_1_1core_1_1_handle.md#function-is-valid)**() const<br>判断Handle是否有效. 当Handle的idx达到最大时, 无效.  |
| bool | **[operator==](Classes/classzmesh_1_1core_1_1_handle.md#function-operator==)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>通过判断两个Handle的idx来判断是否相同  |
| bool | **[operator!=](Classes/classzmesh_1_1core_1_1_handle.md#function-operator!=)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>与operator==相反  |
| bool | **[operator<](Classes/classzmesh_1_1core_1_1_handle.md#function-operator<)**(const [Handle](Classes/classzmesh_1_1core_1_1_handle.md) & rhs) const<br>通过两个Handle的idx来比较大小  |
| void | **[__increment](Classes/classzmesh_1_1core_1_1_handle.md#function---increment)**()<br>只会在Iterator中使用, 其他地方不会使用这个函数  |
| void | **[__decrement](Classes/classzmesh_1_1core_1_1_handle.md#function---decrement)**()<br>只会在Iterator中使用, 其他地方不会使用这个函数  |


## Public Functions Documentation

### function SmartFaceHandle

```cpp
inline explicit SmartFaceHandle(
    Index idx =INDEX_MAX,
    const MeshKernel * mesh =nullptr
)
```


### function mesh

```cpp
inline const MeshKernel * mesh() const
```


### function is_deleted

```cpp
bool is_deleted() const
```

是否被标记为删除 

Topology 


### function is_boundary

```cpp
bool is_boundary() const
```

是否是边界点 

### function halfedge

```cpp
SmartHalfedgeHandle halfedge() const
```

返回相邻的一条半边 

### function vertices

```cpp
VertexAroundFaceCirculator vertices() const
```

遍历这个面周围的顶点 

Circulators 


### function vertices_cw

```cpp
VertexAroundFaceCWCirculator vertices_cw() const
```

遍历这个面周围的顶点, 顺时针版本 

### function vertices_ccw

```cpp
VertexAroundFaceCCWCirculator vertices_ccw() const
```

遍历这个面周围的顶点, 逆时针版本 

### function edges

```cpp
EdgeAroundFaceCirculator edges() const
```

遍历这个面周围的边 

### function edges_cw

```cpp
EdgeAroundFaceCWCirculator edges_cw() const
```

遍历这个面周围的边, 顺时针版本 

### function edges_ccw

```cpp
EdgeAroundFaceCCWCirculator edges_ccw() const
```

遍历这个面周围的边, 逆时针版本 

### function haledges

```cpp
HalfedgeAroundFaceCirculator haledges() const
```

遍历这个面周围的半边 

### function halfedges_cw

```cpp
HalfedgeAroundFaceCWCirculator halfedges_cw() const
```

遍历这个面周围的半边, 顺时针版本 

### function halfedges_ccw

```cpp
HalfedgeAroundFaceCCWCirculator halfedges_ccw() const
```

遍历这个面周围的半边, 逆时针版本 

### function faces

```cpp
FaceAroundFaceCirculator faces() const
```

遍历这个面周围的面 

### function faces_cw

```cpp
FaceAroundFaceCWCirculator faces_cw() const
```

遍历这个面周围的面, 顺时针版本 

### function faces_ccw

```cpp
FaceAroundFaceCCWCirculator faces_ccw() const
```

遍历这个面周围的面, 逆时针版本 

### function valence

```cpp
unsigned int valence() const
```

valence就是这个面周围的顶点个数 

-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800