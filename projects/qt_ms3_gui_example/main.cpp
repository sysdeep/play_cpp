#include "mainwindow.h"

#include <QApplication>

#include "core/core.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Core core = Core();
    core.foo();

    w.show();
    return a.exec();
}
