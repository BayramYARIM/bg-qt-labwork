#include "resim.h"
#include <math.h>
#include <QApplication>
#include <qmath.h>
#include <math.h>

resim::resim(QWidget *parant) : QLabel(parant)
{
    renk = qRgb(255,255,255);
    QImage ortam(1024,768,QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(ortam));
    res = ortam;
    kontrol = 0;
}

void resim::mousePressEvent(QMouseEvent *event)
{
    //ilkNokta = event->pos();
    nokta *n = new nokta(this);
    n->setGeometry(event->x(), event->y(), 10, 10);
    n->resimAdres = this;
    n->show();
    noktalarB.push_back(n);
}

int resim::faktoriyel(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return faktoriyel(n - 1) * n;
    }
}

double resim::Cfonksiyon(int n, int i)
{
    return faktoriyel(n) / (faktoriyel(i) * (faktoriyel(n - i)));
}

QPoint resim::Bfonksiyon(double u)
{
    QPoint yeniNokta;
    double X = 0, Y = 0;
    for (int i = 0; i < noktalarB.size(); ++i) {
        X += noktalarB[i]->x() * Cfonksiyon(noktalarB.size() - 1, i) * pow(u, i) * pow(1 - u, (noktalarB.size() - 1) - i);
        Y += noktalarB[i]->y() * Cfonksiyon(noktalarB.size() - 1, i) * pow(u, i) * pow(1 - u, (noktalarB.size() - 1) - i);
    }
    yeniNokta.setX(round(X));
    yeniNokta.setY(round(Y));
    return yeniNokta;
}

void resim::cizBezier()
{
    QPoint nokta;
    double u = 0;
    while(u <= 1) {
        QApplication::processEvents();
        nokta = Bfonksiyon(u);
        res.setPixel(nokta.x(), nokta.y(), renk);
        setPixmap(QPixmap::fromImage(res));
        u += 0.001;
    }
}



