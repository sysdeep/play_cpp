#pragma once

#include <cstdint>
#include <chrono>
#include <functional>
#include "update_ctx.hpp"

class AniTimer
{
public:
    AniTimer(uint64_t timeout, std::function<void()> callback);
    void update(UpdateCtx *ctx);

private:
    uint64_t timeout;
    std::chrono::system_clock::time_point last_checkout;
    std::function<void()> callback;
};