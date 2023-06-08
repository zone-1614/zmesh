#pragma once

#include <filesystem>
#include <memory>

#include <zmesh/gl/mesh_window.h>

namespace zmesh {
namespace gl {

class MeshWindowBuilder {
public:
    MeshWindowBuilder();

    MeshWindowBuilder& width(int w);

    MeshWindowBuilder& height(int h);

    MeshWindowBuilder& maximize();

    MeshWindowBuilder& title(const std::string& t);

    MeshWindowBuilder& mesh(const std::filesystem::path& path);

    MeshWindowBuilder& draw_mode(DrawMode mode);

    std::unique_ptr<MeshWindow> pointer();

private:
    std::unique_ptr<MeshWindow> mesh_window_ptr_;
};

}
}