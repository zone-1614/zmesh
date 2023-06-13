#include <zmesh/gl/base_window.h>

#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <filesystem>

#include <spdlog/spdlog.h>
#define STBIW_WINDOWS_UTF8
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <zmesh/gl/mesh_window_builder.h>

namespace zmesh {
namespace gl {

BaseWindow::BaseWindow(int width, int height, const std::string& title)
    : width_(width), height_(height), title_(title) {
    // init glfw
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfw_window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
    if (glfw_window_ == nullptr) {
        spdlog::error("[BaseWindow] init glfw failed");
        glfwTerminate();
        throw std::runtime_error("init glfw failed");
    }
    glfwMakeContextCurrent(glfw_window_);
    glfwSetWindowUserPointer(glfw_window_, this);

    // init glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        spdlog::error("[BaseWindow] init glad failed");
        throw std::runtime_error("init glad failed");
    }

    // init opengl
    glViewport(0, 0, width_, height_);
    glEnable(GL_DEPTH_TEST);

    // init imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // imgui style
    ImGui::StyleColorsClassic();
    // ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(glfw_window_, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    init_callbacks();

    log_info();
}

void BaseWindow::run() {
    init_imgui_style();
    while (!glfwWindowShouldClose(glfw_window_)) {
        render();
    }
}

void BaseWindow::init_callbacks() {
    glfwSetKeyCallback(glfw_window_, BaseWindow::KeyCallback);
    glfwSetCharCallback(glfw_window_, BaseWindow::CharacterCallback);
    glfwSetCursorPosCallback(glfw_window_, BaseWindow::CursorPosCallback);
    glfwSetCursorEnterCallback(glfw_window_, BaseWindow::CursorEnterCallback);
    glfwSetMouseButtonCallback(glfw_window_, BaseWindow::MouseButtonCallback);
    glfwSetScrollCallback(glfw_window_, BaseWindow::ScrollCallback);
    glfwSetDropCallback(glfw_window_, BaseWindow::DropCallback);
    glfwSetFramebufferSizeCallback(glfw_window_, BaseWindow::FramebufferSizeCallback);
}

void BaseWindow::init_imgui_style() {
    // 抄来的style, 修改了一点点
    // https://github.com/ocornut/imgui/issues/707
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text] = ImVec4(0.31f, 0.25f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.74f, 0.74f, 0.94f, 1.00f);
    // style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.68f, 0.68f, 0.68f, 0.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.62f, 0.70f, 0.72f, 0.56f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.95f, 0.33f, 0.14f, 0.47f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.97f, 0.31f, 0.13f, 0.81f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.42f, 0.75f, 1.00f, 0.53f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.42f, 0.75f, 1.00f, 0.53f); // --- 我改的
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.65f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.40f, 0.62f, 0.80f, 0.15f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.39f, 0.64f, 0.80f, 0.30f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.28f, 0.67f, 0.80f, 0.59f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.25f, 0.48f, 0.53f, 0.67f);
    // style.Colors[ImGuiCol_ComboBg] = ImVec4(0.89f, 0.98f, 1.00f, 0.99f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.48f, 0.47f, 0.47f, 0.71f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.31f, 0.47f, 0.99f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.79f, 0.18f, 0.78f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.82f, 1.00f, 0.81f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.72f, 1.00f, 1.00f, 0.86f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.65f, 0.78f, 0.84f, 0.80f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.75f, 0.88f, 0.94f, 0.80f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.55f, 0.68f, 0.74f, 0.80f);//ImVec4(0.46f, 0.84f, 0.90f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.60f, 0.60f, 0.80f, 0.30f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
    // style.Colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.75f, 0.98f, 0.50f);
    // style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 0.47f, 0.41f, 0.60f);
    // style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.16f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.99f, 0.54f, 0.43f);
    // style.Colors[ImGuiCol_TooltipBg] = ImVec4(0.82f, 0.92f, 1.00f, 0.90f);
    style.Alpha = 1.0f;
    // style.WindowFillAlphaDefault = 1.0f;
    style.FrameRounding = 4;
    style.IndentSpacing = 12.0f;
}

