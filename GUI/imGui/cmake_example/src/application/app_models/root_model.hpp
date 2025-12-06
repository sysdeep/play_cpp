#pragma once
#include "./section_model.hpp"
#include "logic/core/base_model.hpp"
#include "logic/project/node.hpp"

class RootModel : public LOGIC::BaseModel {
  public:
    RootModel(LOGIC::Node *node);

    // composition
    SectionModel *section;
    // DSensorModel *sensor_1;
    // DSensorModel *sensor_2;
};