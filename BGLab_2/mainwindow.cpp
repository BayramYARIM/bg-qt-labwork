#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setGeometry(0,0,600,600);
    ui->label->setFrameShape(QFrame::Box);
    ui->label->show();
    renk=qRgb(255,255,255);
    QImage ortam(600,600,QImage::Format_RGB32);
    ui->label->setPixmap(QPixmap::fromImage(ortam));
    resim=ortam;
    kontrol=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(kontrol==0)
    {
        ilkNokta=event->pos();
        kontrol++;
    }
    else
    {
        sonNokta=event->pos();
        kontrol=0;
        DogruCizDDA();
    }

}

void MainWindow::DogruCizDDA()
{
    double dx=sonNokta.x()-ilkNokta.x();
    double dy=sonNokta.y()-ilkNokta.y();
    double Xartim, Yartim;
    double adim;
    double x,y;

    if(fabs(dx)>fabs(dy))
    {
        adim=fabs(dx);
    }
    else
        adim=fabs(dy);

    Xartim=dx/adim;
    Yartim=dy/adim;

    x=ilkNokta.x();
    y=ilkNokta.y();

    for(int i=0; i<adim; i++)
    {
        x+=Xartim;
        y+=Yartim;
        resim.setPixel(round(x),round(y),renk);
        ui->label->setPixmap(QPixmap::fromImage(resim));

    }

}

