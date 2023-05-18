#include "obstacles.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QTimer>

ObstAcles::ObstAcles(QString normalImg)
{
    ImagPath = normalImg;
    pix = new QPixmap;
    bool ret = pix->load(normalImg);
    if(!ret){
        qDebug() << "图片加载失败";
        return;
    }
    setFixedSize(pix->width() / 4, pix->height() / 4);

    *pix = pix->scaled(pix->width() / 4 , pix->height() / 4);
    setMask( pix->mask() );
    setMinimumHeight(pix->height() / 4);
    setMinimumWidth(pix->width() / 4);

    mid_width = pix->width() / 8;
    mid_height = pix->width() / 8;

    //qDebug() << "obsacles " << "w " << mid_width << "h " << mid_height;

    mid_pos = new QPoint(pix->width() / 8, pix->height() / 4);

}

void ObstAcles::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawPixmap(0, 0, *pix);

}
