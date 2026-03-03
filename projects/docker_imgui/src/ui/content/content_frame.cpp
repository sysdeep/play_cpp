#include <string>
#include "imgui.h"
#include "content_frame.hpp"

using namespace ui;

ContentFrame::ContentFrame() {};

void ContentFrame::draw()
{
    ImGui::Separator();
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
    if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
    {
        if (ImGui::BeginTabItem("Avocado"))
        {
            ImGui::Text("This is the Avocado tab!\nblah blah blah blah blah");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Broccoli"))
        {
            ImGui::Text("This is the Broccoli tab!\nblah blah blah blah blah");
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Cucumber"))
        {
            ImGui::Text("This is the Cucumber tab!\nblah blah blah blah blah");
            ImGui::EndTabItem();
        }

        for (const auto &pp : pages)
        {
            std::string title = std::to_string(pp.first) + " tab";

            if (ImGui::BeginTabItem(title.c_str()))
            {
                // pp.first
                pp.second->draw();

                ImGui::EndTabItem();
            }
        }

        ImGui::EndTabBar();
    }
    ImGui::Separator();
};

void ContentFrame::registerPage(int pageId, Frame *frame)
{
    pages[pageId] = frame;
};