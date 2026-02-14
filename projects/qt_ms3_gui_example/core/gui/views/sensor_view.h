#ifndef SENSORVIEW_H
#define SENSORVIEW_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <string>

class SensorView : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    int size;
    bool state = false;
    std::string color;
    QTimer *timer;

    void _update_view();

public:
    explicit SensorView(int size, QGraphicsRectItem *parent = nullptr);

    void set_color(std::string);
};

#endif // SENSORVIEW_H
