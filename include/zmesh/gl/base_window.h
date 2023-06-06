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
#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

    virtual void init_imgui_style();

    void log_info() const;

private:
    void init_callbacks();

public:
    //! get the width of window
    int width() const;

    //! get the height of window
    int height() const;

    //! get the size of window
    std::pair<int, int> size() const;

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
    // callback functions
    virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {}

    virtual void character_callback(GLFWwindow* window, unsigned int codepoint) {}

    virtual void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {}

    virtual void cursor_enter_callback(GLFWwindow* window, int entered) {}

    virtual void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {}

    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {}

    virtual void drop_callback(GLFWwindow* window, int count, const char** paths) {}

    virtual void framebuffer_size_callback(GLFWwindow* window, int width, int height) {}

    // static callback functions
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    static void CharacterCallback(GLFWwindow* window, unsigned int codepoint);

    static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);

    static void CursorEnterCallback(GLFWwindow* window, int entered);

    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    static void DropCallback(GLFWwindow* window, int count, const char** paths);

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

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

    // 是否按下鼠标
    std::array<bool, 8> button_pressed_{false};
};

}
}