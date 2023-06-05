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

int main() {
    zmesh::gl::MeshWindow mesh_window;
    mesh_window.run();
}
