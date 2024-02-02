#include "./base_model.hpp"
#include <exception>

using namespace LOGIC;

Attr *BaseModel::get_attr(int id) {
    for (auto attr : attrs) {
        if (attr->id == id) {
            return attr;
        }
    }

    return nullptr;
}

void BaseModel::set_attr_value(int id, int value) {
    for (auto attr : attrs) {
        if (attr->id == id) {
            attr->set_int(value);
            notify_attr_changed(id);
            break;
        }
    }
}

int BaseModel::get_attr_value(int id) {
    for (auto attr : attrs) {
        if (attr->id == id) {
            return attr->get_int();
        }
    }
    throw std::exception();
}
