#pragma once

#include <glm/glm.hpp>

#include <zmesh/gl/base_window.h>

namespace zmesh {
namespace gl {

enum class DrawMode : int {
    PointCloud = 0, /* 点云 */
    Wireframe = 1, /* 线框 */
    PhongShading = 2, /*  */
    PhongShadingWithWireframe = 3, /* phong shading 加上线框 */
    Texture = 4 /* 纹理 */
};

static std::array<std::string, 5> kDrawModeName = {
    "PointCloud",
    "Wireframe",
    "PhongShading",
    "PhongShadingWithWireframe",
    "Texture"
};

class ArcballWindow : public BaseWindow {
public: 
    ArcballWindow(int width, int height, const std::string& title = "") 
        : BaseWindow(width, height, title) { }
    virtual ~ArcballWindow() = default;

    // 设置draw mode, 默认是点云
    void set_draw_mode(DrawMode draw_mode);

    void set_scene(const glm::vec3& center, float radius);

    // 调整视角到可以看到整个scene
    void view_all();

protected:
    virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    virtual void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    virtual void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

protected:
    virtual void draw() = 0;

    void rotation(int x, int y);

    void translation(int x, int y);

    void zoom(int x, int y);

    void fly_to(int x, int y);

    void translate(const glm::vec3& trans);

    void rotate(const glm::vec3& axis, float angle);

    bool map_to_sphere(const glm::ivec2& point, glm::vec3& result);

protected:
    DrawMode draw_mode_;
    
    glm::vec3 center_;
    float radius_;

    float near_, far_, fovy_;

    glm::mat4 M;
    glm::mat4 V;
    glm::mat4 P;

    glm::ivec2 last_point_2d_;
    glm::vec3 last_point_3d_;
    bool last_point_ok_;
};

}
}