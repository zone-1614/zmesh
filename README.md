# ZMesh
ZMesh: 更适合中国宝宝体质的图形学框架

ZMesh目前只是一套数据结构, 后续会添加可视化之类的功能和一些几何处理算法

# 目录
* core: mesh数据结构
  * [x] Mesh
  * [x] Iterator
  * [x] Circulator
  * [x] SmartHandle
* io: 读写文件
  * [x] ObjReader
  * [ ] ObjWriter
  * [ ] OffReader 
  * [ ] OffWriter
  * [ ] 其他3D文件的 Reader 和 Writer
* gl: OpenGL相关
  * [x] Mesh可视化
  * UI
    * [x] log
    * [ ] file
    * [x] 将mesh渲染在imgui中
* algo: 算法相关
  * [x] 顶点法向
  * [x] 面法向

# 参考
[OpenMesh](https://www.graphics.rwth-aachen.de/software/openmesh/): 非常好用的网格库

[pmp-library](https://www.pmp-library.org/): 我喜欢用的几何库

[peridyno](https://www.peridyno.com/): GAMES401讲的软件