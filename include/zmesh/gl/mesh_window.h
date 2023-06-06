#pragma once

#include <zmesh/gl/base_window.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>

namespace zmesh {
namespace gl {

        float my_color;
        char buf[255];
        float f = 0.5f;
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
        ImGui::InputText("input text", buf, 255);
        if (ImGui::Button("Save")) {
            // do something
            spdlog::info("width: {}, height: {}", width_, height_);
            screenshot();
        }
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

        // Edit a color stored as 4 floats
        ImGui::ColorEdit4("Color", &my_color);

        // Generate samples and plot them
        float samples[100];
        for (int n = 0; n < 100; n++)
            samples[n] = sinf(n * 0.2f + ImGui::GetTime() * 1.5f);
        ImGui::PlotLines("Samples", samples, 100);

        // Display contents in a scrolling region
        ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
        ImGui::BeginChild("Scrolling");
        for (int n = 0; n < 50; n++)
            ImGui::Text("%04d: Some text", n);
        ImGui::EndChild();

        ImGui::End();

        /* end frame */
        glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // 237, 232, 239
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwPollEvents();
        glfwSwapBuffers(glfw_window_);
    }
};

}
}