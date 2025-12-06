#pragma once
#include "../project/node.hpp"
#include "logic/core/base_model.hpp"
#include <string>

namespace LOGIC {

// struct SectionAttrs {
//     int logic;
// };

class Section : public BaseModel {
  public:
    Section(Node *node);
    // SectionAttrs attrs{0};
};

} // namespace LOGIC
