#include "sensor_view.h"
#include <QBrush>
#include <QPen>
#include <QObject>
#include <QDebug>
#include <QString>
#include <iostream>

SensorView::SensorView(int size, QGraphicsRectItem *parent)
    : QGraphicsRectItem{parent}, size{size}
{

    setRect(0, 0, size, size);
    // setBrush(QBrush(QColor(Qt::blue)));
    setPen(QPen(Qt::NoPen));

    color = "yellow";

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
    auto sensor_color = state ? this->color : std::string("blue");
    // std::cout << sensor_color << std::endl;
    setBrush(QBrush(QColor(QString::fromStdString(color))));
}

void SensorView::set_color(std::string color)
{
    this->color = color;
    this->_update_view();
}