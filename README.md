# ZMesh
ZMesh是一套的网格数据结构, 带有一些几何处理算法的实现和文件io功能

# 目录
* core: mesh数据结构
* io: 读写文件
* algo: 算法相关

# 更新说明
之前在这个仓库中有一个可视化功能的实现, 本次更新将相关部分删除了. 原因如下
* 在设计之初, 这个仓库就是为了写一个网格库, 没有可视化的打算, 可视化只是为了看看效果是否正确
* 之前的可视化用的是OpenGL和ImGui之类的技术, 而ImGui的功能贫瘠, 中文资料稀少, 比较难开发, 之后应该会用Qt开发一个可视化

# 参考
[OpenMesh](https://www.graphics.rwth-aachen.de/software/openmesh/): 非常好用的网格库

[pmp-library](https://www.pmp-library.org/): 我喜欢用的几何库

[peridyno](https://www.peridyno.com/): GAMES401讲的软件