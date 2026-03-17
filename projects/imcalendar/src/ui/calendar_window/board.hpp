#pragma once
#include <vector>
#include "calendar/calendar.hpp"
#include "calendar_model.hpp"

namespace UI
{
    class Board
    {
    public:
        Board();

        void draw(CalendarModel *model);

    private:
        std::vector<Day> make_board(CalendarModel *model);

        // cache
        int last_year = -1;
        int last_month = -1;
        std::vector<Day> data_model;

        bool day_is_current(Day day, CalendarModel *model);
    };
}