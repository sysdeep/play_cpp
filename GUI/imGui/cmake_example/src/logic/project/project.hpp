#ifndef LOGIC_PROJECT
#define LOGIC_PROJECT

#include "./node.hpp"
#include "logic/core/base_model.hpp"
#include <string>
#include <vector>

namespace LOGIC {
class Project {
  public:
    Project();
    Node *get_node_by_name(std::string path);
    Node *get_node_root();

  private:
    std::vector<Node *> nodes_map;
    Node *nodes_tree;
};
} // namespace LOGIC

#endif // !LOGIC_PROJECT
