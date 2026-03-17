#include <iostream>
#include <ostream>
#include <string>
#include <ctime>
#include "calendar_window.hpp"
#include "imgui.h"
#include "calendar/calendar.hpp"
#include "ui/utils/utils.hpp"

using namespace UI;
CalendarWindow::CalendarWindow()
{

  // // current date/time based on current system

  this->model = new CalendarModel();
  this->board = new Board();
  this->selector = new Selector(this->model);
  this->today_bar = new TodayBar();
}

void CalendarWindow::draw()
{

  ImGuiViewport *viewport = ImGui::GetMainViewport();
  auto size = ImVec2(viewport->WorkSize.x, viewport->WorkSize.y);
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(size);

  ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration |
                                  ImGuiWindowFlags_NoMove |
                                  ImGuiWindowFlags_NoResize |
                                  ImGuiWindowFlags_NoSavedSettings |
                                  ImGuiWindowFlags_NoBringToFrontOnFocus;

  ImGui::Begin("CalendarWindow", nullptr, window_flags);

  today_bar->draw();
  ImGui::Dummy(ImVec2(0.0f, 16.0f));
  selector->draw();
  ImGui::Dummy(ImVec2(0.0f, 16.0f));
  board->draw(this->model);

  ImGui::End();
}
