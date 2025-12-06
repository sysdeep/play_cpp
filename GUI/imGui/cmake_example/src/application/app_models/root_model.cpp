#include "./root_model.hpp"
#include <stdexcept>

RootModel::RootModel(LOGIC::Node *node) : LOGIC::BaseModel(node) {
    //
    auto section_node = node->get_node("section");
    if (section_node == nullptr) {
        throw std::logic_error("node not found!");
    }

    this->section = new SectionModel(section_node);
}