#pragma once

#include "logic/core/base_model.hpp"
#include <string>

namespace LOGIC {

class MainSupply : public BaseModel {
  public:
    MainSupply(Node *node);

    // attrs
    int logic = 0;
    bool is_error = false;
    bool is_blocked = false;
};

} // namespace LOGIC
