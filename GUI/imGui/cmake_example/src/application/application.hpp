#ifndef APPLICATION
#define APPLICATION

#include "ui/main_window.hpp"

class Application {
  public:
    Application();
    void run();

  private:
    UI::MainWindow *_main_window;
};

#endif // !DEBUG
