#pragma once
#include "./dsensor_model.hpp"
#include "./main_supply_model.hpp"
#include "logic/models/section.hpp"
#include "logic/project/node.hpp"

class SectionModel : public LOGIC::Section {
  public:
    SectionModel(LOGIC::Node *node);

    // composition
    DSensorModel *sensor_1;
    DSensorModel *sensor_2;

    MainSupplyModel *main_supply;
};