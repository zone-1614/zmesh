---
title: zmesh::io

---

# zmesh::io



## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[zmesh::io::BaseReader](../Classes/classzmesh_1_1io_1_1_base_reader.md)** <br>所有Reader的基类  |
| class | **[zmesh::io::io_options](../Classes/structzmesh_1_1io_1_1io__options.md)** <br>用来控制是否读/写顶点法向, 顶点纹理坐标, 顶点颜色等等 这个类暂时没啥用  |
| class | **[zmesh::io::ObjReader](../Classes/classzmesh_1_1io_1_1_obj_reader.md)** <br>从obj文件读入网格  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[trim](Namespaces/namespacezmesh_1_1io.md#function-trim)**(std::string & str)<br>类似java里面的trim, 去掉字符串前面后面的空白字符  |
| bool | **[read](Namespaces/namespacezmesh_1_1io.md#function-read)**([Mesh](../Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file) |
| bool | **[read](Namespaces/namespacezmesh_1_1io.md#function-read)**([Mesh](../Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file, const [io_options](../Classes/structzmesh_1_1io_1_1io__options.md) & options) |
| void | **[write](Namespaces/namespacezmesh_1_1io.md#function-write)**([Mesh](../Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file) |
| void | **[write](Namespaces/namespacezmesh_1_1io.md#function-write)**([Mesh](../Classes/classzmesh_1_1core_1_1_mesh.md) & mesh, const std::filesystem::path & file, const [io_options](../Classes/structzmesh_1_1io_1_1io__options.md) & options) |


## Functions Documentation

### function trim

```cpp
void trim(
    std::string & str
)
```

类似java里面的trim, 去掉字符串前面后面的空白字符 

### function read

```cpp
bool read(
    Mesh & mesh,
    const std::filesystem::path & file
)
```


**Parameters**: 

  * **mesh** 输出网格 
  * **file** 输入文件 


**Return**: 读取是否成功 

### function read

```cpp
bool read(
    Mesh & mesh,
    const std::filesystem::path & file,
    const io_options & options
)
```


**Parameters**: 

  * **mesh** 输出网格 
  * **file** 输入文件 
  * **options** io选项 


**Return**: 读取是否成功 

### function write

```cpp
void write(
    Mesh & mesh,
    const std::filesystem::path & file
)
```


**Parameters**: 

  * **mesh** 输入网格 
  * **file** 写入文件 


**Return**: 写入是否成功 

### function write

```cpp
void write(
    Mesh & mesh,
    const std::filesystem::path & file,
    const io_options & options
)
```


**Parameters**: 

  * **mesh** 输入网格 
  * **file** 写入文件 
  * **options** io选项 


**Return**: 写入是否成功 





-------------------------------

Updated on 2023-05-30 at 09:04:12 +0800