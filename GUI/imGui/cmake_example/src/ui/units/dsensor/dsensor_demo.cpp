#include "./dsensor_demo.hpp"
#include "./dsensor_model_view.hpp"
#include "./dsensor_view.hpp"
#include "imgui.h"
#include "logic/project/node.hpp"

DsensorDemo::DsensorDemo() {
    //
    sensor = new UI::DSensorView();

    auto sensor_node = new LOGIC::Node("foo", std::vector<LOGIC::Node *>{});
    sensor_model = new DSensorModel(sensor_node);
    sensor_with_model = new UI::DSensorModelView(sensor_model);
}

void DsensorDemo::draw() {
    ImGui::Begin("DSensor demo");

    if (ImGui::Button("Toggle")) {
        sensor->toggle();
        if (sensor_model->logic > 0) {
            sensor_model->logic = 0;
        } else {
            sensor_model->logic = 1;
        }
    }

    if (ImGui::Button("Error")) {
        sensor_model->is_error = !sensor_model->is_error;
    }

    if (ImGui::Button("Block")) {
        sensor_model->is_blocked = !sensor_model->is_blocked;
    }

    if (ImGui::Button("Visible")) {
        sensor->set_visible(!sensor->visible());
        sensor_with_model->set_visible(!sensor_with_model->visible());
    }

    ImDrawList *draw_list_g = ImGui::GetWindowDrawList();
    sensor->draw(draw_list_g);
    sensor_with_model->draw(draw_list_g);

    ImGui::End();
}