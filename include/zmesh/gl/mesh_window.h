#pragma once

#include <filesystem>
#include <memory>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>

#include <zmesh/core/mesh.h>
#include <zmesh/gl/base_window.h>
#include <zmesh/gl/log_system.h>
#include <zmesh/gl/shader.h>

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
    void render_ui();
    void render_mesh();
    void end_frame();

private:
    void init_shader();
//     void add_shader(std::shared_ptr<Shader> shader_ptr);

protected:
    Mesh mesh_;

private:
    // imgui
    bool p_open_{true};
    bool show_{true};

    char save_filename_[100] = "";
    std::string current_filename_{"no file"};

    // open gl
    unsigned int vbo_;
    unsigned int ebo_;
    unsigned int vao_;
    unsigned int texture;

    // log system
    LogSystem log_system_{};

    // 可选的shader
    // TODO: 默认有几个shader, 用户可以通过builder的shader函数添加
    std::vector<std::shared_ptr<Shader>> shaders_;
};

}
}