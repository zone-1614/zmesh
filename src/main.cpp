#include <zmesh/zmesh.h>

#include <filesystem>

int main() {
    zmesh::gl::MeshWindow window(800, 600, "zmesh", std::filesystem::path("./models/Nefertiti_face.obj"));
    window.run();
}