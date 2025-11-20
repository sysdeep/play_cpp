#pragma once
#include "./dsensor_view.hpp"
#include "ui/demo/demo_modal/child_demo_modal.hpp"

class DsensorDemo : public ChildDemoModal {
  public:
    DsensorDemo(/* args */);
    // ~DsensorDemo();
    void draw() override;

  private:
    UI::DSensorView *sensor;
};