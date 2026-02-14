#ifndef SPECIALLABEL_H
#define SPECIALLABEL_H

#include <QWidget>
#include <QLabel>

class SpecialLabel : public QLabel
{
    Q_OBJECT
public:
    explicit SpecialLabel(QLabel *parent = nullptr);

signals:
};

#endif // SPECIALLABEL_H
