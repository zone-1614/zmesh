#pragma once

namespace zmesh {
namespace io {

//! @class io_options
//! @brief 用来控制是否读/写顶点法向, 顶点纹理坐标, 顶点颜色等等
//! 这个类暂时没啥用
struct io_options {
    bool vertex_normal{false}; //!< 是否读/写顶点法向
    bool vertex_texture_coord{false}; //!< 是否读/写顶点纹理坐标
    bool vertex_color{false}; //!< 是否读/写顶点颜色
    bool face_normal{false}; //!< 是否读/写面的法向
    bool face_color{false}; //!< 是否读/写面的颜色
};

}
}