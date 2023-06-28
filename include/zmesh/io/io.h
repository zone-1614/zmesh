/**
 * @file io.h
 * @author zone-1614 (you@domain.com)
 * @brief io函数
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <filesystem>

#include <zmesh/core/mesh.h>
#include <zmesh/io/io_options.h>

namespace zmesh {

using core::Mesh;

namespace io {

//! @param[out] mesh 输出网格
//! @param[in] file 输入文件
//! @return 读取是否成功
bool read(Mesh& mesh, const std::filesystem::path& file);

//! @param[out] mesh 输出网格
//! @param[in] file 输入文件
//! @param[in] options io选项
//! @return 读取是否成功
bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void read_obj(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void read_off(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

//! @param[in] mesh 输入网格
//! @param[in] file 写入文件
//! @return 写入是否成功
void write(Mesh& mesh, const std::filesystem::path& file);

//! @param[in] mesh 输入网格
//! @param[in] file 写入文件
//! @param[in] options io选项
//! @return 写入是否成功
void write(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void write_obj(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void write_off(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

}
}