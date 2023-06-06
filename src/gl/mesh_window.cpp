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
    ImGui::Begin("zmesh");
    ImGui::Text("text");
    
    if (ImGui::Button("screenshot")) {
        screenshot();
    }
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