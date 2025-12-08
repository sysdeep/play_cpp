#include "./main_supply_model.hpp"
#include <iostream>

MainSupplyModel::MainSupplyModel(LOGIC::Node *node) : LOGIC::MainSupply(node) {
    //
    std::cout << "main supply node: " << this->node << std::endl;
    sensor_enabled = new DSensorModel(node->get_node("sensor_enabled"));
}