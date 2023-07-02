/**
 * @file util.h
 * @author zone-1614 (you@domain.com)
 * @brief 一些常用的函数
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <chrono>
#include <functional>

#include <spdlog/spdlog.h>

namespace zmesh {

//! 计算程序消耗时间, 并打印. 用来测试性能瓶颈
void log_cost_time(std::function<void()> f) {
    auto t0 = std::chrono::steady_clock::now();
    f();
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    spdlog::info("[util] cost time: {} ms", std::chrono::duration_cast<std::chrono::milliseconds>(dt).count());
}

//! 计算程序消耗时间(以ms为单位), 并返回. 可以用来统计循环中某一段代码消耗时间总和
long long cost_time(std::function<void()> f) {
    auto t0 = std::chrono::steady_clock::now();
    f();
    auto t1 = std::chrono::steady_clock::now();
    auto dt = t1 - t0;
    return std::chrono::duration_cast<std::chrono::milliseconds>(dt).count();
}

}