void BaseWindow::log_info() const {
    std::stringstream log_info_ss;
    log_info_ss << glGetString(GL_VENDOR);
    spdlog::info("OpenGL Vendor: {}", log_info_ss.str());
    log_info_ss.str("");
    log_info_ss << glGetString(GL_RENDERER);
    spdlog::info("OpenGL Renderer: {}", log_info_ss.str());
    log_info_ss.str("");
    log_info_ss << glGetString(GL_VERSION);
    spdlog::info("OpenGL Version: {}", log_info_ss.str());
    log_info_ss.str("");
    log_info_ss << ImGui::GetVersion();
    spdlog::info("ImGui Version: {}", log_info_ss.str());
}

int BaseWindow::width() const {
    return width_;
}

int BaseWindow::height() const {
    return height_;
}

std::pair<int, int> BaseWindow::size() const {
    return {width_, height_};
}

std::pair<double, double> BaseWindow::cursor_pos() const {
    double x, y;
    glfwGetCursorPos(glfw_window_, &x, &y);
    return {x, y};
}

bool BaseWindow::left_shift_pressed() const {
    return left_shift_pressed_;
}

bool BaseWindow::left_ctrl_pressed() const {
    return left_ctrl_pressed_;
}

bool BaseWindow::left_alt_pressed() const {
    return left_alt_pressed_;
}

bool BaseWindow::right_shift_pressed() const {
    return right_shift_pressed_;
}

bool BaseWindow::right_ctrl_pressed() const {
    return right_ctrl_pressed_;
}

bool BaseWindow::right_alt_pressed() const {
    return right_alt_pressed_;
}

void BaseWindow::screenshot() {
    // 不存在则创建screenshot目录
    std::filesystem::create_directory("./screenshot");

    static int screenshot_number = 0;
    std::stringstream filename;
    filename << "./screenshot/" << title_ << "_" << screenshot_number++ << ".png";

    // allocate memory
    auto png_data = new unsigned char[3 * width_ * height_];

    // read the framebuffer
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, width_, height_, GL_RGB, GL_UNSIGNED_BYTE, png_data);

    // save the screen to png  (use stb image)
    glfwMakeContextCurrent(glfw_window_);
    stbi_flip_vertically_on_write(true);
    stbi_write_png(filename.str().c_str(), width_, height_, 3, png_data, 3 * width_);

    spdlog::info("Save screenshot to {}", filename.str().c_str());

    delete[] png_data;
}

void BaseWindow::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    // if (!ImGui::GetIO().WantCaptureKeyboard)
    switch (key) {
        case GLFW_KEY_LEFT_SHIFT:
            base_window->left_shift_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_CONTROL:
            base_window->left_ctrl_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_ALT:
            base_window->left_alt_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_RIGHT_SHIFT:
            base_window->right_shift_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_RIGHT_CONTROL:
            base_window->right_ctrl_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_RIGHT_ALT:
            base_window->right_alt_pressed_ = (action != GLFW_RELEASE);
            break;
    }
    base_window->key_callback(window, key, scancode, action, mods);
}

void BaseWindow::CharacterCallback(GLFWwindow* window, unsigned int codepoint) {
    ImGui_ImplGlfw_CharCallback(window, codepoint);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->character_callback(window, codepoint);
}

void BaseWindow::CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->cursor_pos_callback(window, xpos, xpos);
}

void BaseWindow::CursorEnterCallback(GLFWwindow* window, int entered) {
    ImGui_ImplGlfw_CursorEnterCallback(window, entered);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->cursor_enter_callback(window, entered);
}

void BaseWindow::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    // if (!ImGui::GetIO().WantCaptureMouse)
    base_window->button_pressed_[button] = (action == GLFW_PRESS);
    base_window->mouse_button_callback(window, button, action, mods);
}

void BaseWindow::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);

    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->scroll_callback(window, xoffset, yoffset);
}

void BaseWindow::DropCallback(GLFWwindow* window, int count, const char** paths) {
    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->drop_callback(window, count, paths);
}

void BaseWindow::FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    BaseWindow* base_window = static_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
    base_window->width_ = width;
    base_window->height_ = height;
    glViewport(0, 0, width, height);
    
    base_window->framebuffer_size_callback(window, width, height);
}

}
}