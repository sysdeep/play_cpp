#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include "./main_menu.hpp"
#include "./scene.hpp"
#include "application/application_ctx.hpp"
#include "imgui.h"
#include <GLFW/glfw3.h>

namespace UI {

class MainWindow {
  public:
    MainWindow(ApplicationCtx *ctx);
    void loop();

  private:
    ApplicationCtx *ctx;
    // char *glsl_version;
    GLFWwindow *window;
    ImGuiIO *io;
    MainMenu *_main_menu;
    Scene *_scene;

    void initGLFW();
    void initImGui();

    void exitImGui();
    void exitGLFW();
};

} // namespace UI

#endif // !MAIN_WINDOW
