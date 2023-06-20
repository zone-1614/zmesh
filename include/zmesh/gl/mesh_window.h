#pragma once

#include <filesystem>
#include <memory>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>

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

    void update_mesh();

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
    // imgui 的参数 (在mesh window里才有imgui的参数而不是在base window里, 
    // 这样设计是因为我觉得以后可能继承base window去做别的事, 而不需要加载一个文件)
    bool p_open_{true};
    bool show_{true};

    char save_filename_[100] = "";
    std::string current_filename_{"no file"};

    // open gl
    unsigned int vbo_{0};
    unsigned int ebo_{0};
    unsigned int vao_{0};
    unsigned int vertex_normal_buffer_{0};
    unsigned int tex_coord_buffer_{0};
    unsigned int texture_{0};


    // log system
    LogSystem log_system_{};

    // 可选的shader
    // TODO: 默认有几个shader, 用户可以通过builder的shader函数添加
    std::vector<std::shared_ptr<Shader>> shaders_;
    std::shared_ptr<Shader> current_shader_;

    float point_size_{5.0f}; // 用于画点云的点大小
    float ambient_{0.1f};
    float diffuse_{0.8f};
    float specular_{0.6f};
    glm::vec3 light_pos_{1.0f, 1.0f, 1.0f};
    glm::vec3 light_color_{1.0f, 1.0f, 1.0f};
    glm::vec3 object_color_{0.3f, 0.4f, 0.7f};
    glm::vec3 view_pos_{1.0f, 0.0f, 0.0f};

};

}
}