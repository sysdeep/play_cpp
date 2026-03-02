#include "humanize.hpp"
// #include <format>

using namespace ui;

std::string Humanize::toSize(const uint64_t value)
{
    const uint64_t div = 1024;

    std::string r;
    if (value <= 0)
        r = "0 bytes";
    else if (value >= Humanize::gb)
        // r = std::format("{} GBytes", value / Humanize::gb);
        r = std::to_string(value / Humanize::gb) + " Gb";
    else if (value >= Humanize::mb)
        r = std::to_string(value / Humanize::mb) + " Mb";
    // r = std::format("{} MBytes", value / Humanize::mb);
    else if (value >= Humanize::kb)
        r = std::to_string(value / Humanize::kb) + " Kb";
    // r = std::format("{} KBytes", value / Humanize::kb);
    return r;
}

std::string Humanize::formatImageID(const std::string &value)
{
    return value.substr(7, 7 + 12);
}