#include "AboutDialog.hpp"

#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QDate>

namespace  {

auto const YEAR  { QString::number(QDate::currentDate().year()) };
    auto const MONTH { QString::number(QDate::currentDate().month()) };

const QString description {

    "<h3>" "PROJECT_NAME_TITLE" " " "PROJECT_VERSION"
                " (Build " "BUILD_NUMBER" + QString(" - ") + MONTH + "/" + YEAR + ")</h3>"
            "Shell-centric MongoDB management tool.<br/>"
            "<a href=\"https://" "PROJECT_GITHUB_ISSUES" "\">Submit</a> issues/proposals on GitHub.<br/>"
            "<br/>"


    "<a href=\"https://" "PROJECT_DOMAIN" "\">" "PROJECT_DOMAIN" "</a> <br/>"

    "Copyright 2014-" + YEAR +
    " <a href= " "PROJECT_COMPANYNAME_DOMAIN" " >" "PROJECT_COMPANYNAME"
    "</a>. All rights reserved.<br/>"
    "<br/>"

    "The program is provided AS IS with NO WARRANTY OF ANY KIND, "
    "INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A "
    "PARTICULAR PURPOSE.<br/>"
    "<br>"

    "<b>Dependencies: <br></b>"
    "Mongo-Shell " "MongoDB_VERSION" "<br>"
    "Qt " "PROJECT_QT_VERSION" "<br>"
    "OpenSSL " 	   "OPENSSL_VERSION" "<br>"
    "libssh2 " 	   "LIBSSH2_VERSION" "<br>"
    "QJson "   	   "QJSON_VERSION" "<br>"

    "Google Test " "GOOGLE_TEST_VERSION" "<br>"
    "<br>"

    "<b>Credits: <br/></b>"
    "Some icons are designed by Freepik <a href=https://www.flaticon.com>www.flaticon.com</a>"
    "<br/>"

};
}

AboutDialog::AboutDialog(QWidget *parent): QDialog(parent)
{

    setWindowTitle("About "  "PROJECT_NAME_TITLE");

    //// About tab
    auto aboutTab = new QWidget;
    auto layout = new QGridLayout(this);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    auto copyRightLabel = new QLabel(description);
    copyRightLabel->setWordWrap(true);
    copyRightLabel->setOpenExternalLinks(true);
    copyRightLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

    // TODO
    auto logoLabel = new QLabel;
//            logoLabel->setPixmap(iconPixmap);

    layout->addWidget(logoLabel, 0, 0, 1, 1);
    layout->addWidget(copyRightLabel, 0, 1, 4, 4);
    aboutTab->setLayout(layout);


    //// License Agreement tab
    auto licenseTab = new QWidget;

    // button box -----------------------------------------
    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    // main layout ----------------------------------------
    auto tabWidget = new QTabWidget;
    tabWidget->addTab(aboutTab, "About");
    tabWidget->addTab(licenseTab, "License Agreement");

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
}
