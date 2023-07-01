#pragma once

#include <mutex>
#include <memory>
#include <vector>
#include <string>

#include <imgui.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace zmesh {
namespace gl {

// spdlog不提供获取log为std::string的接口, 这里实现稍微tricky
//! 能够获取std::string的sink
class str_sink : public spdlog::sinks::base_sink<std::mutex> {
public: 
    std::vector<std::string> get_logs();
    void clear();

protected:
    virtual void sink_it_(const spdlog::details::log_msg& msg) override;
    virtual void flush_() override {}

private:
    std::vector<std::string> logs_;
};

class LogWindow {
public:
    LogWindow();
    void clear();
    void draw();
};

}
}