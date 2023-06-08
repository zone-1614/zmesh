#include <zmesh/gl/mesh_window_builder.h>

namespace zmesh {
namespace gl {

MeshWindowBuilder::MeshWindowBuilder()
    : mesh_window_ptr_(std::make_unique<MeshWindow>(800, 600, "mesh")) {
    // default settings
}

MeshWindowBuilder& MeshWindowBuilder::width(int w) {
    auto h = mesh_window_ptr_->height();
    glfwSetWindowSize(mesh_window_ptr_->glfw_window_, w, h);
    return *this;
}

MeshWindowBuilder& MeshWindowBuilder::height(int h) {
    auto w = mesh_window_ptr_->width();
    glfwSetWindowSize(mesh_window_ptr_->glfw_window_, w, h);
    return *this;
}

MeshWindowBuilder& MeshWindowBuilder::maximize() {
    glfwMaximizeWindow(mesh_window_ptr_->glfw_window_);
    return *this;
}

MeshWindowBuilder& MeshWindowBuilder::title(const std::string& t) {
    glfwSetWindowTitle(mesh_window_ptr_->glfw_window_, t.c_str());
    return *this;
}

MeshWindowBuilder& MeshWindowBuilder::mesh(const std::filesystem::path& path) {
    mesh_window_ptr_->load_mesh(path);
    return *this;
}

MeshWindowBuilder& MeshWindowBuilder::draw_mode(DrawMode mode) {
    // TODO
    return *this;
}

std::unique_ptr<MeshWindow> MeshWindowBuilder::pointer() {
    return std::move(mesh_window_ptr_);
}

}
}