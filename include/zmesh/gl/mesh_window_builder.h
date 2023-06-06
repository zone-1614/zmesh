#pragma once

#include <filesystem>

#include <zmesh/gl/mesh_window.h>

namespace zmesh {
namespace gl {

class MeshWindowBuilder {
public:
    MeshWindowBuilder();

    MeshWindowBuilder& width(int w);

    MeshWindowBuilder& height(int h);

    MeshWindowBuilder& title(const std::string& t);

    MeshWindowBuilder& mesh(const std::filesystem::path& path);

    MeshWindowBuilder& draw_mode(DrawMode mode);

    operator MeshWindow();
    
private:
    MeshWindow* mesh_window_ptr_;
};

}
}