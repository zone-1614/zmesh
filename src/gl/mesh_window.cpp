#include <zmesh/gl/mesh_window.h>

#include <zmesh/gl/mesh_window_builder.h>
#include <zmesh/io/io.h>
#include <zmesh/algo/normals.h>

namespace zmesh {
namespace gl {

using zmesh::io::read;
using zmesh::io::write;

MeshWindow::MeshWindow(int width, int height, const std::string& title)
    : BaseWindow(width, height, title) {

    init_shader();
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
    update_mesh();
}

void MeshWindow::save_mesh(const std::string& filename) {
    // 默认保存到 ./models 文件夹下
    std::filesystem::path path{"./models/" + filename + ".obj"};
    // TODO
    // write(mesh_, path);
}

void MeshWindow::update_mesh() {
    // 第一次运行需要创建 opengl buffer object
    if (!vao_) {
        glGenVertexArrays(1, &vao_);
        glGenBuffers(1, &vbo_);
        glGenBuffers(1, &ebo_);
        glGenBuffers(1, &vertex_normal_buffer_);
    }

    glBindVertexArray(vao_);

    // auto vnormals = algo::vertex_normals(mesh_); // 计算所有的顶点法向
    auto vpoints = mesh_.points();

    // 顶点数据
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, vpoints.size() * 3 * sizeof(float), vpoints.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glDisableVertexAttribArray(1); // 关掉法向， 因为还没写

    glBindVertexArray(0);
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
    glm::mat4 M = glm::mat4(1.0);
    glm::mat4 V = glm::mat4(1.0);
    glm::mat4 P = glm::mat4(1.0);

    current_shader_->use();
    current_shader_->setFloat("point_size", point_size_);
    current_shader_->setMat4("M", M);
    current_shader_->setMat4("V", V);
    current_shader_->setMat4("P", P);
    current_shader_->setFloat("ambient", ambient_);
    current_shader_->setFloat("diffuse", diffuse_);
    current_shader_->setFloat("specular", specular_);
    current_shader_->setVec3("light_pos", light_pos_);
    current_shader_->setVec3("light_color", light_color_);
    current_shader_->setVec3("object_color", object_color_);
    current_shader_->setVec3("view_pos", view_pos_);

    glBindVertexArray(vao_);

    glDrawArrays(GL_POINTS, 0, mesh_.n_vertices());

    glBindVertexArray(0);
}

void MeshWindow::end_frame() {
    glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // RGB: 237, 232, 239
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwPollEvents();
    glfwSwapBuffers(glfw_window_);
}

// void MeshWindow::add_shader(std::shared_ptr<Shader> shader_ptr) {
//     shaders_.push_back(shader_ptr);
// }

void MeshWindow::init_shader() {
    // 默认添加几个常用的shader
    // phong shading
    shaders_.push_back(std::make_shared<Shader>(
        "phong shader",
        std::filesystem::path("./shaders/phong.vert"),
        std::filesystem::path("./shaders/phong.frag")
    ));

    current_shader_ = shaders_[0];

    // TODO 或许还有其他的
}

}
}