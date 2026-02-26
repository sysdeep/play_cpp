#include "containers_page.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QStringList>
#include <QString>
#include <QNetworkRequest>
#include "docker/containers_parser.hpp"
#include <iostream>
#include <QList>
#include <QPushButton>

ContainersPage::ContainersPage(QWidget* parent): QWidget(parent)
{

    QList<QString> labels{
        QString("Names"),
        QString("Id"),
        QString("Image"),
        QString("State"),
        QString("Status"),
    };


    this->list = new QTreeWidget();
    this->list->setHeaderLabels(QStringList(labels));

    btn_refresh = new QPushButton("Refresh");
    connect(btn_refresh, &QPushButton::clicked, this, &ContainersPage::doContainersRequest);

    auto main_layout = new QVBoxLayout(this);

    main_layout->addWidget(new QLabel("Containers page"));
    main_layout->addWidget(this->list);
    main_layout->addWidget(btn_refresh);

    // net
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ContainersPage::onManagerFinished);



    // FAIL: доступно только с версии 6.8
//    auto request = QNetworkRequest(QUrl("unix+http://localhost/containers/json"));
//    request.setAttribute(QNetworkRequest::LocalServerNameAttribute, "/var/run/docker.sock");

//    manager->get(request);

    // /containers/json
    // QUrl url("unix+http://localhost/path/on/server");
    // /var/run/docker.sock
    // "http:/v1.24"

    // start ----------------------------------------------
    this->doContainersRequest();

}

void ContainersPage::fill_table(std::vector<docker::Container> containers)
{
    this->list->clear();

    for(auto const &container : containers){
        std::string container_name{};
        if(container.Names.size() > 0){
            container_name = container.Names[0];
        }
        QList<QString> values{
            QString::fromStdString(container_name),
            QString::fromStdString(container.Id),
            QString::fromStdString(container.Image),
            QString::fromStdString(container.State),
            QString::fromStdString(container.Status),
        };

        this->list->addTopLevelItem(new QTreeWidgetItem(this->list, QStringList(values)));
    }


}

void ContainersPage::onManagerFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        // Read the data from the reply
        QByteArray responseData = reply->readAll();
//      qDebug() << "Response:" << responseData;

        auto payloadJson = responseData.toStdString();
        auto containers = docker::parseContainers(payloadJson);

        this->fill_table(containers);

    } else {
        qDebug() << "Error:" << reply->errorString();
    }

    // The reply object must be deleted after use
    reply->deleteLater();
}

void ContainersPage::doContainersRequest()
{
    manager->get(QNetworkRequest(QUrl("http://localhost:2375/containers/json")));
}
