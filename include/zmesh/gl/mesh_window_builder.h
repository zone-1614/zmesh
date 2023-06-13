#pragma once

#include <filesystem>
#include <memory>

#include <zmesh/gl/mesh_window.h>

namespace zmesh {
namespace gl {

class MeshWindowBuilder {
public:
    MeshWindowBuilder();

    MeshWindowBuilder& width(int w);

    MeshWindowBuilder& height(int h);

    MeshWindowBuilder& maximize();

    MeshWindowBuilder& title(const std::string& t);

    MeshWindowBuilder& mesh(const std::filesystem::path& path);

    MeshWindowBuilder& mesh(const std::string& path);

    MeshWindowBuilder& draw_mode(DrawMode mode);

    //! 添加一个 shader
    //! @param name shader的名字
    //! @param vpath vertex shader的路径
    //! @param fpath fragment shader的路径
    MeshWindowBuilder& shader(
        const std::string& name, 
        const std::filesystem::path& vpath, 
        const std::filesystem::path& fpath
    );

    //! 添加一个 shader
    //! @param name shader的名字
    //! @param vpath vertex shader的路径
    //! @param fpath fragment shader的路径
    MeshWindowBuilder& shader(
        const std::string& name, 
        const std::string& vpath, 
        const std::string& fpath
    );

    //! 返回mesh window的 unique pointer
    std::unique_ptr<MeshWindow> pointer();

private:
    // 使用unique pointer是因为 opengl 和 imgui 的初始化需要用到一些指针, 把window创建在栈上不方便
    std::unique_ptr<MeshWindow> mesh_window_ptr_;
};

}
}