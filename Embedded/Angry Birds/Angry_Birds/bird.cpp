#include "bird.h"
#include <QPixmap>
//#include <//qDebug>
#include <QBitmap>
#include <QPainter>
#include <QTimer>

bird::bird(QString normalImg)
{
    ImagPath = normalImg;
    pix = new QPixmap;
    time = 0;
    current_vx = 0;
    current_vy = 0;

    bool ret = pix->load(normalImg);
    if(!ret){
        //qDebug() << "图片加载失败";
        return;
    }
    *pix = pix->scaled(pix->width() * 0.02, pix->height() * 0.02);
    setFixedSize(pix->width() * 0.02, pix->height() * 0.02);
//    setGeometry(0, 0, 480, 270);;
    setMask( pix->mask() );
    setMinimumHeight(pix->height());
    setMinimumWidth(pix->width());

    mid_width = pix->width() * 0.008;
    mid_height = pix->height() * 0.008;

    //qDebug() << "brid " << "w " << mid_width << "h " << mid_height;

    mid_pos = new QPoint(pix->width() * 0.008 / 2, pix->height() * 0.008 / 2);

    time = 0;
    bird_weight = 3;
    vx_flag = true;
    flag_move = false;

    timer = new QTimer(this);
}

void bird::port(qreal vx, qreal vy, qreal resistance_const, qreal accg)
{
    if(current_vy == 0 && current_vx == 0 && time == 0)
    {
        current_vx = vx;
        current_vy = vy;
        if(vy > 0)
        {
            flag = true;
        }else {
            flag = false;
        }

        this->resistance_const = resistance_const;
        this->accg = accg;
    }

   if(time == 0)
   {
        wpos = this->geometry().topLeft();
        track_x = track_y = 0;
   }

    resistance_ax = resistance_const * current_vx * current_vx / bird_weight;
    last_vx = current_vx;
    if(current_vx > 0)
    {
        current_vx -= (resistance_ax + 0.4 * 0.01);
    }else if(current_vx < 0)
    {
        current_vx += (resistance_ax + 0.4 * 0.01);
    }
    if(flag == true)
    {
        current_vy +=  (accg * 0.1 - 0.9);
        energy -= (accg * 0.1 + 0.9);
        if(energy < 0)
            flag = false;
    }else
    {
        current_vy +=  (accg * 0.1 + 0.9);
        energy += (accg * 0.1);
        if(current_vy > 0)
            flag = true;
    }


    if( qAbs(current_vx + last_vx) != qAbs(qAbs(current_vx) + qAbs(last_vx)) ) //单位统一
    {
        vx_flag = false;
    }

    time += 0.1;


    if(vx_flag == true) //  x方向上的运动
    {
        track_x += current_vx * 0.1;

    }
        track_y += current_vy * 0.1;


    move(wpos.x() +track_x , wpos.y() + track_y);
    if(wpos.x() + track_x > 480 || wpos.y() + track_y  > 185 || wpos.y() + track_y < 0 ||
            wpos.x() + track_x < 0 || (current_vx == 0 && current_vy == 0))   //超过界面范围、速度为0重置小鸟
    {
        move(19 , 174);
        timer->stop();
        time = 0;
        track_x = track_y = 0;
        current_vx = 0;
        current_vy = 0;
    }
    emit bird_move(QPoint(geometry().topLeft().x() + width() / 2,
                          geometry().topLeft().y() + height() / 2));

}

void bird::mouseMoveEvent(QMouseEvent *event)   //重写鼠标事件，时小鸟可拖动
{
    if(current_vx != 0 || current_vy != 0) return;
    pos1 = event->globalPos();


    move(wpos.x()+pos1.x()-pos.x(),
         wpos.y()+pos1.y()-pos.y());
    emit bird_slig(QPoint(geometry().topLeft().x() + width()/2,
                          geometry().topLeft().y() + height()/2));

}

void bird::mousePressEvent(QMouseEvent *event)
{
    if(current_vx != 0 || current_vy != 0) return;
        flag_move = true;
        pos = event->globalPos();
        wpos = this->geometry().topLeft();

        if(event->buttons() ==  Qt::RightButton)
        {

            current_vx = current_vy = 0;
        }

}

void bird::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawPixmap(0, 0, *pix);

}
