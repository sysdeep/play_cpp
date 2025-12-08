#include "demo_modal.hpp"
#include "imgui.h"
#include "ui/units/dsensor/dsensor_demo.hpp"
#include "ui/units/main_supply_view/main_supply_view_demo.hpp"

DemoModal::DemoModal() {
    //
    // childrens.insert(std::make_pair(1, new DsensorDemo()));
    childrens.insert({1, new DsensorDemo()});
    childrens.insert({2, new MainSupplyViewDemo()});
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
    }

    if (ImGui::Button("main supply")) {

        if (modals.contains(2)) {
            modals.erase(2);
        } else {
            modals.insert(2);
        }
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