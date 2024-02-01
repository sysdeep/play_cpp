#include "./base_model.hpp"
#include <exception>

using namespace LOGIC;

void BaseModel::set_attr_value(int id, int value) {
    for (auto attr : attrs) {
        if (attr->id == id) {
            attr->value = value;
            break;
        }
    }
}

int BaseModel::get_attr_value(int id) {
    for (auto attr : attrs) {
        if (attr->id == id) {
            return attr->value;
        }
    }
    throw std::exception();
}
