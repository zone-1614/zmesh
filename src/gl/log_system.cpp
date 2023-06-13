#include <zmesh/gl/log_system.h>

#include <fmt/format.h>
#include <GLFW/glfw3.h>

namespace zmesh {
namespace gl {

std::vector<std::string> str_sink::logs() {
    std::lock_guard lck(mutex_);
    std::vector<std::string> v(logs_.begin(), logs_.end());
    return v;
}

void str_sink::clear() {
    std::lock_guard lck(mutex_);
    logs_.clear();
}

void str_sink::sink_it_(const spdlog::details::log_msg& msg) {
    spdlog::memory_buf_t formatted;
    spdlog::sinks::base_sink<std::mutex>::formatter_->format(msg, formatted);
    logs_.push_back(fmt::to_string(formatted));
}

LogSystem::LogSystem() {
    auto logger = spdlog::default_logger();
    auto& sinks = logger->sinks();
    sinks.push_back(std::make_shared<str_sink>());
}

void LogSystem::clear() {
    auto logger = spdlog::default_logger();
    auto& sinks = logger->sinks();
    auto sink = std::dynamic_pointer_cast<str_sink>(sinks.back());
    sink->clear();
}

void LogSystem::draw() {
    // get logs
    auto logger = spdlog::default_logger();
    auto& sinks = logger->sinks();
    auto sink = std::dynamic_pointer_cast<str_sink>(sinks.back());
    auto logs = sink->logs();

    ImGui::Begin("Log");

    if (ImGui::Button("Clear logs")) {
        clear();
    }
    ImGui::SameLine();
    if (ImGui::Button("Copy last log")) {
        auto window = glfwGetCurrentContext();
        glfwSetClipboardString(window, logs.back().c_str());
    }
    ImGui::SameLine();
    if (ImGui::Button("Copy all logs")) {
        auto window = glfwGetCurrentContext();
        std::string all_logs = "";
        for (auto log : logs) {
            all_logs += log;
        }
        glfwSetClipboardString(window, all_logs.c_str());
    }

    ImGui::BeginChild("logs");
    for (auto log : logs) {
        ImGui::TextUnformatted(log.c_str());
    }
    
    // 如果在最底端, 就保持在最底端. 否则保持在原位置
    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
        ImGui::SetScrollHereY(1.0f);
    }

    ImGui::EndChild();

    ImGui::End();
}

}
}