#include "./dsensor.hpp"
#include "logic/core/attr.hpp"

using namespace LOGIC;

DSensor::DSensor() {
    attrs.push_back(new Attr(1));
    attrs.push_back(new Attr(2));
    attrs.push_back(new Attr(3));
    attrs.push_back(new Attr(4));
}
