#include "core.hpp"

using namespace core;
// constexpr std::array<Weekday, 7> weekdays{
//     Weekday::Monday,
//     Weekday::Tuesday,
//     Weekday::Wednesday,
//     Weekday::Thursday,
//     Weekday::Friday,
//     Weekday::Saturday,
//     Weekday::Sunday,
// };

const char *get_weekday_name(Weekday weekday)
{
    return weekdays_long[static_cast<int>(weekday)];
}

const char *get_weekday_name_short(Weekday weekday)
{
    return weekdays_short[static_cast<int>(weekday)];
}

const char *core::get_month_name(Month month)
{
    return month_names[static_cast<int>(month)];
}