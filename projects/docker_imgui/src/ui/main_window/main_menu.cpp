#include "imgui.h"
#include "main_menu.hpp"

MainMenu::MainMenu(UIState *state) : state{state}
{
}

void MainMenu::draw()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {

            if (ImGui::MenuItem("Help", "CTRL+H"))
            {

                // show_help_window = true;
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z"))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false))
            {
            } // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X"))
            {
            }
            if (ImGui::MenuItem("Copy", "CTRL+C"))
            {
            }
            if (ImGui::MenuItem("Paste", "CTRL+V"))
            {
            }
            ImGui::EndMenu();
        }
        // about
        if (ImGui::BeginMenu("About"))
        {
            if (ImGui::MenuItem("About"))
            {
                state->about_window = !state->about_window;
            }
            ImGui::EndMenu();
        }
        // debug
        if (ImGui::BeginMenu("Debug"))
        {
            if (ImGui::MenuItem("Demo"))
            {
                state->demo_window = !state->demo_window;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    // if (this->_show_demo)
    // {
    //     ImGui::ShowDemoWindow(&this->_show_demo);
    // }
}
