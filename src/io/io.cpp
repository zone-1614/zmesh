#include <zmesh/io/io.h>
#include <zmesh/io/obj_reader.h>

namespace zmesh {
namespace io {

// TODO 应该换一种方式来初始化这个 readers
static std::vector<BaseReader*> readers {
    new ObjReader()
};

bool read(Mesh& mesh, const std::filesystem::path& file) {
    io_options options;
    return read(mesh, file, options);
}

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

// void read_obj(Mesh& mesh, const std::filesystem::path& file, const io_options& options) {
//     // TODO 当前版本不管option, 只读顶点和面
//     // ObjReader reader(mesh, file, options);
//     // reader.read();
// }

// void read_off(Mesh& mesh, const std::filesystem::path& file, const io_options& options) {
//     // TODO 当前版本不管option, 只读顶点和面
//     // ObjReader reader(mesh, file, options);
//     // reader.read();
// }

}
}