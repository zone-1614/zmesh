---
title: zmesh::core::BaseIterator
summary: 所有迭代器的基类 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标 

---

# zmesh::core::BaseIterator



所有迭代器的基类 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标  [More...](#detailed-description)


`#include <iterators.h>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::bidirectional_iterator_tag | **[iterator_category](Classes/classzmesh_1_1core_1_1_base_iterator.md#using-iterator-category)**  |
| using const HandleType & | **[reference](Classes/classzmesh_1_1core_1_1_base_iterator.md#using-reference)**  |
| using const HandleType * | **[pointer](Classes/classzmesh_1_1core_1_1_base_iterator.md#using-pointer)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-baseiterator)**() =default |
| | **[BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-baseiterator)**(HandleType handle) |
| [reference](Classes/classzmesh_1_1core_1_1_base_iterator.md#using-reference) | **[operator*](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator*)**() const |
| [pointer](Classes/classzmesh_1_1core_1_1_base_iterator.md#using-pointer) | **[operator->](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator->)**() const |
| bool | **[operator==](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator==)**(const [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) & rhs) const |
| bool | **[operator!=](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator!=)**(const [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) & rhs) const |
| [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) & | **[operator++](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator++)**() |
| [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) | **[operator++](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator++)**(int ) |
| [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) & | **[operator--](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator--)**() |
| [BaseIterator](Classes/classzmesh_1_1core_1_1_base_iterator.md) | **[operator--](Classes/classzmesh_1_1core_1_1_base_iterator.md#function-operator--)**(int ) |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| HandleType | **[handle_](Classes/classzmesh_1_1core_1_1_base_iterator.md#variable-handle-)** <br>迭代器所拥有的Handle  |

## Detailed Description

```cpp
template <typename HandleType >
class zmesh::core::BaseIterator;
```

所有迭代器的基类 因为Handle表现起来就像数组的下标, 所以迭代器的递增递减就只是增加减少对应Handle的下标 
## Public Types Documentation

### using iterator_category

```cpp
using zmesh::core::BaseIterator< HandleType >::iterator_category =  std::bidirectional_iterator_tag;
```


### using reference

```cpp
using zmesh::core::BaseIterator< HandleType >::reference =  const HandleType&;
```


### using pointer

```cpp
using zmesh::core::BaseIterator< HandleType >::pointer =  const HandleType*;
```


## Public Functions Documentation

### function BaseIterator

```cpp
BaseIterator() =default
```


### function BaseIterator

```cpp
inline BaseIterator(
    HandleType handle
)
```


### function operator*

```cpp
inline reference operator*() const
```


### function operator->

```cpp
inline pointer operator->() const
```


### function operator==

```cpp
inline bool operator==(
    const BaseIterator & rhs
) const
```


### function operator!=

```cpp
inline bool operator!=(
    const BaseIterator & rhs
) const
```


### function operator++

```cpp
inline BaseIterator & operator++()
```


### function operator++

```cpp
inline BaseIterator operator++(
    int 
)
```


### function operator--

```cpp
inline BaseIterator & operator--()
```


### function operator--

```cpp
inline BaseIterator operator--(
    int 
)
```


## Protected Attributes Documentation

### variable handle_

```cpp
HandleType handle_;
```

迭代器所拥有的Handle 

-------------------------------

Updated on 2023-05-27 at 20:04:06 +0800