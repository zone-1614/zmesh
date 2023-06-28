#include <zmesh/gl/mesh_window.h>

#include <zmesh/algo/bbox.h>

#include <exception>

#include <spdlog/spdlog.h>

#include <zmesh/io/io.h>

namespace zmesh {
namespace gl {

MeshWindow::MeshWindow(
    int width, 
    int height, 
    std::string title, 
    std::filesystem::path mesh_path
) : width_(width), height_(height), title_(title) {

    io::read(mesh_, mesh_path);

    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfw_window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (glfw_window_ == nullptr) {
        glfwTerminate();
        throw std::runtime_error("GLFW init failed");
    }
    glfwMakeContextCurrent(glfw_window_);
    glfwSetWindowUserPointer(glfw_window_, this); // 构造函数执行完毕之前暴露this指针不安全, 有没有更好的做法?
    // init callbacks
    glfwSetFramebufferSizeCallback(glfw_window_, MeshWindow::framebuffer_size_callback);
    glfwSetKeyCallback(glfw_window_, MeshWindow::key_callback);
    glfwSetCursorPosCallback(glfw_window_, MeshWindow::cursor_pos_callback);
    glfwSetMouseButtonCallback(glfw_window_, MeshWindow::mouse_button_callback);
    glfwSetScrollCallback(glfw_window_, MeshWindow::scroll_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("glad init failed");
    }
    
    shader_ = std::make_shared<Shader>(
        std::filesystem::path("./shaders/phong.vert"),
        std::filesystem::path("./shaders/phong.frag")
    );

    // 利用bbox计算一开始相机的位置
    auto [_, bbmax] = algo::bounding_box(mesh_);
    auto radius = std::max({ bbmax[0], bbmax[1], bbmax[2] }) * 3.0f; // 数值为最大的一个坐标乘以3
    camera_ = std::make_shared<TrackballCamera>(glm::vec3(0, 0, radius));
    camera_->set_width(width);
    camera_->set_height(height);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    auto vertices = mesh_.points();
    std::vector<unsigned int> indices;
    indices.reserve(mesh_.n_faces() * 3);
    for (auto f : mesh_.faces()) {
        for (auto v : f.vertices()) {
            indices.push_back(v.idx());
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

MeshWindow::~MeshWindow() {
    glfwTerminate();
}

void MeshWindow::run() {
    while (!glfwWindowShouldClose(glfw_window_)) {
        mainloop();
    }
}

void MeshWindow::mainloop() {
    glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // RGB: 237, 232, 239
    glClear(GL_COLOR_BUFFER_BIT);

    shader_->use();
    auto P = camera_->get_projection_matrix();
    auto V = camera_->get_view_matrix();
    shader_->set_mat4("P", P);
    shader_->set_mat4("V", V);
    glBindVertexArray(VAO);
    unsigned int n_indices_ = mesh_.n_faces() * 3;
    glDrawElements(GL_TRIANGLES, n_indices_, GL_UNSIGNED_INT, 0);
    // glDrawElements(GL_LINES, n_indices_, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(glfw_window_);
    glfwPollEvents();
}

void MeshWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    mesh_window->width_ = width;
    mesh_window->height_ = height;
    mesh_window->camera_->set_width(width);
    mesh_window->camera_->set_height(height);
    glViewport(0, 0, width, height);
}

void MeshWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(mesh_window->glfw_window_, GLFW_TRUE);
            break;
        case GLFW_KEY_LEFT_SHIFT:
            mesh_window->left_shift_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_CONTROL:
            mesh_window->left_ctrl_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_ALT:
            mesh_window->left_alt_pressed_ = (action != GLFW_RELEASE);
            break;
    }
}

void MeshWindow::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    if (mesh_window->enable_trackball_) {
        mesh_window->camera_->update(xpos, ypos);
    }
}

void MeshWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    mesh_window->mouse_button_pressed_[button] = (action != GLFW_RELEASE);

    // 按下鼠标左键开启trackball
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        auto [x, y] = mesh_window->cursor_pos();
        mesh_window->camera_->set_last(x, y);
        mesh_window->enable_trackball_ = true;
    }
    // 松开鼠标左键关闭trackball
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mesh_window->enable_trackball_ = false;
    }
}

void MeshWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    mesh_window->camera_->scroll(yoffset);
}

}
}