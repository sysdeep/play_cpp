#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_factory.hpp"
#include "./main_menu.hpp"
#include "calendar/calendar.hpp"

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
    Calendar *calendar;
  };

} // namespace UI

#endif // !MAIN_WINDOW
