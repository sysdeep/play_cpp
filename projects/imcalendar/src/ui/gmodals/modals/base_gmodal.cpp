#include "./base_gmodal.hpp"
#include "imgui.h"

using namespace UI::GMODALS;

BaseGmodal::BaseGmodal(){};

void BaseGmodal::draw() {

    if (!is_visible)
        return;

    ImGui::Begin("DSensor Gmodal", &this->is_visible);

    ImGui::Text("Hello from DSensor window!");

    this->frame->draw();

    if (ImGui::Button("Close Me")) {

        this->is_visible = false;
    }

    ImGui::End();
};
