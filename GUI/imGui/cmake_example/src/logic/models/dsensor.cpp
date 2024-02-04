#include "./dsensor.hpp"
#include "logic/core/attr.hpp"
#include "logic/core/base_model.hpp"
#include <string>

using namespace LOGIC;

DSensor::DSensor(std::string name) : BaseModel(name) {
    attrs.push_back(new Attr(1));
    attrs.push_back(new Attr(2));
    attrs.push_back(new Attr(3));
    attrs.push_back(new Attr(4));
}
