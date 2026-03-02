#pragma once
#include <string>
#include <cstdint>

namespace ui
{
    class Humanize
    {
        static const u_int64_t div = 1024;
        static const u_int64_t kb = div;
        static const u_int64_t mb = div * div;
        static const u_int64_t gb = div * div * div;

    public:
        static std::string toSize(const uint64_t value);
        static std::string formatImageID(const std::string &value);
    };
}