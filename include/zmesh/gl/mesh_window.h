#pragma once

#include <string>
#include <vector>
#include <memory>
#include <array>
#include <filesystem>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <zmesh/gl/shader.h>
#include <zmesh/gl/trackball_camera.h>
#include <zmesh/core/mesh.h>

namespace zmesh {
namespace gl {

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

protected:
    // key
    bool left_shift_pressed() { return left_shift_pressed_; }

    bool left_ctrl_pressed() { return left_ctrl_pressed_; }

    bool left_alt_pressed() { return left_alt_pressed_; }

    // mouse
    bool left_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_LEFT]; }

    bool middle_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_MIDDLE]; }

    bool right_mouse_button_pressed() { return mouse_button_pressed_[GLFW_MOUSE_BUTTON_RIGHT]; }

    void screenshot();

    //! 鼠标位置, 范围是 [0, width], [0, height], 左上角为 (0, 0)
    std::pair<double, double> cursor_pos() {
        double x, y;
        glfwGetCursorPos(glfw_window_, &x, &y);
        return {x, y};
    }

    
private:
    // void init();
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

    // std::vector<Shader> shaders_;
    std::shared_ptr<Shader> shader_;
    // shader使用智能指针是因为创建shader之前需要初始化glad之类的, 而shader又不提供默认构造
    // camera其实不需要用智能指针, 只是为了长的像
    bool enable_trackball_{false}; //!< 是否开启trackball
    std::shared_ptr<TrackballCamera> camera_;

    unsigned int VAO;
};

}
}