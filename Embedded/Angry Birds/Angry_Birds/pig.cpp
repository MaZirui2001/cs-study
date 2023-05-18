#include "pig.h"
#include <QPainter>
#include <QTimer>
#include <QPixmap>

pig::pig()
{
    setFixedSize(16, 16);
    mid_pos = new QPoint(8, 8);
    pix.load(":/img/pig.png");

}
void pig::paintEvent(QPaintEvent *event)
{

     QPainter p1(this);
//     if(isboom)
//     {
//         QPainter p(pp);
//         p.drawPixmap(0, 0, 64,64, QPixmap(":/img/boom.png"));
//     }
//     else
        p1.drawPixmap(0, 0, 16,16, pix);
}
void pig::boom( pig *p)
{
    isboom = true;
    update();

    QTimer::singleShot(200, p, SLOT(hide()));
}

void pig::hide_pig(pig *p){
    p->hide();
}
