#include "./node.hpp"
#include <iostream>

LOGIC::Node::Node(std::string name, std::vector<Node *> childs) : name(name) {
    //
    for (auto ch : childs) {
        this->childrens[ch->name] = ch;
    }
}

LOGIC::Node *LOGIC::Node::get_node(std::string node_path) {

    auto first_dot_pos = node_path.find(".");
    // std::cout << "first dot pos: " << first_dot_pos << std::endl;

    // if finish
    if (first_dot_pos == std::string::npos) {
        if (this->childrens.contains(node_path)) {
            return this->childrens[node_path];
        } else {
            return nullptr;
        }
    }

    // continue in childrens
    auto first_name = node_path.substr(0, first_dot_pos);
    auto continue_path = node_path.substr(first_dot_pos, node_path.length());
    for (const auto &[name, ch] : this->childrens) {
        if (first_name == name) {
            // group path without first
            return ch->get_node(continue_path);
        }
    }

    return nullptr;

    // auto first_name = node_path.substr(0, node_path.find("."));
    // if (first_name != this->name) {
    //     return nullptr;
    // }
    // //
    // return this;
}