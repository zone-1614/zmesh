#pragma once

#include <glm/glm.hpp>

namespace zmesh {
namespace gl {

class TrackballCamera {
public:
    TrackballCamera(
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3 lookat = glm::vec3(0.0f, 0.0f, 0.0f),
        float radius = 5.0f
    ) : position_(position),
        up_(up),
        lookat_(lookat),
        radius_(radius)
    {}

    glm::mat4 get_view_matrix() { return glm::lookAt(position_, lookat_, up_); }

    float get_zoom() { return zoom_; }
    
    //! @param xpos 当前x坐标
    //! @param ypos 当前y坐标
    //! @param width 窗口宽度, 需要利用它来计算旋转的角度
    //! @param height 窗口高度, 需要利用它来计算旋转的角度
    void update(double xpos, double ypos, int width, int height) {
        auto dx = xpos - last_.x, dy = last_.y - ypos; // dx dy 是鼠标移动的距离, last_是上一帧鼠标所在位置
        
        // 旋转大小, 单位是弧度
        float rotate_x = (2.0f * M_PI) * dx / (float)width; // 绕x轴转可以360度转
        float rotate_y = M_PI * dy / (float)height; // 绕y轴旋转的角度有限制, 限制在-90到90度之间
        spdlog::info("rotate x: {}, y: {}", rotate_x, rotate_y);
        // 当前相机位置和中心坐标的齐次坐标
        glm::vec4 position = glm::vec4(position_, 1.0f);
        glm::vec4 lookat = glm::vec4(lookat_, 1.0f);

        // x的旋转矩阵
        glm::mat4 rotate_matrix_x = glm::mat4(1.0f);
        rotate_matrix_x = glm::rotate(rotate_matrix_x, rotate_x, up_);
        position = (rotate_matrix_x * (position - lookat)) + lookat;

        // 限制 y 的旋转角度
        // up_向量不变, 永远指向(0,1,0), 利用view_dir和up_的点乘的绝对值来控制y的旋转角度 (注意要normalize)
        glm::vec3 view_dir = glm::normalize(glm::vec3(lookat - position));
        auto dot_product = std::abs(glm::dot(view_dir, up_));
        // cos(5度) = 0.9962
        if (dot_product < 0.9962f) {
            // y的旋转矩阵
            glm::mat4 rotate_matrix_y = glm::mat4(1);
            rotate_matrix_y = glm::rotate(rotate_matrix_y, rotate_y, glm::vec3(1.0f, 0.0f, 0.0f));
            position = (rotate_matrix_y * (position - lookat)) + lookat;
        }

        // 更新上一帧的坐标
        last_.x = xpos;
        last_.y = ypos;

        // 更新 position_
        position_ = glm::vec3(position);
        // spdlog::info("update camera position: {}, {}, {}", position_.x, position_.y, position_.z);
    }

    void set_last(double x, double y) {
        last_.x = static_cast<float>(x);
        last_.y = static_cast<float>(y);
    }

private:
    glm::vec3 position_;
    glm::vec3 up_;
    glm::vec3 lookat_; //!< center
    float radius_;
    float zoom_{45.0f};

    // old coord
    glm::vec2 last_{0.0f, 0.0f};
};

}
}