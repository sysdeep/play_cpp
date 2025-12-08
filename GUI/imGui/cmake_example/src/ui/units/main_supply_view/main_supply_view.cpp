
#include "./main_supply_view.hpp"
#include "../dsensor/dsensor_model_view.hpp"

using namespace UI;

MainSupplyView::MainSupplyView(MainSupplyModel *model) : model(model) {
    //
    sensor_enabled = new DSensorModelView(model->sensor_enabled);
};

void MainSupplyView::draw(ImVec2 pos) {
    //
    Views::MainSupply::draw(pos);

    // TODO: из-за эксперимента - не получается

    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    sensor_enabled->draw(draw_list);
}