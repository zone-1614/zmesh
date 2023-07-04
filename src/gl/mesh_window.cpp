#include <zmesh/gl/mesh_window.h>

#include <exception>
#include <string>
#include <sstream>
#include <thread>

#include <spdlog/spdlog.h>
// 这两个define不能放在头文件里面
#define STBIW_WINDOWS_UTF8
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <zmesh/algo/bbox.h>
#include <zmesh/io/io.h>
#include <zmesh/algo/normals.h>
#include <zmesh/util.h>

namespace zmesh {
namespace gl {

MeshWindow::MeshWindow(
    int width, 
    int height, 
    std::string title, 
    std::filesystem::path mesh_path
) : width_(width), height_(height), title_(title) {

    // 从文件读mesh
    io::read(mesh_, mesh_path);

    // init models, 加载models文件夹下面的文件
    auto models_path = std::filesystem::path("./models");
    auto models_path_iter = std::filesystem::directory_iterator(models_path);
    for (auto obj : models_path_iter) {
        models_.push_back(obj.path());
    }

    glfwInit();
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);

    glfw_window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (glfw_window_ == nullptr) {
        glfwTerminate();
        throw std::runtime_error("GLFW init failed");
    }
    glfwMakeContextCurrent(glfw_window_);
    glfwSetWindowUserPointer(glfw_window_, this); // 构造函数执行完毕之前暴露this指针不安全, 有没有更好的做法?
    // init callbacks
    glfwSetFramebufferSizeCallback(glfw_window_, MeshWindow::framebuffer_size_callback);
    glfwSetKeyCallback(glfw_window_, MeshWindow::key_callback);
    glfwSetCursorPosCallback(glfw_window_, MeshWindow::cursor_pos_callback);
    glfwSetMouseButtonCallback(glfw_window_, MeshWindow::mouse_button_callback);
    glfwSetScrollCallback(glfw_window_, MeshWindow::scroll_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("glad init failed");
    }

    glEnable(GL_DEPTH_TEST);
    glLineWidth(1.2f); // 线的宽度, 太小会被遮挡
    glEnable(GL_PROGRAM_POINT_SIZE); // 画点云

    // init imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // imgui style
    ImGui::StyleColorsClassic();
    // ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(glfw_window_, false);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    init_imgui_style();

    // init stb image
    stbi_flip_vertically_on_write(true);

    // log some information
    std::stringstream log_info_ss;
    log_info_ss << glGetString(GL_VENDOR);
    spdlog::info("[gl] OpenGL Vendor: {}", log_info_ss.str());
    log_info_ss.str(""); // clean the streamstring

    log_info_ss << glGetString(GL_RENDERER);
    spdlog::info("[gl] OpenGL Renderer: {}", log_info_ss.str());
    log_info_ss.str("");

    log_info_ss << glGetString(GL_VERSION);
    spdlog::info("[gl] OpenGL Version: {}", log_info_ss.str());
    log_info_ss.str("");

    log_info_ss << ImGui::GetVersion();
    spdlog::info("[gl] ImGui Version: {}", log_info_ss.str());

    // end init glfw glad opengl imgui
    // begin to init the window 

    shader_ = std::make_shared<Shader>(
        std::filesystem::path("./shaders/phong.vert"), 
        std::filesystem::path("./shaders/phong.frag")
    );

    // 利用bbox计算一开始相机的位置
    auto [_, bbmax] = algo::bounding_box(mesh_);
    auto radius = std::max({ bbmax[0], bbmax[1], bbmax[2] }) * 3.0f; // 数值为最大的一个坐标乘以3
    camera_ = std::make_shared<TrackballCamera>(glm::vec3(0, 0, radius));
    camera_->set_width(width_);
    camera_->set_height(height_);

    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vertex_buffer_);
    glGenBuffers(1, &febo_);
    glGenBuffers(1, &eebo_);
    glGenBuffers(1, &normal_buffer_);

    glBindVertexArray(vao_);

    
    auto vertices = mesh_.points();
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * 3 * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    std::vector<unsigned int> face_indices;
    face_indices.reserve(mesh_.n_faces() * 3);
    for (auto f : mesh_.faces()) {
        for (auto v : f.vertices()) {
            face_indices.push_back(v.idx());
        }
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, febo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, face_indices.size() * sizeof(unsigned int), face_indices.data(), GL_STATIC_DRAW);

    std::vector<unsigned int> edge_indices;
    edge_indices.reserve(mesh_.n_edges() * 2);
    for (auto e : mesh_.edges()) {
        edge_indices.push_back(e.v0().idx());
        edge_indices.push_back(e.v1().idx());
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, edge_indices.size() * sizeof(unsigned int), edge_indices.data(), GL_STATIC_DRAW);

