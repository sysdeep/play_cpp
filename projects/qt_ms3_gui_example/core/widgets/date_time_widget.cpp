#include <QFont>
#include <QDebug>
#include <QDateTime>
#include <QBrush>
#include <QPen>
#include <QColor>

#include "date_time_widget.hpp"


DateTimeWidget::DateTimeWidget(QGraphicsItem *parent) : QGraphicsRectItem(0, 0, 150, 60, parent)
{
    this->setPen(QPen(Qt::NoPen));

    this->ltime = new QGraphicsSimpleTextItem("time", this);
    this->ldate = new QGraphicsSimpleTextItem("date", this);
    this->ldate->setPos(0, DateTimeWidget::date_top_offset);


    QFont ft;
    ft.setFamily("Play");
    ft.setBold(true);
    ft.setPointSize(26);

    QFont fd;
    fd.setFamily("Play");
    fd.setBold(true);
    fd.setPointSize(12);

    this->ltime->setFont(ft);
    this->ldate->setFont(fd);

    this->ltime->setBrush(QBrush(QColor("#1874CD")));
    this->ldate->setBrush(QBrush(QColor("#1874CD")));



    this->__timer = new QTimer();
    QObject::connect(this->__timer, &QTimer::timeout, [this](){
        this->__update();
    });

    this->__timer->start(1000);

    this->__update();
}

void DateTimeWidget::__update()
{
    auto dt = QDateTime::currentDateTime();
    this->ltime->setText(dt.toString("hh:mm:ss"));
    this->ldate->setText(dt.toString("yyyy-MM-dd"));


    auto trect = this->ltime->boundingRect();
    auto drect = this->ldate->boundingRect();
    auto start_x = trect.width() - drect.width();
    this->ldate->setPos(start_x, DateTimeWidget::date_top_offset);
}
