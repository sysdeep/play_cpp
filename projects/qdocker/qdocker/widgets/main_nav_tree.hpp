#pragma once

#include <QWidget>
#include <QTreeWidget>
#include "pages.hpp"

class MainNavTree : public QWidget
{
    Q_OBJECT
public:
    explicit MainNavTree(QWidget *parent = nullptr);

signals:
    void pageSelected(int);

private:
    QTreeWidget *tree;


};

