#ifndef RESIM_H
#define RESIM_H

#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>
#include <QList>
#include "nokta.h"

class resim : public QLabel
{
public:
    resim(QWidget *parant = 0);
    void cizBezier();
private:
    QRgb renk;
    QPoint ilkNokta, sonNokta;
    QImage res;
    void mousePressEvent(QMouseEvent*);
    int kontrol;
    QList<nokta*> noktalarB;
    QList<QPoint> noktalar;
    int faktoriyel(int);
    double Cfonksiyon(int,int);
    QPoint Bfonksiyon(double);
};

#endif // RESIM_H
