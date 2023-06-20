#include <zmesh/gl/arcball_window.h>

namespace zmesh {
namespace gl {

void ArcballWindow::set_draw_mode(DrawMode draw_mode) {
    draw_mode_ = draw_mode;
}

void ArcballWindow::set_scene(const glm::vec3& center, float radius) {
    // center_ = center;
    // radius_ = radius;
    // view_all();
}

void ArcballWindow::view_all() {
    // glm::vec4 c = glm::vec4(center_, 1.0);
    // glm::vec4 t = V * M * c;
    // translate(glm::vec3(-t[0], -t[1], -t[2] - 2.5 * radius_));
}

void ArcballWindow::update() {
    if (!arcball_enabled_) return;

    auto [cursor_x, cursor_y] = cursor_pos();
    auto dx = cursor_x - last_.x, dy = last_.y - cursor_y; // dx dy 是鼠标移动的距离, last_是上一帧鼠标所在位置
    auto [window_width, window_height] = size(); // 当前窗口的大小
    
    // 旋转大小, 单位是弧度
    float rotate_x = (2 * M_PI) * dx / window_width; // 绕x轴转可以360度转
    float rotate_y = M_PI * dy / window_height; // 绕y轴旋转的角度有限制, 限制在-90到90度之间

    // 当前相机位置和中心坐标的齐次坐标
    glm::vec4 eye = glm::vec4(eye_, 1);
    glm::vec4 center = glm::vec4(center_, 1);

    // x的旋转矩阵
    glm::mat4 rotate_matrix_x = glm::mat4(1);
    rotate_matrix_x = glm::rotate(rotate_matrix_x, rotate_x, up_);
    eye = (rotate_matrix_x * (eye - center)) + center;

    // 限制 y 的旋转角度
    // up_向量不变, 永远指向(0,1,0), 利用view_dir和up_的点乘的绝对值来控制y的旋转角度 (注意要normalize)
    glm::vec3 view_dir = glm::normalize(center_ - eye_);
    auto dot_product = std::abs(glm::dot(view_dir, up_));
    // cos(5度) = 0.9962
    if (dot_product < 0.9962f) {
        // y的旋转矩阵
        glm::mat4 rotate_matrix_y = glm::mat4(1);
        rotate_matrix_y = glm::rotate(rotate_matrix_y, rotate_y, up_);
        eye = (rotate_matrix_y * (eye - center)) + center;
    }

    // 更新上一帧的坐标
    last_[0] = cursor_x;
    last_[1] = cursor_y;

    // 更新 eye_
    eye_ = eye;

    // 更新 V
    V = glm::lookAt(eye_, center_, up_);
}

void ArcballWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // 按一次d键就会切换到下一个draw mode
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_D: {
                draw_mode_ = static_cast<DrawMode>((static_cast<int>(draw_mode_) + 1) % 5);
                spdlog::info("set draw mode to {}", kDrawModeName[static_cast<int>(draw_mode_)]); // 有magic enum就可以显示名字了
                break;
            }
            case GLFW_KEY_LEFT: {

                break;
            }
            default: {
                BaseWindow::key_callback(window, key, scancode, action, mods);
                break;
            }
        }
    }
}

void ArcballWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        auto [cursor_x, cursor_y] = cursor_pos(); // 当前鼠标位置

        last_ = glm::vec2(cursor_x, cursor_y);

        arcball_enabled_ = true;
    }

    // 松开左键就要关闭trackball
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        arcball_enabled_ = false;
    }
}

void ArcballWindow::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // zoom
    if (right_mouse_pressed() || (left_mouse_pressed() && left_shift_pressed())) {
        // zoom(xpos, ypos);
    }

    // translation
    else if (middle_mouse_pressed() || (left_mouse_pressed() && left_alt_pressed()))
    {
        // translation(xpos, ypos);
    }

    // rotation
    else if (left_mouse_pressed())
    {
        // rotation(xpos, ypos);
    }

    // remember points
    // last_point_2d_ = glm::ivec2(xpos, ypos);
    // last_point_ok_ = map_to_sphere(last_point_2d_, last_point_3d_);
}

void ArcballWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    float d = -(float)yoffset * 0.12 * radius_;
    // translate(glm::vec3(0.0f, 0.0f, d));
}

}
}