#pragma once
#include "logic/models/dsensor.hpp"
#include "logic/project/node.hpp"

class DSensorModel : public LOGIC::DSensor {
  public:
    DSensorModel(LOGIC::Node *node);
};