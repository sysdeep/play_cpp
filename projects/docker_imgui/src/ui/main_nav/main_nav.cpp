#include "imgui.h"
#include "main_nav.hpp"

using namespace ui;

MainNav::MainNav(UIState *state) : uiState(state) {}

void MainNav::draw()
{

    // window position
    ImGuiIO &io = ImGui::GetIO();
    auto display_size = io.DisplaySize; // Current window/swapchain size
    ImGui::SetNextWindowPos(ImVec2(0.0f, 25.0f));
    // ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize({display_size.x * 0.3f, display_size.y - 25.0f});

    ImGui::Begin("Nav", nullptr, ImGuiWindowFlags_None);

    if (ImGui::Button("Images"))
    {
        uiState->images_window = !uiState->images_window;
    }

    if (ImGui::Button("System"))
    {
        uiState->system_info_window = !uiState->system_info_window;
    }

    if (ImGui::Button("About"))
    {
        uiState->about_window = !uiState->about_window;
    }

    if (ImGui::Button("Demo"))
    {
        uiState->demo_window = !uiState->demo_window;
    }

    // if (ImGui::TreeNode("Resizable, stretch"))
    // {
    //     ImGui::Text("%s", "test");

    //     ImGui::TreePop();
    // }

    ImGui::End();
}