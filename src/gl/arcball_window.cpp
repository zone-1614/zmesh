#include <zmesh/gl/arcball_window.h>

namespace zmesh {
namespace gl {

void ArcballWindow::set_draw_mode(DrawMode draw_mode) {
    draw_mode_ = draw_mode;
}

void ArcballWindow::set_scene(const glm::vec3& center, float radius) {
    center_ = center;
    radius_ = radius;
    view_all();
}

void ArcballWindow::view_all() {
    glm::vec4 c = glm::vec4(center_, 1.0);
    glm::vec4 t = V * M * c;
    translate(glm::vec3(-t[0], -t[1], -t[2] - 2.5 * radius_));
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
    if (action = GLFW_PRESS) {
        last_point_ok_ = map_to_sphere(last_point_2d_, last_point_3d_);
        if (left_ctrl_pressed()) {
            auto [x, y] = cursor_pos();
            fly_to(x, y);
        }
    } else {
        last_point_ok_ = false;
    }
}

void ArcballWindow::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // zoom
    if (right_mouse_pressed() || (left_mouse_pressed() && left_shift_pressed())) {
        zoom(xpos, ypos);
    }

    // translation
    else if (middle_mouse_pressed() || (left_mouse_pressed() && left_alt_pressed()))
    {
        translation(xpos, ypos);
    }

    // rotation
    else if (left_mouse_pressed())
    {
        rotation(xpos, ypos);
    }

    // remember points
    last_point_2d_ = glm::ivec2(xpos, ypos);
    last_point_ok_ = map_to_sphere(last_point_2d_, last_point_3d_);
}

void ArcballWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    float d = -(float)yoffset * 0.12 * radius_;
    translate(glm::vec3(0.0f, 0.0f, d));
}

void ArcballWindow::rotation(int x, int y) {
    if (last_point_ok_) {
        glm::ivec2 newPoint2D;
        glm::vec3 newPoint3D;
        bool newPointok;

        newPoint2D = glm::ivec2(x, y);
        newPointok = map_to_sphere(newPoint2D, newPoint3D);

        if (newPointok)
        {
            vec3 axis = cross(last_point_3d_, newPoint3D); // TODO
            float cosAngle = dot(last_point_3d_, newPoint3D);

            if (fabs(cosAngle) < 1.0)
            {
                float angle = 2.0 * acos(cosAngle) * 180.0 / M_PI;
                rotate(axis, angle);
            }
        }
    }
}

void ArcballWindow::translation(int x, int y) {
    float dx = x - last_point_2d_[0];
    float dy = y - last_point_2d_[1];

    vec4 mc = glm::vec4(center_, 1.0);
    vec4 ec = modelview_matrix_ * mc;
    float z = -(ec[2] / ec[3]);

    float aspect = (float)width() / (float)height();
    float up = tan(fovy_ / 2.0f * M_PI / 180.f) * near_;
    float right = aspect * up;

    translate(glm::vec3(2.0 * dx / width() * right / near_ * z,
                   -2.0 * dy / height() * up / near_ * z, 0.0f));
}

void ArcballWindow::zoom(int x, int y) {
    float dy = y - last_point_2d_[1];
    float h = height();
    translate(glm::vec3(0.0, 0.0, radius_ * dy * 3.0 / h));
}

void ArcballWindow::fly_to(int x, int y) {
    glm::vec3 p;
    if (pick(x, y, p)) {
        center_ = p;
        vec4 c = glm::vec4(center_, 1.0);
        vec4 t = V * M * c;
        translate(glm::vec3(-t[0], -t[1], -0.5 * t[2]));
    }
}

void ArcballWindow::translate(const glm::vec3& trans) {
    // modelview_matrix_ = translation_matrix(t) * modelview_matrix_;
}

void ArcballWindow::rotate(const glm::vec3& axis, float angle) {
    // // center in eye coordinates
    // vec4 mc = vec4(center_, 1.0);
    // vec4 ec = modelview_matrix_ * mc;
    // vec3 c(ec[0] / ec[3], ec[1] / ec[3], ec[2] / ec[3]);

    // modelview_matrix_ = translation_matrix(c) * rotation_matrix(axis, angle) *
    //                     translation_matrix(-c) * modelview_matrix_;
}

bool ArcballWindow::map_to_sphere(const glm::ivec2& point, glm::vec3& result) {
    if ((point2D[0] >= 0) && (point2D[0] <= width()) && (point2D[1] >= 0) &&
        (point2D[1] <= height()))
    {
        double w = width();
        double h = height();
        double x = (double)(point2D[0] - 0.5 * w) / w;
        double y = (double)(0.5 * h - point2D[1]) / h;
        double sinx = sin(M_PI * x * 0.5);
        double siny = sin(M_PI * y * 0.5);
        double sinx2siny2 = sinx * sinx + siny * siny;

        result[0] = sinx;
        result[1] = siny;
        result[2] = sinx2siny2 < 1.0 ? sqrt(1.0 - sinx2siny2) : 0.0;

        return true;
    }
    else
        return false;
}

}
}