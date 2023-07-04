/**
 * @file mesh_window.h
 * @author zone-1614 (you@domain.com)
 * @brief 可视化mesh
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <array>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <zmesh/gl/shader.h>
#include <zmesh/gl/trackball_camera.h>
#include <zmesh/core/mesh.h>
#include <zmesh/gl/log_window.h>

namespace zmesh {
namespace gl {

//! 绘画模式
struct DrawMode {
    static const int Points = 1; //! 点云
    static const int WireFrame = 1 << 1; //! 线框
    static const int PhongShading = 1 << 2; //! phong shading
};

class MeshWindow {
public:
    MeshWindow(
        int width, 
        int height, 
        std::string title, 
        std::filesystem::path mesh_path
    );
    ~MeshWindow();

    void run();

    MeshWindow& set_width(int width) { 
        width_ = width; 
        return *this;
    }

    MeshWindow& set_height(int height) { 
        height_ = height; 
        return *this; 
    }

    MeshWindow& set_title(std::string title) { 
        title_ = title; 
        return *this; 
    }

    //! 设置绘画模式, 用法: window.set_draw_mode(DrawMode::Points | DrawMode::PhongShading);
    MeshWindow& set_draw_mode(int draw_mode) { 
        draw_mode_ = draw_mode; 
        return *this; 
    }

protected:
    // key
    //! 是否按下左边shift键
    bool left_shift_pressed() { return left_shift_pressed_; }

    //! 是否按下左边ctrl键
    bool left_ctrl_pressed() { return left_ctrl_pressed_; }

    //! 是否按下左边alt键
    bool left_alt_pressed() { return left_alt_pressed_; }

    // mouse
    //! 是否按下鼠标左键
    bool left_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_LEFT]; }
    
    //! 是否按下鼠标中键
    bool middle_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_MIDDLE]; }

    //! 是否按下鼠标右键
    bool right_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_RIGHT]; }

    //! 初始化imgui的样式
    void init_imgui_style();

    //! 截图,
    //! 在imgui的button中直接执行并不会截图, 需要有一点特殊的处理, 在opengl画完东西之后再截图, 借助辅助变量 screenshot_
    void screenshot();

    //! 鼠标位置, 范围是 [0, width], [0, height], 左上角为 (0, 0)
    std::pair<double, double> cursor_pos() {
        double x, y;
        glfwGetCursorPos(glfw_window_, &x, &y);
        return {x, y};
    }

    //! 从文件目录加载mesh
    void load_mesh(std::filesystem::path mesh_path);
    
private:
    void mainloop();

    // callback functions
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

private:
    // 窗口属性
    int width_;
    int height_;
    std::string title_;
    GLFWwindow* glfw_window_;

    // 键盘相关, 相关的GLFW宏定义为: GLFW_KEY_LEFT_SHIFT, ...
    bool left_shift_pressed_{false};
    bool left_ctrl_pressed_{false};
    bool left_alt_pressed_{false};

    // 鼠标相关, 具体可以查看GLFW的以下几个宏定义
    /*
    #define GLFW_MOUSE_BUTTON_1         0
    #define GLFW_MOUSE_BUTTON_2         1
    #define GLFW_MOUSE_BUTTON_3         2
    #define GLFW_MOUSE_BUTTON_4         3
    #define GLFW_MOUSE_BUTTON_5         4
    #define GLFW_MOUSE_BUTTON_6         5
    #define GLFW_MOUSE_BUTTON_7         6
    #define GLFW_MOUSE_BUTTON_8         7
    #define GLFW_MOUSE_BUTTON_LAST      GLFW_MOUSE_BUTTON_8
    #define GLFW_MOUSE_BUTTON_LEFT      GLFW_MOUSE_BUTTON_1
    #define GLFW_MOUSE_BUTTON_RIGHT     GLFW_MOUSE_BUTTON_2
    #define GLFW_MOUSE_BUTTON_MIDDLE    GLFW_MOUSE_BUTTON_3
    */
    std::array<bool, 8> mouse_button_pressed_{false};

    core::Mesh mesh_;

    // shader使用智能指针是因为创建shader之前需要初始化glad之类的, 而shader又不提供默认构造
    // camera其实不需要用智能指针, 只是为了形式和shader看起来一样
    bool enable_trackball_{false}; //!< 是否开启trackball
    std::shared_ptr<TrackballCamera> camera_;

    // shader相关
    std::shared_ptr<Shader> shader_;
    float ambient_{0.1f};
    float diffuse_{0.9f};
    float specular_{0.8f};
    glm::vec3 light_color_{1.0f, 1.0f, 1.0f};
    glm::vec3 object_color_{0.439f, 0.337f, 0.592f}; // rgb: 112, 86, 151

    // opengl 相关
    unsigned int vao_; //!< vertex array object
    unsigned int vertex_buffer_; //!< 顶点坐标
    unsigned int febo_; //!< face element buffer object 
    unsigned int eebo_; //!< edge element buffer object 

    unsigned int normal_buffer_; //!< 顶点法向, 也是一个vbo

    float point_size_{6.0f}; //!< OpenGL的点大小, 建议在 5.0 到 8.0之间

    int draw_mode_{DrawMode::Points | DrawMode::WireFrame | DrawMode::PhongShading};

    // helpers for draw mesh on imgui
    unsigned int fbo_; //!< framebuffer object
    unsigned int scene_texture_; //!< 网格场景的纹理, 用于把网格画到imgui中
    unsigned int rbo_; //!< render buffer object

    // ui
    std::vector<std::filesystem::path> models_; //!< models 文件夹下面的obj文件

    LogWindow log_window_;

    bool enable_screenshot_{false}; //!< 截图的辅助变量
    bool is_hover_mesh_{false}; //!< 鼠标是否悬浮在mesh窗口上
};

}
}