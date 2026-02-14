#ifndef SENSORVIEW_H
#define SENSORVIEW_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>

class SensorView : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    int size;
    bool state = false;
    QTimer *timer;

    void _update_view();

public:
    explicit SensorView(int size, QGraphicsRectItem *parent = nullptr);
    // signals:
};

#endif // SENSORVIEW_H
