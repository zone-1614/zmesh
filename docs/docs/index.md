# ZMesh
ZMesh: 更适合中国宝宝体质的图形学框架

ZMesh目前只是一套数据结构, 后续会添加可视化之类的功能和一些几何处理算法.

## 目标
提供一套容易上手的图形学框架, 方便初学者实现自己的想法, 而不用花时间去学OpenGL

## 教程
TODO 这里应该有一个用cmake构建的教程

TODO 这里应该有一个visual studio工程, 直接就能跑起来的那种, 让初学者不用学cmake或者搭建环境等

TODO 应该搞一个把所有依赖添加为submodule的cmake工程, 就不用自己下载包了

## 参考
实现过程主要参考了[OpenMesh](https://www.graphics.rwth-aachen.de/software/openmesh/)和[pmp-library](https://www.pmp-library.org/). 

ZMesh与OpenMesh的区别是: OpenMesh是一套通用的模板库, 而ZMesh只是为了方便初学者实现图形学相关算法设计的框架. 

ZMesh与pmp的区别是: ZMesh实现了SmartHandle, 代码可读性更高. 