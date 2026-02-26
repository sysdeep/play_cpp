#include "main_window.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QStackedLayout>
#include <QMenuBar>

#include "gui/dialogs/AboutDialog.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    auto main_widget = new QWidget();
    auto main_layout = new QVBoxLayout();
    main_widget->setLayout(main_layout);


    setCentralWidget(main_widget);

    // side nav -------------------------------------------
    main_nav_tree = new MainNavTree();


    // main stacked layout --------------------------------
    stack = new QStackedLayout();
    stack->addWidget(new ContainersPage());
    stack->addWidget(new QLabel("images"));


    // compose --------------------------------------------
    auto central_layout = new QHBoxLayout();
    central_layout->addWidget(main_nav_tree);
    central_layout->addLayout(stack);


    // main layout
    main_layout->addLayout(central_layout);


    actions_bar = new ActionsBar();
    connect(actions_bar, &ActionsBar::doClose, [=](){
        this->close();
    });

    main_layout->addStretch();
    main_layout->addWidget(actions_bar);


    // main menu ------------------------------------------
    this->make_main_menu();


    // connect --------------------------------------------
    connect(main_nav_tree, &MainNavTree::pageSelected, this, &MainWindow::onPageSelected);

    // client ---------------------------------------------
    m_thread = new QThread(this);
    const QString socketPath = QStringLiteral("/var/run/docker.sock"); // ← ваш серверный endpoint
    unix_client = new UnixClient(socketPath);
    unix_client->moveToThread(m_thread);

//    connect(ui->sendButton, &QPushButton::clicked,
//                this, &MainWindow::onSendButtonClicked);
    connect(unix_client, &UnixClient::messageReceived,
                this, &MainWindow::onClientMessage);
    connect(unix_client, &UnixClient::connected,
                this, &MainWindow::onClientConnected);
        connect(unix_client, &UnixClient::disconnected,
                this, &MainWindow::onClientDisconnected);
        connect(unix_client, &UnixClient::errorOccurred,
                this, &MainWindow::onClientError);


        // Связываем сигналы/слоты между потоками
        connect(m_thread, &QThread::started, unix_client, &UnixClient::start);
        connect(m_thread, &QThread::finished, unix_client, &QObject::deleteLater);
        connect(this, &MainWindow::destroyed, m_thread, &QThread::quit);
//            connect(this, &MainWindow::destroyed, m_thread, &QThread::wait);

        // TODO: временно отключено
//    m_thread->start();



}

MainWindow::~MainWindow()
{
}

void MainWindow::make_main_menu()
{
    // file -----------------------------------------------
    QMenu *fileMenu = menuBar()->addMenu("File");

    // about ----------------------------------------------
    auto *aboutMenu = menuBar()->addMenu("About");

    // about
    auto *aboutAppAction = new QAction("&About...", this);
    connect(aboutAppAction, &QAction::triggered, [this](){
        AboutDialog dlg(this);
        dlg.exec();
    });

    aboutMenu->addAction(aboutAppAction);
}

void MainWindow::onPageSelected(int page)
{
    qDebug() << "selected page: " << page;
    auto need_index = pages_map[page];
    stack->setCurrentIndex(need_index);
}

void MainWindow::onClientMessage(const QString &msg)
{
    qDebug() << "result: " << msg;
}

void MainWindow::onClientConnected()
{
    qDebug() << "client connected";

    const QString path("/containers/json");
    QMetaObject::invokeMethod(unix_client, "requestJson",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, path));
}

void MainWindow::onClientDisconnected()
{
    qDebug() << "client disconnected";
}

void MainWindow::onClientError(const QString &err)
{
qDebug() << "client error: " << err;
}

