#pragma once

#include <filesystem>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>

#include <zmesh/core/mesh.h>
#include <zmesh/gl/base_window.h>

namespace zmesh {
namespace gl {

using zmesh::core::Mesh;

class MeshWindowBuilder;

enum class DrawMode {
    Points, /* 点云 */
    Wireframe, /* 线框 */
    PhongShading, /*  */
    PhongShadingWithWireframe, /* phong shading 加上线框 */
    Texture /* 纹理 */
};

class MeshWindow : public BaseWindow {
public:
    friend class MeshWindowBuilder;
    static MeshWindowBuilder create();

// private:
    //! private constructor, 用builder去创建 mesh window
    MeshWindow(int width, int height, const std::string& title);

public:
    virtual ~MeshWindow();

    MeshWindow& operator=(const MeshWindow& rhs) {
        this->glfw_window_ = rhs.glfw_window_;
        this->mesh_ = rhs.mesh_;
        
        ImGui_ImplGlfw_InitForOpenGL(glfw_window_, true);
        glfwSetWindowUserPointer(glfw_window_, this);
        glfwMakeContextCurrent(glfw_window_);
    }
    //! load mesh from obj
    void load_mesh(const std::filesystem::path& path);

    //! save mesh to obj
    //! @param filename 文件名字, 不需要后缀, 目前只会保存为obj文件
    //! 默认保存到 ./models 目录下
    void save_mesh(const std::string& filename);

    virtual void render() override;

protected:
    void begin_frame();
    void draw_ui();
    void draw_mesh();
    void end_frame();

protected:
    Mesh mesh_;
};

}
}