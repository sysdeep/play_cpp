#include "imgui.h"
#include "main_window.hpp"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ui/pages/system_info/system_info_page.hpp"
#include "ui/pages/containers/containers_page.hpp"
#include "ui/frames/images/images_frame.hpp"
#include "ui/frames/containers/containers_frame.hpp"
#include "ui/content/content_window.hpp"
#include "ui/content/content_frame.hpp"
#include "ui/icons/fa4.hpp"
#include "ui/windows/container_window.hpp"
#include "ui/windows/image_window.hpp"

MainWindow::MainWindow(docker::DockerClient *docker_client)
{
    //
    factory = new ImGuiFactory();

    state = new UIState();
    state->demo_window = true;

    // content
    auto content_window = new ui::ContentWindow();
    content_window->registerPage(new ui::ContainersFrame(state, docker_client));
    content_window->registerPage(new ui::ImagesFrame(state, docker_client));

    // components
    main_menu = new MainMenu(state);
    // main_nav = new ui::MainNav(state);

    pages.push_back(content_window);
    pages.push_back(new AboutPage(state));
    pages.push_back(new SystemInfoPage(state, docker_client));
    // pages.push_back(new ImagesPage(state, docker_client));
    // pages.push_back(new ui::ContainersPage(state, docker_client));

    // modals manager -------------------------------------
    this->modalsManager = new ui::ModalsManager(state, docker_client);
};

void MainWindow::start_loop()
{
    auto window = factory->init();

    this->_setup_fonts();

    // Setup Dear ImGui style
    // ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    auto io = &ImGui::GetIO();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // start draw ---------------------------------------------------------
        // main menu
        this->main_menu->draw();

        // demo window
        if (state->demo_window)
            ImGui::ShowDemoWindow(&state->demo_window);

        // drawable
        for (auto dp : pages)
        {
            dp->draw();
        }

        // // windows
        // for (const auto &id : state->container_modals)
        // {
        //     ui::ContainerWindow(id).draw();
        // }

        // for (const auto &id : state->image_modals)
        // {
        //     ui::ImageWindow(id).draw();
        // }

        // modals manager
        this->modalsManager->draw();

        // example window -----------------------------------------------------
        if (state->example_window)
        {
            static float f = 0.0f;
            static int counter = 0;

            if (ImGui::Begin("Hello, world!", &state->example_window))
            {

                ImGui::Text("Привет мир - "
                            "\xef\x80\x80");

                ImGui::Text("\xef\x80\x80 Привет мир");
                ImGui::Text("\xef\x80\x81 Привет мир");
                ImGui::Text("\xef\x80\x82 Привет мир");

                ImGui::Text("This is some useful text."); // Display some text (you can
                                                          // use a format strings too)
                ImGui::Checkbox("Demo Window",
                                &state->demo_window); // Edit bools storing our window open/close state

                ImGui::SliderFloat("float", &f, 0.0f,
                                   1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color",
                                  (float *)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button")) // Buttons return true when clicked (most
                                             // widgets return true when edited/activated)
                    counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);
                ImGui::End();
            }
        }

        // Rendering ----------------------------------------------------------
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w,
                     clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    factory->shutdown(window);
};

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

    this->state->fontRegular = io->Fonts->AddFontFromFileTTF("../assets/Roboto-Regular.ttf", fontSize, nullptr, io->Fonts->GetGlyphRangesCyrillic());
    // io->Fonts->AddFontFromFileTTF("../assets/Roboto-Medium.ttf", 16.f);

    // NOTE: данный шрифт подмешивается к самому первому, и должен быть определён сразу за ним
    // icons font
    ImFontConfig icons_config;

    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced

    static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
    io->Fonts->AddFontFromFileTTF("../assets/fontawesome-webfont.ttf", 13.f, &icons_config, icons_ranges);

    // monospace font
    this->state->fontMono = io->Fonts->AddFontFromFileTTF("../assets/RobotoMono-Regular.ttf", fontSize, nullptr, io->Fonts->GetGlyphRangesCyrillic());

    // Call this after all fonts are loaded
    io->Fonts->Build();
}