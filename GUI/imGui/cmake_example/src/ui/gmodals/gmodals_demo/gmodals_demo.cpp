#include "gmodals_demo.hpp"
#include "../modals/dsensor_gmodal.hpp"
#include "imgui.h"

GModalsDemo::GModalsDemo() {
    //
    dsensor = new UI::GMODALS::DSensorGmodal();
}

void GModalsDemo::draw() {
    //
    ImGui::Begin("Gmodals Window");
    ImGui::Checkbox("DSensor", &is_dsensor);
    ImGui::End();

    if (is_dsensor)
        dsensor->draw();
}