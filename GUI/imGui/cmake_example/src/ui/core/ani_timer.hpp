#pragma once

#include "draw_context.hpp"
#include <chrono>
#include <cstdint>
#include <functional>

class AniTimer {
  public:
    AniTimer(uint64_t timeout, std::function<void()> callback);
    void update(DrawContext *ctx);

  private:
    uint64_t timeout;
    std::chrono::system_clock::time_point last_checkout;
    std::function<void()> callback;
};