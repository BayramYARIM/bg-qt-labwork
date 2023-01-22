#ifndef NOKTA_H
#define NOKTA_H

#include <QLabel>
#include <QMouseEvent>

class resim;

class nokta : public QLabel
{
    Q_OBJECT
public:

    nokta (QWidget *parent = 0);
    resim *resimAdres;
    QPoint ilkKonum;
};

#endif // NOKTA_H
