#pragma once

#include <chrono>
#include <functional>

#include <spdlog/spdlog.h>

namespace zmesh {

// 计算程序消耗时间, 并打印
void log_cost_time(std::function<void()> f) {
    auto t0 = std::chrono::steady_clock::now();
    f();
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    spdlog::info("cost time: {} ms", std::chrono::duration_cast<std::chrono::milliseconds>(dt).count());
}

long long cost_time(std::function<void()> f) {
    auto t0 = std::chrono::steady_clock::now();
    f();
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    return std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
}

}