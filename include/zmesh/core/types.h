#pragma once
#include <cstdint>
#include <limits>

#include <Eigen/Dense>

namespace zmesh {
namespace core {

using Index = std::uint32_t;
using Scalar = double;

using Vector3 = Eigen::Vector3d;
using Point = Vector3;
using Normal = Vector3;
using Color = Vector3;

using Vector2 = Eigen::Vector2d;
using TexCoord = Vector2;

const auto INDEX_MAX = UINT32_MAX;

}
}