#include <iostream>
#include <sstream>
#include <filesystem>

#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <zmesh/zmesh.h>

int main() {
    auto window_ptr = zmesh::MeshWindow::create()
        .maximize()
        .title("zmesh window title")
        .mesh(std::filesystem::path("./models/cone.obj"))
        .draw_mode(zmesh::DrawMode::Wireframe)
        .pointer()
        ;

    window_ptr->run();
}
