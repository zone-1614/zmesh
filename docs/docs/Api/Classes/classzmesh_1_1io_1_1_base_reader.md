---
title: zmesh::io::BaseReader
summary: 所有Reader的基类 

---

# zmesh::io::BaseReader



所有Reader的基类 


`#include <base_reader.h>`

Inherited by [zmesh::io::ObjReader](Classes/classzmesh_1_1io_1_1_obj_reader.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[read](Classes/classzmesh_1_1io_1_1_base_reader.md#function-read)**([Mesh](Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file, const [io_options](Classes/structzmesh_1_1io_1_1io__options.md) & options) =0<br>根据io选项, 从文件读入网格  |
| virtual std::string | **[extension](Classes/classzmesh_1_1io_1_1_base_reader.md#function-extension)**() const =0<br>返回文件拓展名  |

## Public Functions Documentation

### function read

```cpp
virtual bool read(
    Mesh & mesh,
    const std::filesystem::path & file,
    const io_options & options
) =0
```

根据io选项, 从文件读入网格 

**Parameters**: 

  * **输出网格** 
  * **输入文件** 
  * **io选项** 


**Reimplemented by**: [zmesh::io::ObjReader::read](Classes/classzmesh_1_1io_1_1_obj_reader.md#function-read)


### function extension

```cpp
virtual std::string extension() const =0
```

返回文件拓展名 

**Reimplemented by**: [zmesh::io::ObjReader::extension](Classes/classzmesh_1_1io_1_1_obj_reader.md#function-extension)


-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800