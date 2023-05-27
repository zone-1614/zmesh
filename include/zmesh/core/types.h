/**
 * @file types.h
 * @author zone-1614 (you@domain.com)
 * @brief 定义一些常用的类型
 * @version 0.1
 * @date 2023-05-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <cstdint>
#include <limits>

#include <Eigen/Dense>

namespace zmesh {
namespace core {

using Index = std::uint32_t; //<! Handle下标的类型
using Scalar = double; //<! 定义完忘记用了

using Vector3 = Eigen::Vector3d; //<! 3维向量类型
using Point = Vector3; //<! Vertex的点类型
using Normal = Vector3; //<! 法向类型
using Color = Vector3; //<! 颜色类型

using Vector2 = Eigen::Vector2d; //<! 2维向量类型
using TexCoord = Vector2; //<! 纹理坐标类型

const auto INDEX_MAX = UINT32_MAX; //<! 最大下标值, 用来判断Handle是否有效

}
}