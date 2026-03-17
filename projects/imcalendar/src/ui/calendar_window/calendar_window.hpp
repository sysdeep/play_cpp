#pragma once
#include <string>
#include "calendar/calendar.hpp"
#include "calendar_model.hpp"
#include "board.hpp"
#include "selector.hpp"
#include "today_bar.hpp"

namespace UI
{
  class CalendarWindow
  {
  public:
    CalendarWindow();
    void draw();

  private:
    CalendarModel *model;

    Board *board;
    Selector *selector;
    TodayBar *today_bar;
  };
}