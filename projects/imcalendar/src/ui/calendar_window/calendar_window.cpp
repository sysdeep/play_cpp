#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
#include "calendar_window.hpp"
#include "imgui.h"
#include "calendar/calendar.hpp"

using namespace UI;
CalendarWindow::CalendarWindow()
{

  // // current date/time based on current system

  this->model = new CalendarModel();
  this->board = new Board();
}

void CalendarWindow::draw()
{

  // if (!is_visible)
  //       return;
  //
  ImGui::Begin("Calendar");

  ImGui::Text("Hello from Calendar!");

  this->_draw_today_info();

  this->_draw_selector();
  this->_draw_week_days();
  board->draw(this->model);

  ImGui::Text("%d", this->tmp_day_index);

  ImGui::End();
}

void CalendarWindow::on_day_clicked(int index)
{
  std::cout << index << std::endl;
  this->tmp_day_index = index;
}

void CalendarWindow::_draw_selector()
{
  // draw month selector
  if (ImGui::BeginTable("month_selector", 3))
  {
    ImGui::TableNextRow();
    ImGui::TableSetColumnIndex(0);
    if (ImGui::Button("prev", ImVec2(-FLT_MIN, 0.0f)))
    {
      model->go_prev_month();
    }

    ImGui::TableSetColumnIndex(1);

    // selected month
    auto month_name = get_month_name(static_cast<calendar::Month>(model->month - 1));
    ImGui::Text("%s %d", month_name, model->year);

    ImGui::TableSetColumnIndex(2);

    if (ImGui::Button("next", ImVec2(-FLT_MIN, 0.0f)))
    {
      model->go_next_month();
    }

    ImGui::EndTable();
  }
}

void CalendarWindow::_draw_week_days()
{
  if (ImGui::BeginTable("week_days_table", 7))
  {
    ImGui::TableNextRow();

    int index = 0;
    for (auto day : this->week_days)
    {

      ImGui::TableSetColumnIndex(index++);
      ImGui::Text("%s", day.c_str());
    }

    ImGui::EndTable();
  }
}

/**
 * информация о тек. дне
 */
void CalendarWindow::_draw_today_info()
{

  // auto ww = cal::day_of_week(model->current_day, model->month, model->year);

  ImGui::Text("Today:");
  ImGui::Text("Year: %d", model->year);
  ImGui::Text("Month: %d", model->month);
  ImGui::Text("Day: %d", model->current_day);
  // ImGui::Text("Wd: %s", cal::to_string(ww).c_str());
  // ImGui::Text("Days in month: %d", model->days);
}
