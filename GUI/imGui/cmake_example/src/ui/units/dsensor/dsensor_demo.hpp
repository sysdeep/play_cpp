#pragma once
#include "./dsensor_model_view.hpp"
#include "./dsensor_view.hpp"
#include "ui/demo/demo_modal/child_demo_modal.hpp"

class DsensorDemo : public ChildDemoModal {
  public:
    DsensorDemo(/* args */);
    // ~DsensorDemo();
    void draw() override;

  private:
    UI::DSensorView *sensor;
    UI::DSensorModelView *sensor_with_model;
    DSensorModel *sensor_model;
};