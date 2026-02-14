#include "vibrator_view.h"
#include <QBrush>

VibratorView::VibratorView(int size, QGraphicsRectItem *parent)
    : QGraphicsRectItem{parent}, size{size}
{

    setRect(0, 0, size, size);
    setBrush(QBrush(QColor(Qt::green)));
}
