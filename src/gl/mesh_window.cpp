#include <zmesh/gl/mesh_window.h>

#include <zmesh/gl/mesh_window_builder.h>
#include <zmesh/io/io.h>

namespace zmesh {
namespace gl {

using zmesh::io::read;
using zmesh::io::write;

MeshWindow::MeshWindow(int width, int height, const std::string& title)
    : BaseWindow(width, height, title) {
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ebo_);

    glBindVertexArray(vao_);
    auto points = mesh_.points();
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, points.size() * 3 * sizeof(float), points.data(), GL_STATIC_DRAW);
    glBindVertexArray(0);
}

MeshWindow::~MeshWindow() {
    glfwTerminate();
}

MeshWindowBuilder MeshWindow::create() {
    return MeshWindowBuilder{};
}

void MeshWindow::render() {
    begin_frame();
    render_ui();
    render_mesh();
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

void MeshWindow::render_ui() {
    ImGui::Begin("Debug");

    // 选择文件
    ImGui::Text("Current file: %s", current_filename_.c_str());
    if (ImGui::Button("select file")) {
        // test log
        spdlog::info("hhh");
    }

    ImGui::Spacing();

    // 另存为
    ImGui::InputText("filename", save_filename_, 100);
    if (ImGui::Button("Save as")) {

    }

    ImGui::Spacing();

    // 截图
    if (ImGui::Button("Screenshot")) {
        screenshot();
    }
    ImGui::End();
    
    log_system_.draw();
}

void MeshWindow::render_mesh() {
    
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