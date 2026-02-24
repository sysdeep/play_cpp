#include "actions_bar.hpp"
#include <QHBoxLayout>
#include <QPushButton>

ActionsBar::ActionsBar()
{


    auto main_layout = new QHBoxLayout();
    main_layout->addStretch();

    auto btn_quit = new QPushButton("Close");
    connect(btn_quit, &QPushButton::clicked, [=](){
       emit this->doClose();
    });
    main_layout->addWidget(btn_quit);


    setLayout(main_layout);
}
