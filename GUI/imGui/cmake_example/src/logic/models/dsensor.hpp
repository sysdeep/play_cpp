#ifndef LOGIC_DSENSOR_MODEL
#define LOGIC_DSENSOR_MODEL

#include "logic/core/base_model.hpp"
#include <string>

namespace LOGIC {
class DSensor : public BaseModel {
  public:
    DSensor(std::string name);
};
} // namespace LOGIC

#endif // !LOGIC_DSENSOR_MODEL
