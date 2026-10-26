#include "about.hpp"
#include "imgui.h"

using namespace UI;
About::About(/* args */) : _is_open(false)
{
}

About::~About()
{
}

void About::draw()
{

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize |
                                    ImGuiWindowFlags_NoSavedSettings |
                                    ImGuiWindowFlags_NoCollapse;
    ImGui::SetNextWindowSize(ImVec2(300.f, 200.f));
    if (_is_open)
    {
        ImGui::Begin("About", &_is_open, window_flags);
        ImGui::Text("About");
        ImGui::Text("Version  : TODO");
        ImGui::Text("Author   : TODO");
        ImGui::Text("Repo     : TODO");
        ImGui::End();
    }
}

void About::show()
{
    _is_open = true;
}