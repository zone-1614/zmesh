/**
 * @file trackball_camera.h
 * @author zone-1614 (you@domain.com)
 * @brief trackball camera
 * trackball就是类似三维建模软件(blender)中的那种相机, 也叫arcball
 * @version 0.1
 * @date 2023-06-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <spdlog/spdlog.h>

namespace zmesh {
namespace gl {

class TrackballCamera {
public:
    TrackballCamera(
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3 lookat = glm::vec3(0.0f, 0.0f, 0.0f),
        float radius = 5.0f
    ) : position_(position),
        up_(up),
        lookat_(lookat),
        radius_(radius)
    {}

    //! 返回投影矩阵
    glm::mat4 get_projection_matrix() { return glm::perspective(glm::radians(zoom_), (float)width_ / (float)height_, near_, far_); }

    //! 返回view矩阵
    glm::mat4 get_view_matrix() { return glm::lookAt(position_, lookat_, up_); }

    //! 返回相机位置
    glm::vec3 get_position() { return position_; }

    float get_radius() { return radius_; }

    glm::vec3 get_right() { return right_; };
    
    //! @param xpos 当前x坐标
    //! @param ypos 当前y坐标
    //! @param width 窗口宽度, 需要利用它来计算旋转的角度
    //! @param height 窗口高度, 需要利用它来计算旋转的角度
    void update(double xpos, double ypos) {
        const auto dx = last_.x - xpos, dy = last_.y - ypos; // dx dy 是鼠标移动的距离, last_是上一帧鼠标所在位置
        
        // 旋转大小, 单位是弧度
        const float rotate_x = (2.0f * M_PI) * dx / (float)width_; // 绕x轴转可以360度转
        const float rotate_y = M_PI * dy / (float)height_; // 绕y轴旋转的角度有限制, 限制在-90到90度之间
        // 当前相机位置和中心坐标的齐次坐标
        glm::vec4 position = glm::vec4(position_, 1.0f);
        glm::vec4 lookat = glm::vec4(lookat_, 1.0f);

        // x的旋转矩阵
        glm::mat4 rotate_matrix_x = glm::mat4(1.0f);
        rotate_matrix_x = glm::rotate(rotate_matrix_x, rotate_x, up_);
        position = (rotate_matrix_x * (position - lookat)) + lookat;

        
        // y的旋转矩阵
        glm::mat4 rotate_matrix_y = glm::mat4(1);
        rotate_matrix_y = glm::rotate(rotate_matrix_y, rotate_y, right_);
        position = (rotate_matrix_y * (position - lookat)) + lookat;

        // 更新上一帧的坐标
        last_.x = xpos;
        last_.y = ypos;

        // 限制 y 的旋转角度, 如果y会超过80度, 那么不旋转
        const glm::vec3 view_dir = glm::normalize(glm::vec3(lookat - position));
        // 因为view_dir和up_都是单位向量, 所以点乘的结果是余弦值
        const auto cos_theta = std::abs(glm::dot(view_dir, up_));
        auto theta = std::acos(cos_theta); // 弧度
        theta = theta * 180.0f / M_PI; // 转为角度

        if (theta > 10.0f) {
            // 更新 position_
            position_ = glm::vec3(position);
            right_ = glm::normalize(glm::cross(view_dir, up_));
        }
    }

    //! glfw scroll callback会得到xoffset和yoffset
    //! 鼠标滚轮往向着自己的方向转时, yoffset是-1, 往屏幕那边转时, yoffset是1
    void scroll(double yoffset) {
        if (yoffset > 0) {
            if (zoom_ < 85.0f) {
                zoom_ += 2.0f;
            }
        } else {
            if (zoom_ > 5.0f) {
                zoom_ -= 2.0f;
            }
        }
    }

    //! 设置上一帧的位置
    void set_last(double x, double y) {
        last_.x = static_cast<float>(x);
        last_.y = static_cast<float>(y);
    }

    //! 设置相机宽度, 和window保持一致
    void set_width(int width) {
        width_ = width;
    }

    //! 设置相机高度, 和window保持一致
    void set_height(int height) {
        height_ = height;
    }

    void set_radius(float radius) {
        radius_ = radius;
        // near_ = 2.0f * radius;
        // far_ = -near_;
    }

private:
    glm::vec3 position_; //!< 相机位置, 有时候也叫 eye (眼睛位置)
    glm::vec3 up_; //!< 上向量, 固定为(0, 1, 0)
    glm::vec3 lookat_; //!< 看向哪里, 有时也叫 center
    glm::vec3 right_{1.0f, 0.0f, 0.0f}; //!< 右向量
    float radius_; //!< trackball的半径, 暂时没有用到
    float zoom_{45.0f}; //!< 缩放, 通过鼠标滚轮调整
    float near_{0.1f}; //!< 用于生成投影矩阵
    float far_{100.0f}; //!< 用于生成投影矩阵

    // old coord
    glm::vec2 last_{0.0f, 0.0f}; //!< 上一帧的坐标

    // window's width and height
    int width_; //!< 窗口宽度
    int height_; //!< 窗口高度
};

}
}