
#include <iostream>
#include "imgui.h"
#include "main_menu.h"
#include "../share.h"

void ShowExampleAppMainMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Calc"))    show_calc_window = true;
            if (ImGui::MenuItem("Help", "CTRL+H"))    show_help_window = true;

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}


void ShowHelpWindow(){
    ImGui::Begin("Help");
    ImGui::Text("Help");
    if(ImGui::Button("Close"))  show_help_window = false;
    ImGui::End();
}