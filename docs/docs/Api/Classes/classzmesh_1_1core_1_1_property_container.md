---
title: zmesh::core::PropertyContainer
summary: 属性的容器, 可以包含多个容器 提供对属性的添加删除获取等操作 

---

# zmesh::core::PropertyContainer



属性的容器, 可以包含多个容器 提供对属性的添加删除获取等操作 


`#include <properties.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md#function-propertycontainer)**() =default |
| | **[~PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md#function-~propertycontainer)**() |
| | **[PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md#function-propertycontainer)**(const [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) & rhs) |
| [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) & | **[operator=](Classes/classzmesh_1_1core_1_1_property_container.md#function-operator=)**(const [PropertyContainer](Classes/classzmesh_1_1core_1_1_property_container.md) & rhs)<br>deep copy  |
| std::vector< std::string > | **[properties](Classes/classzmesh_1_1core_1_1_property_container.md#function-properties)**() const<br>返回所有属性的名字  |
| bool | **[exists](Classes/classzmesh_1_1core_1_1_property_container.md#function-exists)**(const std::string & name) const |
| template <typename T \> <br>[PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)< T > | **[add](Classes/classzmesh_1_1core_1_1_property_container.md#function-add)**(const std::string & name, const T default_value =T())<br>通过名字和默认值添加一个属性, 如果属性已经存在, 就抛出异常  |
| template <typename T \> <br>[PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)< T > | **[get](Classes/classzmesh_1_1core_1_1_property_container.md#function-get)**(const std::string & name) const<br>通过名字查找属性, 如果存在, 就返回该属性的Handle, 如果不存在, 就抛出异常  |
| template <typename T \> <br>[PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)< T > | **[get_or_add](Classes/classzmesh_1_1core_1_1_property_container.md#function-get-or-add)**(const std::string & name, const T default_value =T())<br>通过名字获取属性, 如果属性不存在, 就用参数给定的名字和默认值添加一个属性, 并返回属性的Handle  |
| template <typename T \> <br>void | **[remove](Classes/classzmesh_1_1core_1_1_property_container.md#function-remove)**([PropertyHandle](Classes/classzmesh_1_1core_1_1_property_handle.md)< T > & handle)<br>根据属性的Handle删除一个属性  |
| void | **[free_memory](Classes/classzmesh_1_1core_1_1_property_container.md#function-free-memory)**()<br>释放内存  |
| void | **[clear](Classes/classzmesh_1_1core_1_1_property_container.md#function-clear)**()<br>删除所有属性  |
| size_t | **[n_properties](Classes/classzmesh_1_1core_1_1_property_container.md#function-n-properties)**() const<br>返回这个容器里有多少个属性  |
| size_t | **[size](Classes/classzmesh_1_1core_1_1_property_container.md#function-size)**() const<br>返回每个属性的大小(所有属性都是一样大的)  |
| void | **[push_back](Classes/classzmesh_1_1core_1_1_property_container.md#function-push-back)**()<br>对所有属性添加一个元素  |
| void | **[resize](Classes/classzmesh_1_1core_1_1_property_container.md#function-resize)**(size_t n)<br>调整所有属性的大小  |
| void | **[reserve](Classes/classzmesh_1_1core_1_1_property_container.md#function-reserve)**(size_t n)<br>为属性预留空间  |

## Public Functions Documentation

### function PropertyContainer

```cpp
PropertyContainer() =default
```


### function ~PropertyContainer

```cpp
inline ~PropertyContainer()
```


### function PropertyContainer

```cpp
inline PropertyContainer(
    const PropertyContainer & rhs
)
```


### function operator=

```cpp
inline PropertyContainer & operator=(
    const PropertyContainer & rhs
)
```

deep copy 

### function properties

```cpp
inline std::vector< std::string > properties() const
```

返回所有属性的名字 

### function exists

```cpp
inline bool exists(
    const std::string & name
) const
```


### function add

```cpp
template <typename T >
inline PropertyHandle< T > add(
    const std::string & name,
    const T default_value =T()
)
```

通过名字和默认值添加一个属性, 如果属性已经存在, 就抛出异常 

### function get

```cpp
template <typename T >
inline PropertyHandle< T > get(
    const std::string & name
) const
```

通过名字查找属性, 如果存在, 就返回该属性的Handle, 如果不存在, 就抛出异常 

### function get_or_add

```cpp
template <typename T >
inline PropertyHandle< T > get_or_add(
    const std::string & name,
    const T default_value =T()
)
```

通过名字获取属性, 如果属性不存在, 就用参数给定的名字和默认值添加一个属性, 并返回属性的Handle 

### function remove

```cpp
template <typename T >
inline void remove(
    PropertyHandle< T > & handle
)
```

根据属性的Handle删除一个属性 

### function free_memory

```cpp
inline void free_memory()
```

释放内存 

### function clear

```cpp
inline void clear()
```

删除所有属性 

### function n_properties

```cpp
inline size_t n_properties() const
```

返回这个容器里有多少个属性 

### function size

```cpp
inline size_t size() const
```

返回每个属性的大小(所有属性都是一样大的) 

### function push_back

```cpp
inline void push_back()
```

对所有属性添加一个元素 

### function resize

```cpp
inline void resize(
    size_t n
)
```

调整所有属性的大小 

### function reserve

```cpp
inline void reserve(
    size_t n
)
```

为属性预留空间 

-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800