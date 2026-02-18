#pragma once
#include "../modals/dsensor_gmodal.hpp"

class GModalsDemo {
  public:
    explicit GModalsDemo();
    void draw();

  private:
    UI::GMODALS::DSensorGmodal *dsensor;
    bool is_dsensor = false;
};