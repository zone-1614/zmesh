---
title: zmesh::io::io_options
summary: 用来控制是否读/写顶点法向, 顶点纹理坐标, 顶点颜色等等 这个类暂时没啥用 

---

# zmesh::io::io_options



用来控制是否读/写顶点法向, 顶点纹理坐标, 顶点颜色等等 这个类暂时没啥用 


`#include <io_options.h>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| bool | **[vertex_normal](Classes/structzmesh_1_1io_1_1io__options.md#variable-vertex-normal)** <br>是否读/写顶点法向  |
| bool | **[vertex_texture_coord](Classes/structzmesh_1_1io_1_1io__options.md#variable-vertex-texture-coord)** <br>是否读/写顶点纹理坐标  |
| bool | **[vertex_color](Classes/structzmesh_1_1io_1_1io__options.md#variable-vertex-color)** <br>是否读/写顶点颜色  |
| bool | **[face_normal](Classes/structzmesh_1_1io_1_1io__options.md#variable-face-normal)** <br>是否读/写面的法向  |
| bool | **[face_color](Classes/structzmesh_1_1io_1_1io__options.md#variable-face-color)** <br>是否读/写面的颜色  |

## Public Attributes Documentation

### variable vertex_normal

```cpp
bool vertex_normal {false};
```

是否读/写顶点法向 

### variable vertex_texture_coord

```cpp
bool vertex_texture_coord {false};
```

是否读/写顶点纹理坐标 

### variable vertex_color

```cpp
bool vertex_color {false};
```

是否读/写顶点颜色 

### variable face_normal

```cpp
bool face_normal {false};
```

是否读/写面的法向 

### variable face_color

```cpp
bool face_color {false};
```

是否读/写面的颜色 

-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800