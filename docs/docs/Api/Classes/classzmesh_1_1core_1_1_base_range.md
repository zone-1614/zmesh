---
title: zmesh::core::BaseRange
summary: 通过Range可以方便使用c++11的 range-based for 语句 

---

# zmesh::core::BaseRange



通过Range可以方便使用c++11的 range-based for 语句  [More...](#detailed-description)


`#include <iterators.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BaseRange](Classes/classzmesh_1_1core_1_1_base_range.md#function-baserange)**(IteratorType begin, IteratorType end) |
| IteratorType | **[begin](Classes/classzmesh_1_1core_1_1_base_range.md#function-begin)**() const |
| IteratorType | **[end](Classes/classzmesh_1_1core_1_1_base_range.md#function-end)**() const |

## Detailed Description

```cpp
template <typename IteratorType >
class zmesh::core::BaseRange;
```

通过Range可以方便使用c++11的 range-based for 语句 
## Public Functions Documentation

### function BaseRange

```cpp
inline BaseRange(
    IteratorType begin,
    IteratorType end
)
```


### function begin

```cpp
inline IteratorType begin() const
```


### function end

```cpp
inline IteratorType end() const
```


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800