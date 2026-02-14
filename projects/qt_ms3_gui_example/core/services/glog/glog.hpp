#pragma once
#include <string>

#include "iglog.hpp"

class GLog : public IGLog
{
public:
    GLog();

    void do_log(const std::string msg) override;
};