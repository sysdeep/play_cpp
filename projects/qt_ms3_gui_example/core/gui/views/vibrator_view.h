#pragma once

#include <QObject>
#include <QGraphicsRectItem>

class VibratorView : public QGraphicsRectItem
{

    int size;

public:
    explicit VibratorView(int size, QGraphicsRectItem *parent = nullptr);
};