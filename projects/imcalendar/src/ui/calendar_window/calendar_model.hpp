#pragma once
#include <vector>
#include "calendar/calendar.hpp"

namespace UI
{
  struct Day
  {
    int day;
    calendar::Weekday weekday;
  };

  class CalendarModel
  {
  public:
    CalendarModel();

    int current_day;
    int current_year;
    int current_month;

    int year;
    int month;
    // int days_in_month;

    std::vector<Day> days;

    // std::vector<std::vector<int>> board;

    void go_next_month();
    void go_prev_month();
    void go_next_year();
    void go_prev_year();

    void go_to(int year, int month);

  private:
    void prepare(int year, int month);
  };

}