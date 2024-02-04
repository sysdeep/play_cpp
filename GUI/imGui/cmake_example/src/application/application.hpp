#ifndef APPLICATION
#define APPLICATION

#include "application/application_ctx.hpp"
#include "ui/main_window.hpp"

class Application {
  public:
    Application();
    void run();

  private:
    ApplicationCtx *application_ctx;
    UI::MainWindow *_main_window;
};

#endif // !DEBUG
