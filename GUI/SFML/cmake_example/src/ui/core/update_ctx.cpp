#include "update_ctx.hpp"

UpdateCtx::UpdateCtx(/* args */)
{
    update_time = std::chrono::system_clock::now();
}

UpdateCtx::~UpdateCtx()
{
}
