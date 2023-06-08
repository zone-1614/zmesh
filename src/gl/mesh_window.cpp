#include <zmesh/gl/mesh_window.h>

#include <zmesh/gl/mesh_window_builder.h>
#include <zmesh/io/io.h>

namespace zmesh {
namespace gl {

using zmesh::io::read;
using zmesh::io::write;

MeshWindow::MeshWindow(int width, int height, const std::string& title)
    : BaseWindow(width, height, title) {
    
}

MeshWindow::~MeshWindow() {
    glfwTerminate();
}

MeshWindowBuilder MeshWindow::create() {
    return MeshWindowBuilder{};
}

void MeshWindow::render() {
    begin_frame();
    draw_ui();
    draw_mesh();
    end_frame();
}

void MeshWindow::load_mesh(const std::filesystem::path& path) {
    read(mesh_, path);
}

void MeshWindow::save_mesh(const std::string& filename) {
    // 默认保存到 ./models 文件夹下
    std::filesystem::path path{"./models/" + filename + ".obj"};
    // TODO
    // write(mesh_, path);
}

void MeshWindow::begin_frame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void MeshWindow::draw_ui() {
    // auto io = ImGui::GetIO();
    // ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y));
    // ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoTitleBar;
    // window_flags |= ImGuiWindowFlags_NoCollapse;
    window_flags |= ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_MenuBar;
    ImGui::Begin("zmesh", &p_open_, window_flags);
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("Open", NULL, &show_);
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) {
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::BeginChild("Log", ImVec2(200, 50));
    ImGui::Text("aaaa");
    // Get the size of the child (i.e. the whole draw size of the windows).
    // ImVec2 wsize = ImGui::GetWindowSize();
    // Because I use the texture from OpenGL, I need to invert the V from the UV.
    // ImGui::Image((ImTextureID)0, wsize, ImVec2(0, 1), ImVec2(1, 0));
    ImGui::EndChild();

    ImGui::End();
}

void MeshWindow::draw_mesh() {
    
}

void MeshWindow::end_frame() {
    glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // RGB: 237, 232, 239
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwPollEvents();
    glfwSwapBuffers(glfw_window_);
}

}
}