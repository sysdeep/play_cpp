#include "ani_timer.hpp"
#include <iostream>

AniTimer::AniTimer(uint64_t timeout, std::function<void()> callback) : timeout{timeout}, callback{callback}
{
    this->last_checkout = std::chrono::system_clock::now();
};

void AniTimer::update(UpdateCtx *ctx)
{

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(ctx->update_time - this->last_checkout);

    if (elapsed.count() > this->timeout)
    {
        if (this->callback != nullptr)
        {
            this->callback();
        }
        this->last_checkout = ctx->update_time;
    }
}