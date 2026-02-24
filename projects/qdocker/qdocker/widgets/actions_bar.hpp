#pragma once

#include <QWidget>

class ActionsBar: public QWidget
{
    Q_OBJECT
public:
    ActionsBar();

signals:
    void doClose();

};

