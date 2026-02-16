#ifndef MNEMO_H
#define MNEMO_H

#include "gui/views/sensor_view.h"
#include "widgets/date_time_widget.hpp"
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

class Mnemo : public QGraphicsView
{
    Q_OBJECT

    SensorView *sensor;
    DateTimeWidget *date_time;

public:
    explicit Mnemo(int w, int h, QGraphicsView *parent = nullptr);

    QGraphicsScene *scene;

signals:
};

#endif // MNEMO_H
