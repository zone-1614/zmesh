#pragma once
#include <filesystem>

#include <zmesh/core/mesh.h>
#include <zmesh/io/io_options.h>

namespace zmesh {

using core::Mesh;

namespace io {

bool read(Mesh& mesh, const std::filesystem::path& file);

bool read(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void read_obj(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void read_off(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

void write(Mesh& mesh, const std::filesystem::path& file);

void write(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void write_obj(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

// void write_off(Mesh& mesh, const std::filesystem::path& file, const io_options& options);

}
}