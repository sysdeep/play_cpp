#include "./project.hpp"
#include "logic/core/base_model.hpp"
#include "logic/models/dsensor.hpp"
#include <string>

using namespace LOGIC;

Project::Project() {
    //
    // std::vector<Node *> root_childrens;
    auto root_node = new Node("root", std::vector<Node *>{
                                          //
                                          new Node("section",
                                                   std::vector<Node *>{
                                                       //
                                                       new Node("sensor1", std::vector<Node *>{}),
                                                       new Node("sensor2", std::vector<Node *>{}),
                                                   }),
                                          //
                                      });

    this->nodes_tree = root_node;
    nodes_map.push_back(root_node);
}

Node *Project::get_node_by_name(std::string path) {

    return this->nodes_tree->get_node(path);

    // for (auto model : models) {
    //     if (model->name == path) {
    //         return model;
    //     }
    // }
    // return nullptr;
}

Node *Project::get_node_root() {
    //
    return this->nodes_tree;
}
