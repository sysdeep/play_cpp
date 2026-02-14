#pragma once

struct DSensorInterface
{
    virtual void set_light_state(bool) = 0;
    virtual void set_block_state(bool) = 0;
    virtual void set_error_state(bool) = 0;

    virtual ~DSensorInterface() = default;
};
