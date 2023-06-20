#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    virtual void update() override;

protected:
    virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    virtual void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    virtual void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

protected:
    

protected:
    DrawMode draw_mode_;
    
    bool arcball_enabled_{false}; //!< 按住左键就可以启用trackball
    float radius_{6.0f}; //!< arcball 的半径
    glm::vec2 last_; //!< 上一次鼠标点到的位置

    // 相机参数
    glm::vec3 eye_{0, 0, 1};
    glm::vec3 center_{0, 0, 0};
    glm::vec3 up_{0, 1, 0};

    // MVP矩阵
    // glm::mat4 M = glm::mat4(1.0f);
    glm::mat4 V = glm::translate(glm::mat4(1), glm::vec3(0, 0, -radius_));
    // glm::mat4 P = glm::perspective();
};

}
}