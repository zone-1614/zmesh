---
title: zmesh::core::FaceHandle
summary: 用来表示Face的Handle 

---

# zmesh::core::FaceHandle



用来表示Face的Handle 


`#include <handles.h>`

Inherits from [zmesh::core::Handle](Classes/classzmesh_1_1core_1_1_handle.md)

Inherited by [zmesh::core::SmartFaceHandle](Classes/classzmesh_1_1core_1_1_smart_face_handle.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[FaceHandle](Classes/classzmesh_1_1core_1_1_face_handle.md#function-facehandle)**([Index](Namespaces/namespacezmesh_1_1core.md#using-index) idx =[INDEX_MAX](Namespaces/namespacezmesh_1_1core.md#variable-index-max)) |

## Additional inherited members

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

### function FaceHandle

```cpp
inline FaceHandle(
    Index idx =INDEX_MAX
)
```


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800