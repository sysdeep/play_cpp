#pragma once

#include <QWidget>
#include <QTreeWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ContainersPage: public QWidget
{
    Q_OBJECT
public:
    ContainersPage(QWidget* parent = nullptr);

private:
    QTreeWidget *list;
    QNetworkAccessManager *manager;

public slots:
    void onManagerFinished(QNetworkReply *reply);
};

