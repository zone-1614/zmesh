#pragma once

#include <string>
#include <vector>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <zmesh/gl/shader.h>

namespace zmesh {
namespace gl {

class MeshWindow {
public:
    MeshWindow(int width, int height, std::string title);
    ~MeshWindow();

    void run();

private:
    // void init();
    void mainloop();

    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

private:
    int width_;
    int height_;
    std::string title_;
    GLFWwindow* glfw_window_;

    // std::vector<Shader> shaders_;
    std::shared_ptr<Shader> shader_;

    unsigned int VAO;
};

}
}