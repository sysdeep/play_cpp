#pragma once
#include <vector>
#include "cal.hpp"
#include "core.hpp"

struct Day
{
  int day;
  core::Weekday weekday;
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

  void go_to(int year, int month);

private:
  void prepare(int year, int month);
};
