#include <iostream>
#include <sstream>
#include <filesystem>

#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <zmesh/core/properties.h>
#include <zmesh/core/mesh.h>
#include <zmesh/io/io.h>
#include <zmesh/gl/mesh_window.h>
#include <zmesh/gl/mesh_window_builder.h>

int main() {
    zmesh::gl::MeshWindow window = zmesh::gl::MeshWindow::create()
        .width(800)
        .height(600)
        .title("zmesh window title")
        .mesh(std::filesystem::path("./models/Balls.obj"))
        .draw_mode(zmesh::gl::DrawMode::Wireframe)
        ;

    window.run();
}
