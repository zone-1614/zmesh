#include <zmesh/gl/mesh_window.h>

#include <filesystem>

int main() {
    zmesh::gl::MeshWindow window(800, 600, "hh", std::filesystem::path("./models/torus.obj"));
    window.run();
}