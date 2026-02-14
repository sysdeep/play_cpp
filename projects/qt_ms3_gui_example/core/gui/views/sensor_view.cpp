#include "sensor_view.h"
#include <QBrush>
#include <QPen>
#include <QObject>
#include <QDebug>

SensorView::SensorView(int size, QGraphicsRectItem *parent)
    : QGraphicsRectItem{parent}, size{size}
{

    setRect(0, 0, size, size);
    // setBrush(QBrush(QColor(Qt::blue)));
    setPen(QPen(Qt::NoPen));

    timer = new QTimer();

    connect(timer, &QTimer::timeout, [=]()
            { state = !state; 
            _update_view(); });
    timer->setInterval(1000);
    timer->start();

    // start
    _update_view();
}

void SensorView::_update_view()
{
    auto color = state ? Qt::green : Qt::blue;
    setBrush(QBrush(QColor(color)));
}