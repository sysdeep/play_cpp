#include "dsensor_unit.hpp"

DSensorUnit::DSensorUnit(DSensorCtrl *ctrl, QGraphicsItem *parent) : QGraphicsRectItem(parent), ctrl{ctrl}
{
    sensor = new SensorView(10, this);

    // start
    set_error_state(true);
}

// interface ------------------------------------------------------------------
void DSensorUnit::set_light_state(bool st)
{
    auto color = st ? "lightGreen" : "green";
    sensor->set_color(color);
}

void DSensorUnit::set_block_state(bool st)
{
    auto color = st ? "lightGray" : "gray";
    sensor->set_color(color);
}

void DSensorUnit::set_error_state(bool st)
{
    auto color = st ? "purple" : "red";
    sensor->set_color(color);
}