#pragma once

#include <filesystem>

#include <zmesh/io/io_options.h>
#include <zmesh/core/mesh.h>

namespace zmesh {

using core::Mesh;

namespace io {

// c++ stl does not contain trim
void trim(std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (std::string::npos == start || std::string::npos == end) {
        str = "";
    } else {
        str = str.substr(start, end - start + 1);
    }
}

class BaseReader {
public:
    virtual bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options) = 0;

    // file extension name
    virtual std::string extension() const = 0;
};

}
}