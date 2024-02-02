#ifndef LOGIC_BASE_PROJECT
#define LOGIC_BASE_PROJECT

#include "./base_model.hpp"
#include <string>
#include <vector>

namespace LOGIC {
class BaseProject {
  public:
    BaseModel *get_model(std::string path);

  private:
    std::vector<BaseModel *> models;
};
} // namespace LOGIC

#endif // !DEBUG
