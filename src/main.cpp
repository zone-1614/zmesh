#include <zmesh/core/properties.h>
#include <zmesh/core/mesh.h>
#include <zmesh/io/io.h>

#include <spdlog/spdlog.h>

#include <iostream>
#include <sstream>
#include <filesystem>

// TODO 写一个 OpenGL 渲染一下 Mesh, 看看有没有搞错, 后面应该把 Mesh 集成到一个 OpenGL 的框架之中 
// 不会 GoogleTest, 在这里写点函数测一测

void test();

int main() {
    test();
}

void test() {
    zmesh::core::Mesh mesh;
    std::filesystem::path path("./models/cone.obj");
    zmesh::io::read(mesh, path);

    for (auto f : mesh.faces()) {
        spdlog::info("new center face");
        std::vector<zmesh::core::Point> points;
        for (auto v : f.vertices()) {
            points.push_back(v.point());
        }
        for (auto hf : f.haledges()) {
            spdlog::info("hf iter");
        }
        for (auto ef : f.edges()) {
            spdlog::info("ef iter");
        }
        for (auto ff : f.faces()) {
            spdlog::info("ff iter");
        }
    }

    for (auto v : mesh.vertices()) {
        spdlog::info("new center v");
        for (auto vv : v.vertices()) {
            spdlog::info("vv iter");
        }
        for (auto hv : v.halfedges()) {
            spdlog::info("hv iter");
        }
        for (auto ev : v.edges()) {
            spdlog::info("ev iter");
        }
        for (auto fv : v.edges()) {
            spdlog::info("fv iter");
        }
    }


}