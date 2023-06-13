/**
 * @file log_system.h
 * @author zone-1614 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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

// 因为spdlog没有暴露获取log的相关接口, 所以在这里拓展一下
//! 能够获取std::string的sink
class str_sink : public spdlog::sinks::base_sink<std::mutex> {
public:
    std::vector<std::string> logs();
    void clear();

protected:
    virtual void sink_it_(const spdlog::details::log_msg& msg) override;
    virtual void flush_() override {}

private:
    std::vector<std::string> logs_;
};

class LogSystem {
public:
    LogSystem();
    void clear();
    void draw();
    
private:
};

}
}