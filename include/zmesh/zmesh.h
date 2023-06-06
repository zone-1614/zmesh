/**
 * @file zmesh.h
 * @author zone-1614 (you@domain.com)
 * @brief 包含所有模块的头文件
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <zmesh/core/mesh.h>
#include <zmesh/io/io.h>
#include <zmesh/gl/mesh_window.h>
#include <zmesh/gl/mesh_window_builder.h>

namespace zmesh {

using Mesh = zmesh::core::Mesh;
using zmesh::io::read;
using zmesh::io::write;
using MeshWindow = zmesh::gl::MeshWindow;
using DrawMode = zmesh::gl::DrawMode;

}