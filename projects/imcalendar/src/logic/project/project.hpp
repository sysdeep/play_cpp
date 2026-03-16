#ifndef LOGIC_PROJECT
#define LOGIC_PROJECT

#include "logic/core/base_model.hpp"
#include <string>
#include <vector>

namespace LOGIC {
class Project {
  public:
    Project();
    BaseModel *get_node(std::string path);

  private:
    std::vector<BaseModel *> models;
};
} // namespace LOGIC

#endif // !LOGIC_PROJECT
