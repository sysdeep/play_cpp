#include "mainwindow.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    auto *l = new QLabel("Root");

    setCentralWidget(l);


}

MainWindow::~MainWindow() {}
