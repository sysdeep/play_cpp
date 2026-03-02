#include "about_page.hpp"
#include "imgui.h"

AboutPage::AboutPage(UIState *state) : state{state}
{
    ThirdPartyLibraries.emplace_back(
        "Dear ImGui", "https://github.com/ocornut/imgui", "MakeString(GImguiLicenseData, GImguiLicenseSize)");

    ThirdPartyLibraries.emplace_back(
        "spdlog", "https://github.com/gabime/spdlog", "MakeString(GSpdlogLicenseData, GSpdlogLicenseSize)");

    ThirdPartyLibraries.emplace_back("JetBrains Mono", "https://www.jetbrains.com/lp/mono/",
                                     "MakeString(GJetbrainsMonoLicenseData, GJetbrainsMonoLicenseSize)");
}

void AboutPage::draw()
{
    if (!state->about_window)
        return;

    // window position
    ImGuiIO &io = ImGui::GetIO();
    auto display_size = io.DisplaySize; // Current window/swapchain size
    ImGui::SetNextWindowPos(ImVec2(display_size.x * 0.5f, display_size.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize({display_size.x * 0.5f, display_size.y * 0.5f});

    // start window
    ImGui::Begin("About", &this->state->about_window, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    // Check if the window is focused and the Escape key is pressed
    if (ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) && ImGui::IsKeyPressed(ImGuiKey_Escape))
    {
        state->about_window = false; // Set the visibility state to false to close the window
    }

    auto Style = ImGui::GetStyle();
    ImGui::PushFont(nullptr, Style.FontSizeBase * 1.4f);
    ImGui::Text("ImDocker");
    ImGui::PopFont();

    ImGui::Spacing();
    ImGuiStyle &style = ImGui::GetStyle();
    ImGui::PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]);
    ImGui::Text("%s", "TODO: version");
    ImGui::PopStyleColor();

    // TODO: Licence
    // ImGui::Spacing();
    // ImGui::TextWrapped("%s", "TODO: License");

    if (ThirdPartyLibraries.size() > 0)
    {

        ImGui::Spacing();
        ImGui::Text("Thirdparty libraries:");

        for (auto const &Library : ThirdPartyLibraries)
        {
            ImGui::Separator();
            ImGui::Spacing();
            ImGui::PushFont(nullptr, Style.FontSizeBase * 1.2f);
            ImGui::Text("%s", Library.Name.c_str());
            ImGui::PopFont();
            ImGui::Spacing();
            ImGui::TextLinkOpenURL(Library.Url.c_str(), Library.Url.c_str());
            ImGui::Spacing();
            ImGui::TextWrapped("%s", Library.LicenseText.c_str());
        }
    }

    // if (ImGui::Button("Закрыть"))
    //     this->state->about_window = false;

    ImGui::End();
}