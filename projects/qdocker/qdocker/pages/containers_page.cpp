#include "containers_page.hpp"
#include <QVBoxLayout>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QNetworkRequest>

ContainersPage::ContainersPage(QWidget* parent): QWidget(parent)
{

    this->list = new QTreeWidget();

    auto main_layout = new QVBoxLayout(this);

    main_layout->addWidget(new QLabel("Containers page"));
    main_layout->addWidget(this->list);

    // net
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ContainersPage::onManagerFinished);

    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));

    // FAIL: доступно только с версии 6.8
//    auto request = QNetworkRequest(QUrl("unix+http://localhost/containers/json"));
//    request.setAttribute(QNetworkRequest::LocalServerNameAttribute, "/var/run/docker.sock");

//    manager->get(request);

    // /containers/json
    // QUrl url("unix+http://localhost/path/on/server");
    // /var/run/docker.sock
    // "http:/v1.24"

}

void ContainersPage::onManagerFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
            // Read the data from the reply
            QByteArray responseData = reply->readAll();
            qDebug() << "Response:" << responseData;
        } else {
            qDebug() << "Error:" << reply->errorString();
        }

        // The reply object must be deleted after use
        reply->deleteLater();
}
