#include <zmesh/gl/base_window.h>

#include <sstream>
#include <stdexcept>
#include <chrono>
#include <iomanip>
#include <algorithm>

#include <spdlog/spdlog.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

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

    // spdlog::info("OpenGL Version: {}", glGetString(GL_VERSION));

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

    // spdlog::info("ImGui Version: {}", ImGui::GetVersion());
}

void BaseWindow::run() {
    while (!glfwWindowShouldClose(glfw_window_)) {
        render();
    }
}

void BaseWindow::init_callbacks() {
    key_callback_ = BaseWindow::key_callback;
    character_callback_ = BaseWindow::character_callback;
    cursor_pos_callback_ = BaseWindow::cursor_pos_callback;
    cursor_enter_callback_ = BaseWindow::cursor_enter_callback;
    mouse_button_callback_ = BaseWindow::mouse_button_callback;
    scroll_callback_ = BaseWindow::scroll_callback;
    drop_callback_ = BaseWindow::drop_callback;
    framebuffer_size_callback_ = BaseWindow::framebuffer_size_callback;

    glfwSetKeyCallback(glfw_window_, key_callback_);
    glfwSetCharCallback(glfw_window_, character_callback_);
    glfwSetCursorPosCallback(glfw_window_, cursor_pos_callback_);
    glfwSetCursorEnterCallback(glfw_window_, cursor_enter_callback_);
    glfwSetMouseButtonCallback(glfw_window_, mouse_button_callback_);
    glfwSetScrollCallback(glfw_window_, scroll_callback_);
    glfwSetDropCallback(glfw_window_, drop_callback_);
    glfwSetFramebufferSizeCallback(glfw_window_, framebuffer_size_callback_);
}

void BaseWindow::init_imgui_style() {
    // custom imgui style
    ImGuiStyle& style = ImGui::GetStyle();
    
}

int BaseWindow::width() const {
    return width_;
}

int BaseWindow::height() const {
    return height_;
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
    std::stringstream filename;
    filename << "./screenshot/" << title_ << "  ";
    // add time to the end of filename
    const auto now = std::chrono::system_clock::now();
    const auto t = std::chrono::system_clock::to_time_t(now);
    filename << std::put_time(std::localtime(&t), "%Y-%m-%d %X") << ".png";
    std::string fname = filename.str();
    // replace the space to _
    std::replace(fname.begin(), fname.end(), ' ', '_');

    // allocate
    auto png_data = new unsigned char[3 * width_ * height_];

    // read the framebuffer
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, width_, height_, GL_RGB, GL_UNSIGNED_BYTE, png_data);

    // save the screen to png  (use stb image)
    stbi_flip_vertically_on_write(true);
    stbi_write_png(fname.c_str(), width_, height_, 3, png_data, 3 * width_);

    delete[] png_data;
}

void BaseWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

void BaseWindow::character_callback(GLFWwindow* window, unsigned int codepoint) {

}

void BaseWindow::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {

}

void BaseWindow::cursor_enter_callback(GLFWwindow* window, int entered) {

}

void BaseWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

}

void BaseWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {

}

void BaseWindow::drop_callback(GLFWwindow* window, int count, const char** paths) {

}

void BaseWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    
}

}
}