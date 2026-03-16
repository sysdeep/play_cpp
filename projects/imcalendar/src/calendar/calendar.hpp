#pragma once
#include <string>
#include "calendar_model.hpp"
#include "cal.hpp"
#include "board.hpp"

class Calendar
{
public:
  Calendar();
  void draw();

private:
  CalendarModel *model;

  void on_day_clicked(int index);
  int tmp_day_index = 0;

  Board *board;

  void _draw_selector();
  void _draw_week_days();
  void _draw_today_info();

  const std::vector<std::string> week_days = {"пн", "вт", "ср", "чт",
                                              "пт", "сб", "вс"};
};
