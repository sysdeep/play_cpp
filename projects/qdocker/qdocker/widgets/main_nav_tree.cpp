#include "main_nav_tree.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QTreeWidgetItem>
#include <QDebug>

MainNavTree::MainNavTree(QWidget *parent)
    : QWidget{parent}
{

    this->setMaximumWidth(300);

    auto main_layout = new QVBoxLayout(this);

    main_layout->addWidget(new QLabel("nav"));


    tree = new QTreeWidget();
    main_layout->addWidget(tree);

    // setup tree
    tree->setColumnCount(1);

    // add nav items
    auto docker_node = new QTreeWidgetItem(
                static_cast<QTreeWidget *>(nullptr),
                QStringList(QString("docker"))
                );

    // containers
    auto containers_node = new QTreeWidgetItem(
                                  static_cast<QTreeWidget *>(nullptr),
                                  QStringList(QString("containers"))
                                  );
    containers_node->setData(0, Qt::UserRole, PAGE_CONTAINERS);
    tree->addTopLevelItem(containers_node);

    // images
    auto images_node = new QTreeWidgetItem(
                                  docker_node,
                                  QStringList(QString("images"))
                                  );
    images_node->setData(0, Qt::UserRole, PAGE_IMAGES);
    docker_node->addChild(images_node);

    // swarm
    auto swarm_node = new QTreeWidgetItem(
                static_cast<QTreeWidget *>(nullptr),
                QStringList(QString("swarm"))
                );

    // config
    auto config_node = new QTreeWidgetItem(
                                  swarm_node,
                                  QStringList(QString("config"))
                                  );
    config_node->setData(0, Qt::UserRole, PAGE_IMAGES);
    swarm_node->addChild(config_node);


    tree->addTopLevelItem(docker_node);
    tree->addTopLevelItem(swarm_node);

    connect(tree, &QTreeWidget::itemClicked, [=](QTreeWidgetItem *item, int column){
       auto data = item->data(column, Qt::UserRole);
//       qDebug() << data;
       if(data.isValid()){
           int page = data.toInt();
//           qDebug() << "page: " << page;
           emit pageSelected(page);
       }
    });
}

