#ifndef MNEMO_H
#define MNEMO_H

#include "gui/views/sensor_view.h"
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

class Mnemo : public QGraphicsView
{
    Q_OBJECT

    SensorView *sensor;

public:
    explicit Mnemo(int w, int h, QGraphicsView *parent = nullptr);

    QGraphicsScene *scene;

signals:
};

#endif // MNEMO_H
