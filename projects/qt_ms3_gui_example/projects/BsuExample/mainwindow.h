#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mnemo.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Mnemo *mnemo;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
