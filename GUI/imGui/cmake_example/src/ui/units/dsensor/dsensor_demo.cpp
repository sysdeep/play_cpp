#include "./dsensor_demo.hpp"
#include "./dsensor_view.hpp"
#include "imgui.h"

DsensorDemo::DsensorDemo() {
    //
    sensor = new UI::DSensorView();
}

void DsensorDemo::draw() {
    ImGui::Begin("DSensor demo");

    if (ImGui::Button("Toggle")) {
        sensor->toggle();
    }

    if (ImGui::Button("Visible")) {
        sensor->set_visible(!sensor->visible());
    }

    ImDrawList *draw_list_g = ImGui::GetWindowDrawList();
    sensor->draw(draw_list_g);

    ImGui::End();
}