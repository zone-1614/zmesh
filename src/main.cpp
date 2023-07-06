#include <zmesh/zmesh.h>

#include <filesystem>

int main() {
    zmesh::gl::MeshWindow window(800, 600, "zmesh");
    window.run();
}