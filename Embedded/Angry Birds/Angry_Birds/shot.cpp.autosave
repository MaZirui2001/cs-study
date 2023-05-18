#include "shot.h"
#include <QMouseEvent>
#include <QPainter>
#include <QIcon>
#include <QMessageBox>
//#include <//qDebug>

void slingshot::debug(){
    //qDebug("ok");
}
slingshot::slingshot(int xx ,QWidget *parent)
    : QWidget(parent)
{
    //posline = QPoint(465, 551);
    posline = QPoint(124, 154);
    pullflag = false;
//    setFixedSize(1800, 967);
    setFixedSize(480, 270);
    // setGeometry(70,50,1800,967);
    setGeometry(0, 0, 480, 270);
    this->setWindowIcon(QIcon(":/img/yellow_bird.png"));
    this->setWindowTitle("Angry Birds");
    check = new datacheck(xx, this);    //选择小鸟的关数
    connect(check->b, SIGNAL(bird_slig(QPoint)), this, SLOT(slig(QPoint)));
    bk.load(":/img/bord.jpg");
    ex.load(":/img/exit.png");


    connect(this, SIGNAL(Releaseline()), this, SLOT(set_timer()));
    connect(check->b->timer, SIGNAL(timeout()), this, SLOT(emit_port()));
    connect(check->b->timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(this, SIGNAL(info(qreal, qreal, qreal, qreal)), check->b, SLOT(port(qreal, qreal, qreal, qreal)));

}
void slingshot::paintEvent(QPaintEvent *event)
{
    //画弹弓支架
    QPainter p(this);
    // p.drawPixmap(0, 0, 1800,967, QPixmap(":/img/bord.jpg"));
    p.drawPixmap(0, 0, 480, 270, bk);
    //p.drawPixmap(1740, 10, 50, 50, QPixmap(":/img/exit.png"));
    p.drawPixmap(460, 0, 20, 20, ex);
    QPen pen; //画笔，画线用
//    pen.setWidth(10);
    pen.setWidth(3);
    p.setPen(pen);//把笔给画家
//    p.drawLine(QPoint(460,616), QPoint(440, 546));
//    p.drawLine(QPoint(460,616), QPoint(490, 556));
//    p.drawLine(QPoint(460,616), QPoint(460, 726));
    p.drawLine(QPoint(123,172), QPoint(117, 152));
    p.drawLine(QPoint(123,172), QPoint(131, 155));
    p.drawLine(QPoint(123,172), QPoint(123, 203));

    //画弹弓皮筋
    QPainter plin1(this);
    QPainter plin2(this);
    pen.setColor(Qt::red);
    plin1.setPen(pen);
    plin2.setPen(pen);
//    plin1.drawLine(QPoint(440,546), posline);
//    plin2.drawLine(posline, QPoint(490, 556));
    plin1.drawLine(QPoint(117,152), posline);
    plin2.drawLine(posline, QPoint(131, 155));
    //画中心拉力点
    QPainter point(this);
    pen.setWidth(6);
    pen.setColor(Qt::black);
    point.setPen(pen);//把笔给画家
    point.drawPoint(posline);

    //qDebug() << pullflag << "pullflag";

}
void slingshot::mouseMoveEvent(QMouseEvent *event)
{
    //判断拉动皮筋
    //qDebug() << event->pos().x() << event->pos().y();
    if(event->pos().x() > 117 && event->pos().x() < 131 && event->pos().y() > 152 && event->pos().y() < 155)
        pullflag = true;
    if(pullflag && event->pos().x() >0 && event->pos().x() < 480 && event->pos().y() > 0 && event->pos().y() < 270)
        posline = event->pos();
    update();
}
void slingshot::mouseReleaseEvent(QMouseEvent *event)
{
//    if(check->b->flag_move == false)
//        posline = QPoint(465, 551);
    check->b->flag_move = false;
    //判断在拉动皮筋后松开皮筋
    if(pullflag)
    {
        pullflag = false;
        emit Releaseline();
        //qDebug("realease");
        check->b->current_vx = check->b->current_vy = 0;
        vx = 124 - posline.x();
        vy = 130 - posline.y();
        resistance_const = 0.0003;
        accg = 15.6;
//        posline = QPoint(465, 551);
        posline = QPoint(124, 154);
        pullflag = false;
    }
    update();
}
void slingshot::mousePressEvent(QMouseEvent *event)
{
    //退出游戏
    if(event->pos().x() > 460 && event->pos().x() < 480 && event->pos().y() > 0 && event->pos().y() < 20)
    {
          QMessageBox msgBox;
          msgBox.setWindowIcon(QIcon(":/img/red_bird.png"));
          msgBox.setIconPixmap(QPixmap(":/img/icon.png"));
          msgBox.setText("Are you sure to exit ?");
          msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
          if( QMessageBox::Yes == msgBox.exec())
          {
              emit backto();
              hide();//隐藏当前界面
          }
    }
}

void slingshot::slig(QPoint p)
{
    //判断拉动皮筋
//    if(p.x() > 440 && p.x() < 490 && p.y() > 546 && p.y() < 556)
//        pullflag = true;
//    //qDebug() << check->b->current_vx << check->b->current_vy;
    if(check->b->current_vx != 0 || check->b->current_vy != 0){
        pullflag = false;
        return;
      }
    else pullflag = true;
//    posline = p;
//    pullflag = true;
    if(pullflag == true)
    {
        if(pullflag && p.x() >27 && p.x() < 203 && p.y() > 67 && p.y() < 235)
            posline = p;
    }else {
//        posline = QPoint(465, 551);
        posline = QPoint(124, 154);
    }

    if(check->b->flag_move == false)
    {
        //posline = QPoint(465, 551);
        posline = QPoint(124, 154);
    }


    update();
}
