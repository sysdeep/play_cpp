#include "mainwindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#include "../../core/core.h"
#include "bootstrap/bootstrap.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Core core = Core();
    core.foo();

    auto boot = Bootstrap();

    w.show();
    return a.exec();
}
