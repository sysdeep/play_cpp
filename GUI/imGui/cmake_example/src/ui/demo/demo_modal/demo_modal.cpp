#include "demo_modal.hpp"
#include "imgui.h"
#include "ui/units/dsensor/dsensor_demo.hpp"

DemoModal::DemoModal() {
    //
    // childrens.insert(std::make_pair(1, new DsensorDemo()));
    childrens.insert({1, new DsensorDemo()});
}

// DemoModal::~DemoModal() {}

void DemoModal::draw() {
    ImGui::Begin("Demo modal");

    if (ImGui::Button("dsensor")) {

        if (modals.contains(1)) {
            modals.erase(1);
        } else {
            modals.insert(1);
        }
        // auto model = ctx->project->get_node("main_sensor");

        // model->set_attr_value(1, 1);
    }
    // ImGui::SameLine();
    // if (ImGui::Button("disable")) {
    //     // auto model = ctx->project->get_node("main_sensor");

    //     // model->set_attr_value(1, 0);
    // }

    for (int m : modals) {
        childrens.at(m)->draw();
    }

    ImGui::End();
}