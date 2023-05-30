---
title: zmesh::io::ObjReader
summary: 从obj文件读入网格 

---

# zmesh::io::ObjReader



从obj文件读入网格 


`#include <obj_reader.h>`

Inherits from [zmesh::io::BaseReader](Classes/classzmesh_1_1io_1_1_base_reader.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[read](Classes/classzmesh_1_1io_1_1_obj_reader.md#function-read)**([Mesh](Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file, const [io_options](Classes/structzmesh_1_1io_1_1io__options.md) & options)<br>根据io选项, 从文件读入网格  |
| virtual std::string | **[extension](Classes/classzmesh_1_1io_1_1_obj_reader.md#function-extension)**() const<br>返回文件拓展名  |

## Public Functions Documentation

### function read

```cpp
inline virtual bool read(
    Mesh & mesh,
    const std::filesystem::path & file,
    const io_options & options
)
```

根据io选项, 从文件读入网格 

**Parameters**: 

  * **输出网格** 
  * **输入文件** 
  * **io选项** 


**Reimplements**: [zmesh::io::BaseReader::read](Classes/classzmesh_1_1io_1_1_base_reader.md#function-read)


### function extension

```cpp
inline virtual std::string extension() const
```

返回文件拓展名 

**Reimplements**: [zmesh::io::BaseReader::extension](Classes/classzmesh_1_1io_1_1_base_reader.md#function-extension)


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800