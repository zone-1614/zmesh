#include <zmesh/gl/mesh_window.h>

#include <spdlog/spdlog.h>

#include <exception>

namespace zmesh {
namespace gl {

float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,  // first Triangle
    1, 2, 3   // second Triangle
};
    int success;
    char infoLog[512];
    unsigned int VBO, EBO;
MeshWindow::MeshWindow(int width, int height, std::string title)
    : width_(width), height_(height), title_(title) {
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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("glad init failed");
    }
    
    shader_ = std::make_shared<Shader>(
        std::filesystem::path("./shaders/test.vert"),
        std::filesystem::path("./shaders/test.frag"));

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader_->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(glfw_window_);
    glfwPollEvents();
}

}
}