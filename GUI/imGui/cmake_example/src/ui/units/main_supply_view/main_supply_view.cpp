
#include "./main_supply_view.hpp"
#include "../dsensor/dsensor_model_view.hpp"

using namespace UI;

MainSupplyView::MainSupplyView(MainSupplyModel *model, SceneNode *parent) : Views::MainSupply{parent}, model(model) {

    float sensorsX = 12.f;
    //
    sensor_enabled = new DSensorModelView(model->sensor_enabled, this);
    sensor_enabled->setPos(sensorsX, 12);

    //
    sensor_blocked = new DSensorModelView(model->sensor_enabled, this);
    sensor_blocked->setPos(sensorsX, 12 + 12 + 4);
};

void MainSupplyView::drawEvent(DrawContext *ctx) {
    //
    auto p0 = ImGui::GetCursorScreenPos();
    Views::MainSupply::drawEvent(ctx);
    ImGui::SetCursorScreenPos(p0);

    // sensor
    sensor_enabled->draw(ctx);

    sensor_blocked->draw(ctx);
}