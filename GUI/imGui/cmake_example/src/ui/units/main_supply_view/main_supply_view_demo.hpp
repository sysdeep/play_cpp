#pragma once
#include "./main_supply_view.hpp"
#include "ui/demo/demo_modal/child_demo_modal.hpp"

class MainSupplyViewDemo : public ChildDemoModal {
  public:
    MainSupplyViewDemo(/* args */);
    // ~DsensorDemo();
    void draw() override;

  private:
    UI::MainSupplyView *main_supply;
    // UI::DSensorModelView *sensor_with_model;
    // DSensorModel *sensor_model;
};