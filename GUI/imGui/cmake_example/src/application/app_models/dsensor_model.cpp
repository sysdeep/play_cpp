#include "./dsensor_model.hpp"
#include <iostream>

// DSensorModel::DSensorModel(std::string name) : LOGIC::DSensor(name) {}
DSensorModel::DSensorModel(LOGIC::Node *node) : LOGIC::DSensor(node) {
    //
    std::cout << "dsensor node: " << this->node << std::endl;
}