#include "mnemo.h"
#include "gui/views/vibrator_view.h"

Mnemo::Mnemo(int w, int h, QGraphicsView *parent)
    : QGraphicsView{parent}
{
    scene = new QGraphicsScene(0, 0, w, h);
    setScene(scene);
    setAlignment(Qt::AlignTop);

    // items
    sensor = new SensorView(55);
    scene->addItem(sensor);
    sensor->setPos(40, 40);

    auto *vibrator = new VibratorView(20);
    scene->addItem(vibrator);

    // datetime
    date_time = new DateTimeWidget();
    scene->addItem(date_time);
    date_time->setPos(w - date_time->boundingRect().width(), 10);
}
