#ifndef LOGIC_DSENSOR_MODEL
#define LOGIC_DSENSOR_MODEL

#include "logic/core/base_model.hpp"
#include <string>

namespace LOGIC {

// struct DSensorAttrs {
//     int logic;
// };

class DSensor : public BaseModel {
  public:
    DSensor(Node *node);
    // DSensorAttrs attrs{0};

    // attrs
    int logic = 0;
    bool is_error = false;
    bool is_blocked = false;
};

} // namespace LOGIC

#endif // !LOGIC_DSENSOR_MODEL
