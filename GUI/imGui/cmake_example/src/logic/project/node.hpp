#pragma once
#include <map>
#include <string>
#include <vector>

namespace LOGIC {
class Node {
  public:
    Node(std::string name, std::vector<Node *> childs);

    // members
    std::string name;

    Node *get_node(std::string node_path);

  private:
    std::map<std::string, Node *> childrens;
};
} // namespace LOGIC
