#include <zmesh/io/io.h>
#include <zmesh/io/obj_reader.h>

namespace zmesh {
namespace io {

// TODO 应该换一种方式来初始化这个 readers
static std::vector<BaseReader*> readers {
    new ObjReader()
};

//! 根据文件路径读mesh
bool read(Mesh& mesh, const std::filesystem::path& file) {
    io_options options;
    return read(mesh, file, options);
}

//! 根据文件路径和io option读mesh
bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options) {
    mesh.clear();

    auto ext_name = file.extension().string();
    std::transform(ext_name.begin(), ext_name.end(), ext_name.begin(), ::tolower);

    for (auto reader : readers) {
        if (reader->extension() == ext_name) {
            return reader->read(mesh, file, options);
        }
    }
    return false;
}

}
}