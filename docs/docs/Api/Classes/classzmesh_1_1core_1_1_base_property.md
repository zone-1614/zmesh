---
title: zmesh::core::BaseProperty
summary: Property的基类 

---

# zmesh::core::BaseProperty



Property的基类 


`#include <properties.h>`

Inherited by [zmesh::core::Property< Point >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< zmesh::core::MeshKernel::VertexTopology >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< zmesh::core::MeshKernel::EdgeTopology >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< zmesh::core::MeshKernel::HalfedgeTopology >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< zmesh::core::MeshKernel::FaceTopology >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< bool >](Classes/classzmesh_1_1core_1_1_property.md), [zmesh::core::Property< T >](Classes/classzmesh_1_1core_1_1_property.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md#function-baseproperty)**(std::string name) |
| virtual | **[~BaseProperty](Classes/classzmesh_1_1core_1_1_base_property.md#function-~baseproperty)**() =default |
| virtual void | **[resize](Classes/classzmesh_1_1core_1_1_base_property.md#function-resize)**(size_t n) =0<br>修改属性的size 当向Mesh中添加Vertex或者Face的时候需要使用  |
| virtual void | **[reserve](Classes/classzmesh_1_1core_1_1_base_property.md#function-reserve)**(size_t n) =0<br>为属性的容器预留空间 具体实现就是调用stl容器的reserve而已  |
| virtual void | **[push_back](Classes/classzmesh_1_1core_1_1_base_property.md#function-push-back)**() =0<br>添加一个空元素  |
| virtual void | **[free_memory](Classes/classzmesh_1_1core_1_1_base_property.md#function-free-memory)**() =0<br>释放内存  |
| virtual [BasePropertyPtr](Namespaces/namespacezmesh_1_1core.md#using-basepropertyptr) | **[clone](Classes/classzmesh_1_1core_1_1_base_property.md#function-clone)**() =0<br>deep copy  |
| const std::string & | **[name](Classes/classzmesh_1_1core_1_1_base_property.md#function-name)**() const<br>获得属性的名字  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::string | **[name_](Classes/classzmesh_1_1core_1_1_base_property.md#variable-name-)**  |

## Public Functions Documentation

### function BaseProperty

```cpp
inline explicit BaseProperty(
    std::string name
)
```


### function ~BaseProperty

```cpp
virtual ~BaseProperty() =default
```


### function resize

```cpp
virtual void resize(
    size_t n
) =0
```

修改属性的size 当向Mesh中添加Vertex或者Face的时候需要使用 

**Parameters**: 

  * **n** 新的property size大小 


**Reimplemented by**: [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize), [zmesh::core::Property::resize](Classes/classzmesh_1_1core_1_1_property.md#function-resize)


### function reserve

```cpp
virtual void reserve(
    size_t n
) =0
```

为属性的容器预留空间 具体实现就是调用stl容器的reserve而已 

**Parameters**: 

  * **n** 预留的空间大小 


**Reimplemented by**: [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve), [zmesh::core::Property::reserve](Classes/classzmesh_1_1core_1_1_property.md#function-reserve)


### function push_back

```cpp
virtual void push_back() =0
```

添加一个空元素 

**Reimplemented by**: [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back), [zmesh::core::Property::push_back](Classes/classzmesh_1_1core_1_1_property.md#function-push-back)


### function free_memory

```cpp
virtual void free_memory() =0
```

释放内存 

**Reimplemented by**: [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory), [zmesh::core::Property::free_memory](Classes/classzmesh_1_1core_1_1_property.md#function-free-memory)


### function clone

```cpp
virtual BasePropertyPtr clone() =0
```

deep copy 

**Return**: BasePropertyPtr 克隆后的属性指针 

**Reimplemented by**: [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone), [zmesh::core::Property::clone](Classes/classzmesh_1_1core_1_1_property.md#function-clone)


### function name

```cpp
inline const std::string & name() const
```

获得属性的名字 

**Return**: const std::string& 属性的名字 

## Protected Attributes Documentation

### variable name_

```cpp
std::string name_;
```


属性的名字 


-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800