#pragma once

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_factory.hpp"
// #include "./main_menu.hpp"
#include "ui/calendar_window/calendar_window.hpp"

namespace UI
{

  class MainWindow
  {
  public:
    MainWindow();
    void loop();

  private:
    ImGuiFactory *factory;

    void _setup_fonts();
    void _setup_style();

    void draw();

    // components
    CalendarWindow *calendar;
  };

} // namespace UI
