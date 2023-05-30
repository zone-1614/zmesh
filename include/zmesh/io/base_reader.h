#pragma once

#include <filesystem>

#include <zmesh/io/io_options.h>
#include <zmesh/core/mesh.h>

namespace zmesh {

using core::Mesh;

namespace io {

//! 类似java里面的trim, 去掉字符串前面后面的空白字符
void trim(std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (std::string::npos == start || std::string::npos == end) {
        str = "";
    } else {
        str = str.substr(start, end - start + 1);
    }
}

//! @class BaseReader
//! @brief 所有Reader的基类
class BaseReader {
public:
    //! @brief 根据io选项, 从文件读入网格
    //! @param[out] 输出网格
    //! @param[in] 输入文件
    //! @param[in] io选项
    virtual bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options) = 0;

    //! 返回文件拓展名
    virtual std::string extension() const = 0;
};

}
}