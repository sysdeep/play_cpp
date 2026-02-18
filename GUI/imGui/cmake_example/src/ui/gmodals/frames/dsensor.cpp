#include "./dsensor.hpp"
#include "imgui.h"
#include "ui/gmodals/frames/base_frame.hpp"

using namespace UI::GMODALS;

DSensor::DSensor()
    : BaseFrame() {

      };

void DSensor::draw() {
    //
    ImGui::Text("DSensor frame!");

    ImGui::Checkbox("block", &this->is_disabled);
};
