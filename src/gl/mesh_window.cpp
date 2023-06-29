#include <zmesh/gl/mesh_window.h>

#include <zmesh/algo/bbox.h>
#include <zmesh/io/io.h>
#include <zmesh/algo/normals.h>

#include <spdlog/spdlog.h>

#include <exception>

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
    glfwWindowHint(GLFW_SAMPLES, 4);

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

    glEnable(GL_DEPTH_TEST);
    glLineWidth(1.2f); // 线的宽度, 太小会被遮挡
    glEnable(GL_PROGRAM_POINT_SIZE); // 画点云
    
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

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vertex_buffer_);
    glGenBuffers(1, &febo_);
    glGenBuffers(1, &eebo_);
    glGenBuffers(1, &normal_buffer_);
    glBindVertexArray(vao_);

    auto vertices = mesh_.points();
    std::vector<unsigned int> face_indices;
    face_indices.reserve(mesh_.n_faces() * 3);
    for (auto f : mesh_.faces()) {
        for (auto v : f.vertices()) {
            face_indices.push_back(v.idx());
        }
    }

    std::vector<unsigned int> edge_indices;
    edge_indices.reserve(mesh_.n_edges() * 2);
    for (auto e : mesh_.edges()) {
        edge_indices.push_back(e.v0().idx());
        edge_indices.push_back(e.v1().idx());
    }

    auto vnormals = algo::vertex_normals(mesh_);
    auto vnormals_vector = vnormals.vector();

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, febo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, face_indices.size() * sizeof(unsigned int), face_indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, edge_indices.size() * sizeof(unsigned int), edge_indices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normal_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vnormals_vector.size() * 3 * sizeof(float), vnormals_vector.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(1);

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 更新 OpenGL buffers
    // 频繁更新导致卡顿, 暂时不更新
    // 更新顶点法向
    // auto vnormals = algo::vertex_normals(mesh_);
    // auto vnormals_vector = vnormals.vector();
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normal_buffer_);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, vnormals_vector.size() * 3 * sizeof(float), vnormals_vector.data(), GL_STATIC_DRAW);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    // glEnableVertexAttribArray(1);

    shader_->use();
    auto P = camera_->get_projection_matrix();
    auto V = camera_->get_view_matrix();
    shader_->set_mat4("P", P);
    shader_->set_mat4("V", V);
    shader_->set_float("ambient", ambient_);
    shader_->set_float("diffuse", diffuse_);
    shader_->set_float("specular", specular_);
    shader_->set_vec3("light_color", light_color_);
    shader_->set_vec3("object_color", object_color_);
    shader_->set_vec3("view_pos", camera_->get_position());
    // shader_->set_vec3("light_pos", glm::vec3(3.0f, 3.0f, 3.0f));
    shader_->set_vec3("light_pos", camera_->get_position());

    glBindVertexArray(vao_);

    // 画三角形
    shader_->set_vec4("temp_color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    unsigned int face_indices_ = mesh_.n_faces() * 3;
    glDepthRange(0.01, 1.0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, febo_);
    glDrawElements(GL_TRIANGLES, face_indices_, GL_UNSIGNED_INT, 0);

    // 画线框
    shader_->set_vec4("temp_color", glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    unsigned int edge_indices_ = mesh_.n_edges() * 2;
    glDepthRange(0.0, 1.0);
    glDepthFunc(GL_LEQUAL); // 设置状态: 深度测试函数为小于等于
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eebo_);
    glDrawElements(GL_LINES, edge_indices_, GL_UNSIGNED_INT, 0);
    glDepthFunc(GL_LESS); // 恢复深度测试函数

    // 画顶点
    shader_->set_float("point_size", point_size_);
    shader_->set_vec4("temp_color", glm::vec4(0.439f, 0.337f, 0.592f, 1.0f)); // rgb: 112, 86, 151
    unsigned int vertex_indices_ = mesh_.n_vertices();
    glDrawArrays(GL_POINTS, 0, vertex_indices_);

    glBindVertexArray(0);

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