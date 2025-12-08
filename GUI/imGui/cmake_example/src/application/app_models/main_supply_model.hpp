#pragma once
#include "./dsensor_model.hpp"
#include "logic/models/main_supply.hpp"
#include "logic/project/node.hpp"

class MainSupplyModel : public LOGIC::MainSupply {
  public:
    MainSupplyModel(LOGIC::Node *node);

    // composition
    DSensorModel *sensor_enabled;
};