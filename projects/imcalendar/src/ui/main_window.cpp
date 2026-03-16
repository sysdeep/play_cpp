#include "./main_window.hpp"
#include "./main_menu.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include <GLFW/glfw3.h> // Will drag system OpenGL headers

using namespace UI;

MainWindow::MainWindow()
{

  factory = new ImGuiFactory();
  calendar = new Calendar();
}

void MainWindow::loop()
{
  auto window = factory->init();

  this->_setup_fonts();
  this->_setup_style();

  // Our state
  bool show_demo_window = true;
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // UI::DSensorVM *model = new UI::DSensorVM();
  // UI::DSensorViewEx sensor = UI::DSensorViewEx(model);
  //

  // auto dsensor_gmodal = new UI::GMODALS::DSensorGmodal();

  auto io = &ImGui::GetIO();

  // Main loop
  while (!glfwWindowShouldClose(window))
  {

    glfwPollEvents();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // draw -----------------------------------------------
    this->draw();

    // 1. Show the big demo window (Most of the sample code is in
    // ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear
    // ImGui!).
    if (show_demo_window)
      ImGui::ShowDemoWindow(&show_demo_window);

    // my
    // sensor.draw();
    // _main_menu->draw();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  factory->shutdown(window);
}

void MainWindow::draw()
{

  calendar->draw();
}

void MainWindow::_setup_fonts()
{
  // Load Fonts
  // - If no fonts are loaded, dear imgui will use the default font. You can
  // also load multiple fonts and use ImGui::PushFont()/PopFont() to select
  // them.
  // - AddFontFromFileTTF() will return the ImFont* so you can store it if you
  // need to select the font among multiple.
  // - If the file cannot be loaded, the function will return a nullptr. Please
  // handle those errors in your application (e.g. use an assertion, or display
  // an error and quit).
  // - The fonts will be rasterized at a given size (w/ oversampling) and stored
  // into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which
  // ImGui_ImplXXXX_NewFrame below will call.
  // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype
  // for higher quality font rendering.
  // - Read 'docs/FONTS.md' for more instructions and details.
  // - Remember that in C/C++ if you want to include a backslash \ in a string
  // literal you need to write a double backslash \\ !
  // - Our Emscripten build process allows embedding fonts to be accessible at
  // runtime from the "fonts/" folder. See Makefile.emscripten for details.
  // io.Fonts->AddFontDefault();
  // io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
  // io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
  // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
  // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
  // ImFont* font =
  // io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f,
  // nullptr, io.Fonts->GetGlyphRangesJapanese()); IM_ASSERT(font != nullptr);

  auto io = &ImGui::GetIO();
  // ------------------------------------------------------------------------
  // io.Fonts->AddFontFromFileTTF("../fira.ttf", 16.0f, NULL,
  //                              io.Fonts->GetGlyphRangesCyrillic());
  // io.Fonts->AddFontFromFileTTF("../hemi_head_bd_it.ttf", 16.0f, NULL,
  //                              io.Fonts->GetGlyphRangesCyrillic());
  // io->Fonts->AddFontFromFileTTF("../vendors/imgui/misc/fonts/Roboto-Medium.ttf", 16.0f, NULL,
  //                               io->Fonts->GetGlyphRangesCyrillic());

  // io->Fonts->AddFontFromFileTTF("../assets/Roboto-Regular.ttf", 16.0f, NULL,
  //                               io->Fonts->GetGlyphRangesCyrillic());

  // io->Fonts->AddFontDefaultVector();

  const auto fontSize = 18.f;

  // this->state->fontRegular = io->Fonts->AddFontFromFileTTF("../assets/Roboto-Regular.ttf", fontSize, nullptr, io->Fonts->GetGlyphRangesCyrillic());
  io->Fonts->AddFontFromFileTTF("../vendors/imgui/misc/fonts/Roboto-Medium.ttf", fontSize, nullptr, io->Fonts->GetGlyphRangesCyrillic());
  // io->Fonts->AddFontFromFileTTF("../assets/Roboto-Medium.ttf", 16.f);

  // // NOTE: данный шрифт подмешивается к самому первому, и должен быть определён сразу за ним
  // // icons font
  // ImFontConfig icons_config;

  // icons_config.MergeMode = true;
  // icons_config.PixelSnapH = true;
  // icons_config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced

  // static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
  // io->Fonts->AddFontFromFileTTF("../assets/fontawesome-webfont.ttf", 13.f, &icons_config, icons_ranges);

  // // monospace font
  // this->state->fontMono = io->Fonts->AddFontFromFileTTF("../assets/RobotoMono-Regular.ttf", fontSize, nullptr, io->Fonts->GetGlyphRangesCyrillic());

  // Call this after all fonts are loaded
  io->Fonts->Build();
}

void MainWindow::_setup_style()
{
  auto &style = ImGui::GetStyle();
  // style.Colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
  // style.Colors[ImGuiCol_FrameBg] = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);

  style.FrameRounding = 2.0f;
  style.ChildRounding = 2.0f;
  style.TabRounding = 2.0f;
  style.GrabRounding = 2.0f;
  style.PopupRounding = 2.0f;
  style.WindowRounding = 2.0f;
  style.ScrollbarRounding = 4.0f;
}