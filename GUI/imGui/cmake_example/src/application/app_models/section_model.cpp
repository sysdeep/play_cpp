#include "./section_model.hpp"

SectionModel::SectionModel(LOGIC::Node *node) : LOGIC::Section(node) {
    this->sensor_1 = new DSensorModel(node->get_node("sensor1"));
    this->sensor_1 = new DSensorModel(node->get_node("sensor2"));

    this->main_supply = new MainSupplyModel(node->get_node("main_supply"));
}