    auto vnormals = algo::vertex_normals(mesh_);
    auto vnormals_vector = vnormals.vector();
    glBindBuffer(GL_ARRAY_BUFFER, normal_buffer_);
    glBufferData(GL_ARRAY_BUFFER, vnormals_vector.size() * 3 * sizeof(float), vnormals_vector.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glfwMaximizeWindow(glfw_window_);

    // after maximize the glfw window, init some buffer for draw the mesh into imgui
    glGenFramebuffers(1, &fbo_);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

    glGenTextures(1, &scene_texture_);
    glBindTexture(GL_TEXTURE_2D, scene_texture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, scene_texture_, 0);

    glGenRenderbuffers(1, &rbo_);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo_);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width_, height_);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo_);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        spdlog::error("framebuffer is not complete");
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

MeshWindow::~MeshWindow() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}

void MeshWindow::run() {
    while (!glfwWindowShouldClose(glfw_window_)) {
        mainloop();
    }
}

void MeshWindow::init_imgui_style() {
    // 抄来的style, 修改了一点点
    // https://github.com/ocornut/imgui/issues/707
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text] = ImVec4(0.31f, 0.25f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.74f, 0.74f, 0.94f, 1.00f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.68f, 0.68f, 0.68f, 0.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.8f, 0.8f, 0.8f, 1.00f); // --- 我添加的
    style.Colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.62f, 0.70f, 0.72f, 0.56f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.95f, 0.33f, 0.14f, 0.47f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.97f, 0.31f, 0.13f, 0.81f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.42f, 0.75f, 1.00f, 0.53f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.42f, 0.75f, 1.00f, 0.53f); // --- 我改的
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.65f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.40f, 0.62f, 0.80f, 0.15f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.39f, 0.64f, 0.80f, 0.30f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.28f, 0.67f, 0.80f, 0.59f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.25f, 0.48f, 0.53f, 0.67f);
    // style.Colors[ImGuiCol_ComboBg] = ImVec4(0.89f, 0.98f, 1.00f, 0.99f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.48f, 0.47f, 0.47f, 0.71f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.31f, 0.47f, 0.99f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.79f, 0.18f, 0.78f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.82f, 1.00f, 0.81f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.72f, 1.00f, 1.00f, 0.86f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.65f, 0.78f, 0.84f, 0.80f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.75f, 0.88f, 0.94f, 0.80f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.55f, 0.68f, 0.74f, 0.80f);//ImVec4(0.46f, 0.84f, 0.90f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.60f, 0.60f, 0.80f, 0.30f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
    // style.Colors[ImGuiCol_CloseButton] = ImVec4(0.41f, 0.75f, 0.98f, 0.50f);
    // style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 0.47f, 0.41f, 0.60f);
    // style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.16f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.99f, 0.54f, 0.43f);
    // style.Colors[ImGuiCol_TooltipBg] = ImVec4(0.82f, 0.92f, 1.00f, 0.90f);
    style.Alpha = 1.0f;
    // style.WindowFillAlphaDefault = 1.0f;
    style.FrameRounding = 4;
    style.IndentSpacing = 12.0f;
    // 可以在这里设置字体, 没有暴露接口, 因为jetbrain这个字体好看
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF("./fonts/JetBrainsMono-Medium.ttf", 18.0f); // 第二个参数是字体大小
    // ImGui::PushFont(font);
}

void MeshWindow::screenshot() {
    // 不存在则创建screenshot目录
    std::filesystem::create_directory("./screenshot");

    static int screenshot_count = 0;
    std::stringstream filename;
    filename << "./screenshot/" << title_ << "_" << screenshot_count++ << ".png";
    std::string filename_str = filename.str();
    // allocate memory 
    auto png_data = new unsigned char[3 * width_ * height_];

    glfwMakeContextCurrent(glfw_window_);
    // read the framebuffer

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, width_, height_, GL_RGB, GL_UNSIGNED_BYTE, png_data);
    auto screenshot_thread = std::thread([&, filename_str, png_data] {
        stbi_flip_vertically_on_write(true);
        // save the screen to png (use stb image write)
        stbi_write_png(filename_str.c_str(), width_, height_, 3, png_data, 3 * width_);
        delete[] png_data;
        spdlog::info("save screenshot to {}", filename_str.c_str());
    });
    screenshot_thread.detach();
}

void MeshWindow::load_mesh(std::filesystem::path mesh_path) {

}

