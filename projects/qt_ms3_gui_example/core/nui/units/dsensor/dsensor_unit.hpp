#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "gui/views/sensor_view.h"
#include "dsensor_interface.hpp"
#include "dsensor_ctrl.hpp"

class DSensorUnit : public QGraphicsRectItem, public DSensorInterface
{
    SensorView *sensor;
    DSensorCtrl *ctrl;

public:
    DSensorUnit(DSensorCtrl *ctrl, QGraphicsItem *parent = nullptr);

    void set_light_state(bool) override;
    void set_block_state(bool) override;
    void set_error_state(bool) override;
};