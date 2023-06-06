#pragma once

#include <zmesh/io/base_reader.h>
#include <spdlog/spdlog.h>

#include <fstream>
#include <string>

/**
 * Provide the functions to read and write mesh from obj file.
*/

namespace zmesh {
namespace io {

//! @class ObjReader
//! @brief 从obj文件读入网格
class ObjReader : public BaseReader {
public:
    bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options) {
        spdlog::info("[ZMesh] read mesh from {}", std::filesystem::absolute(file).string());
        // TODO 现在不管options, 只读顶点和面
        std::ifstream ifs(file.string());
        std::string line;

        // use for read vertex
        double x, y, z;
        // use for read face
        unsigned int idx;
        std::vector<core::VertexHandle> vertices;
        std::string f_item;

        while (!ifs.eof()) {
            std::getline(ifs, line);
            trim(line);
            // parse the content
            if (line.size() == 0) { // blank line
                continue;
            } else if (line[0] == '#') { // comment
                continue;
            } 

            std::stringstream ss;
            ss.str(line);
            std::string head;
            ss >> head;
            if (head == "v") { // vertex
                ss >> x >> y >> z;
                mesh.add_vertex(x, y, z);
            } else if (head == "vn") { // vertex normal
                // TODO
            } else if (head == "vt") { // vertex texcoord
                // TODO
            } else if (head == "f") {
                vertices.clear();
                while (ss >> f_item) {
                    // TODO 读取 tex 和 normal, 现在的实现把这两个全丢掉了
                    auto i = f_item.find_first_of("/");
                    if (i == std::string::npos) {
                        auto idx = atoi(f_item.c_str());
                        vertices.emplace_back(idx - 1);
                    } else {
                        auto idx = atoi(f_item.substr(0, i).c_str());
                        vertices.emplace_back(idx - 1);
                    }
                }
                mesh.add_face(vertices);
            } else {

            }
        }

        ifs.close();

        return true;
    }

    std::string extension() const {
        return ".obj";
    }
};

}
}