void MeshWindow::mainloop() {
    glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
    glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // RGB: 237, 232, 239
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader_->use();
    auto P = camera_->get_projection_matrix();
    auto V = camera_->get_view_matrix();
    shader_->set_mat4("P", P);
    shader_->set_mat4("V", V);
    shader_->set_float("ambient", ambient_);
    shader_->set_float("diffuse", diffuse_);
    shader_->set_float("specular", specular_);
    shader_->set_vec3("front_light_color", light_color_);
    shader_->set_vec3("back_light_color", light_color_);
    shader_->set_vec3("object_color", object_color_);
    shader_->set_vec3("view_pos", camera_->get_position());
    shader_->set_vec3("front_light_pos", camera_->get_position() * 3.0f);
    auto back_light_pos = -camera_->get_position() * 2.0f;
    back_light_pos.y *= -1.5f;
    shader_->set_vec3("back_light_pos", back_light_pos);

    glBindVertexArray(vao_);

    if (draw_mode_ & DrawMode::PhongShading) {
        // 画三角形
        shader_->set_bool("enable_shading", true);
        shader_->set_vec4("temp_color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        unsigned int face_indices_ = mesh_.n_faces() * 3;
        glDepthRange(0.01, 1.0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, febo_);
        glDrawElements(GL_TRIANGLES, face_indices_, GL_UNSIGNED_INT, 0);
    }

    if (draw_mode_ & DrawMode::WireFrame) {
        // 画线框
        shader_->set_bool("enable_shading", false);
        unsigned int edge_indices_ = mesh_.n_edges() * 2;
        glDepthRange(0.0, 1.0);
        glDepthFunc(GL_LEQUAL); // 设置状态: 深度测试函数为小于等于
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eebo_);
        glDrawElements(GL_LINES, edge_indices_, GL_UNSIGNED_INT, 0);
        glDepthFunc(GL_LESS); // 恢复深度测试函数
    }

    if (draw_mode_ & DrawMode::Points) {
        // 画顶点
        shader_->set_bool("enable_shading", false);
        shader_->set_float("point_size", point_size_);
        unsigned int vertex_indices_ = mesh_.n_vertices();
        glDrawArrays(GL_POINTS, 0, vertex_indices_);
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindVertexArray(0);

    glClearColor(0.9294f, 0.9098f, 0.9372f, 1.0f); // RGB: 237, 232, 239
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // ui
    ImGui::Begin("file", nullptr, ImGuiTreeNodeFlags_DefaultOpen);
    static int item_current_idx = 0;
    const char* combo_preview_value = (models_[item_current_idx]).stem().string().c_str();
    if (ImGui::BeginCombo("models", combo_preview_value)) {
        for (int i = 0; i < models_.size(); i++) {
            const bool is_selected = (item_current_idx == i);
            if (ImGui::Selectable(models_[i].stem().string().c_str(), is_selected)) {
                load_mesh(models_[i]);
                item_current_idx = i;
            }
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
    if (ImGui::Button("select file")) {
        
    }
    if (ImGui::Button("screenshot")) {
        enable_screenshot_ = true;
    }
    ImGui::End();

    log_window_.draw();

    // mesh
    // ImGui::Begin("scene", nullptr, ImGuiWindowFlags_NoMove);
    ImGui::Begin("scene");
    {
        ImGui::BeginChild("mesh");
        ImGui::Image(
            (ImTextureID) scene_texture_,
            ImGui::GetContentRegionAvail(),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );
        is_hover_mesh_ = ImGui::IsItemHovered();
        if (!enable_trackball_) { // 之前已经是enable的话, 就不要再次判断hover了
            enable_trackball_ = enable_trackball_ && is_hover_mesh_;
        }
    }
    ImGui::EndChild();
    ImGui::End();

    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // 直到调用这个函数, ui才会画上去, 所以ui会在前面画的东西上边

    // 截图在这里执行
    if (enable_screenshot_) {
        enable_screenshot_ = false;
        screenshot();
    }

    glfwSwapBuffers(glfw_window_);
    glfwPollEvents();
}

void MeshWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    mesh_window->width_ = width;
    mesh_window->height_ = height;
    mesh_window->camera_->set_width(width);
    mesh_window->camera_->set_height(height);
    glViewport(0, 0, width, height);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mesh_window->width_, mesh_window->height_, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mesh_window->scene_texture_, 0);

    glBindRenderbuffer(GL_RENDERBUFFER, mesh_window->rbo_);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, mesh_window->width_, mesh_window->height_);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mesh_window->rbo_);
}

void MeshWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(mesh_window->glfw_window_, GLFW_TRUE);
            break;
        case GLFW_KEY_LEFT_SHIFT:
            mesh_window->left_shift_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_CONTROL:
            mesh_window->left_ctrl_pressed_ = (action != GLFW_RELEASE);
            break;
        case GLFW_KEY_LEFT_ALT:
            mesh_window->left_alt_pressed_ = (action != GLFW_RELEASE);
            break;
        // case GLFW_KEY_T:
        //     if (action == GLFW_PRESS)
        //         mesh_window->screenshot();
        //     break;
    }
}

void MeshWindow::cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    // ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);

    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    if (mesh_window->enable_trackball_) {
        mesh_window->camera_->update(xpos, ypos);
    }
}

void MeshWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    if (mesh_window->is_hover_mesh_) {
        mesh_window->mouse_button_pressed_[button] = (action != GLFW_RELEASE);

        // 按下鼠标左键开启trackball
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            auto [x, y] = mesh_window->cursor_pos();
            mesh_window->camera_->set_last(x, y);
            mesh_window->enable_trackball_ = true;
        }
    } else {
        ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    }

    // 放在上一个if外面是因为这样可以让鼠标在mesh窗口外面松开
    // 松开鼠标左键关闭trackball
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mesh_window->enable_trackball_ = false;
    }
}

void MeshWindow::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    MeshWindow* mesh_window = static_cast<MeshWindow*>(glfwGetWindowUserPointer(window));
    if (mesh_window->is_hover_mesh_) {
        mesh_window->camera_->scroll(yoffset);
    } else {
        ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);        
    }
}

}
}