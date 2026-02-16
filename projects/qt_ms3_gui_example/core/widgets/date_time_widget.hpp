#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsItem>
#include <QTimer>

class DateTimeWidget : public QGraphicsRectItem
{

    static int const date_top_offset = 40;

public:
    explicit DateTimeWidget(QGraphicsItem *parent = nullptr);

    QGraphicsSimpleTextItem *ltime;
    QGraphicsSimpleTextItem *ldate;



private:
    QTimer *__timer;

    void __update();

signals:

public slots:


};

