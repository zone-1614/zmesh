#pragma once

namespace zmesh {
namespace io {

struct io_options {
    bool vertex_normal{false};
    bool vertex_texture_coord{false};
    bool vertex_color{false};
    bool face_normal{false};
    bool face_color{false};
};

}
}