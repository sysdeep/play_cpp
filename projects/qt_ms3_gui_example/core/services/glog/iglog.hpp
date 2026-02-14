#pragma once

#include <string>

class IGLog
{
public:
    // IGLog() = default;
    virtual ~IGLog() = default;
    virtual void do_log(const std::string msg) = 0;
};