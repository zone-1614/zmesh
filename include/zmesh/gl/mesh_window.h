#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

    unsigned int shaderProgram;
    unsigned int VAO;
};

}
}