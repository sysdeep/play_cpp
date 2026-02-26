#pragma once

#include <QWidget>
#include <QTreeWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "docker/containers_parser.hpp"
#include <vector>
#include <QPushButton>

class ContainersPage: public QWidget
{
    Q_OBJECT
public:
    ContainersPage(QWidget* parent = nullptr);

private:
    QTreeWidget *list;
    QPushButton *btn_refresh;
    QNetworkAccessManager *manager;

    void fill_table(std::vector<docker::Container> containers);

public slots:
    void onManagerFinished(QNetworkReply *reply);
    void doContainersRequest();
};

