#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "widgets/actions_bar.hpp"
#include "widgets/main_nav_tree.hpp"
#include "widgets/pages.hpp"
#include <QStackedLayout>
#include "pages/containers_page.hpp"
#include "core/unix_client.hpp"
#include <QThread>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ActionsBar *actions_bar;
    MainNavTree *main_nav_tree;

private:
    QStackedLayout *stack;
    QMap<int, int> pages_map = {
        {PAGE_CONTAINERS, 0},
        {PAGE_IMAGES, 1},
    };
    void make_main_menu();

    QThread        *m_thread = nullptr;
    UnixClient *unix_client = nullptr;


public slots:
    void onPageSelected(int page);

//    void onSendButtonClicked();
        void onClientMessage(const QString &msg);
        void onClientConnected();
        void onClientDisconnected();
        void onClientError(const QString &err);

};
#endif // MAINWINDOW_H
