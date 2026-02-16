#include "mainwindow.h"
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <QHBoxLayout>
// #include "../../core/widgets/speciallabel.h"
#include "widgets/speciallabel.h"
#include "lib/service_locator.hpp"
#include "services/glog/iglog.hpp"
#include "services/glog/glog.hpp"
#include "services/user/user.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget *ww = new QWidget();

    setCentralWidget(ww);

    QVBoxLayout *vl = new QVBoxLayout(ww);

    // make mnemo
    mnemo = new Mnemo(500, 600);
    vl->addWidget(mnemo);

    // controls
    auto *lc = new QHBoxLayout();
    vl->addLayout(lc);

    QPushButton *btn = new QPushButton("close");

    connect(btn, &QPushButton::clicked, [=]()
            { close(); });

    QPushButton *msg_button = new QPushButton("do msg");

    connect(msg_button, &QPushButton::clicked, [=]()
            {
                //
                auto user_service = ServiceLocator::provide<IUser>();
                auto user_mask = std::to_string(user_service->get_mask());

                auto glog = ServiceLocator::provide<IGLog>();
                glog->do_log("from button: " + user_mask);

                //
            });

    auto *specLabel = new SpecialLabel();


    lc->addWidget(specLabel);
    lc->addStretch();
    lc->addWidget(msg_button);
    lc->addWidget(btn);
}

MainWindow::~MainWindow() {}
