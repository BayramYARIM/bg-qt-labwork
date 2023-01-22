#include "nokta.h"
#include "resim.h"

nokta::nokta(QWidget *parent) : QLabel (parent)
{
    setScaledContents(true);
    QImage nok(":/res/images/nokta.png");
    setPixmap(QPixmap::fromImage(nok));
}

void nokta::mousePressEvent(QMouseEvent *event)
{
    //ilkKonum = event->pos();
}

void nokta::mouseReleaseEvent(QMouseEvent *event)
{
    /*int X = event->x() - ilkKonum.x() + x();
    int Y = event->y() - ilkKonum.y() + y();
    setGeometry(X, Y, 10, 10);
    resimAdres->cizBezier();*/
}

