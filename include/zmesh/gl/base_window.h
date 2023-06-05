/**
 * @file base_window.h
 * @author zone-1614 (you@domain.com)
 * @brief 窗口的基类
 * @version 0.1
 * @date 2023-05-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <zmesh/gl/callbacks.h>

namespace zmesh {
namespace gl {

//! @class BaseWindow
//! @brief 窗口的基类
class BaseWindow {
public: 
    //! 构造函数
    BaseWindow(int width, int height, const std::string& title = "");
    virtual ~BaseWindow() {}
    void run();

protected:
    virtual void render() = 0;

    virtual void init_callbacks();

    virtual void init_imgui_style();

public:
    //! get the width of window
    int width() const;

    //! get the height of window
    int height() const;

    //! get the position of cursor
    std::pair<double, double> cursor_pos() const;

    //! press left shift?
    bool left_shift_pressed() const;

    //! press left ctrl?
    bool left_ctrl_pressed() const;

    //! press left alt?
    bool left_alt_pressed() const;
    
    //! press right shift?
    bool right_shift_pressed() const;

    //! press right ctrl?
    bool right_ctrl_pressed() const;

    //! press right alt?
    bool right_alt_pressed() const;

    //! 截图
    void screenshot();

protected:
    // callback function pointers
    KeyCallback key_callback_;

    CharacterCallback character_callback_;

    CursorPosCallback cursor_pos_callback_;

    CursorEnterCallback cursor_enter_callback_;

    MouseButtonCallback mouse_button_callback_;

    ScrollCallback scroll_callback_;

    DropCallback drop_callback_;

    FramebufferSizeCallback framebuffer_size_callback_;

    // callback functions
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void character_callback(GLFWwindow* window, unsigned int codepoint);

    static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    static void cursor_enter_callback(GLFWwindow* window, int entered);

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    static void drop_callback(GLFWwindow* window, int count, const char** paths);

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

protected:
    int width_;
    int height_;
    std::string title_;
    GLFWwindow* glfw_window_;

    // 是否按下按键
    bool left_shift_pressed_{false};
    bool left_ctrl_pressed_{false};
    bool left_alt_pressed_{false};
    bool right_shift_pressed_{false};
    bool right_ctrl_pressed_{false};
    bool right_alt_pressed_{false};
};

}
}