#pragma once

#include <zmesh/gl/base_window.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace zmesh {
namespace gl {

class MeshWindow : public BaseWindow {
public:
    MeshWindow() : BaseWindow(800, 600, "title") { }
    ~MeshWindow() {
        glfwTerminate();
    }
    void render() {
        /* begin frame */
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        /* imgui */
        ImGui::Begin("zmesh");
        ImGui::Text("text");
        char* buf="";
        ImGui::InputText("input text", buf, 100);
        ImGui::End();

        /* end frame */
        glClearColor(0.4f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwPollEvents();
        glfwSwapBuffers(glfw_window_);
    }
};

}
}