#include "start.h"
#include <QPainter>
#include <QMouseEvent>
#include "mybushbutton.h"

Start::Start(QWidget *parent) : QWidget(parent)
{
    setFixedSize(480,270);
    setGeometry(0,0,480,270);
    this->setWindowIcon(QIcon(":/img/icon.png"));
    this->setWindowTitle("AngryBirds");
    pix.load(":/img/start.jpg");
    mybushbutton * backbtn = new mybushbutton(":/img/BackButton.png",":/img/BackButtonSelected.png");

    backbtn->setParent(this);
    backbtn->move(400, 0);
    connect(backbtn, SIGNAL(clicked()),this, SLOT(hide_itself()));
    //界面跳转
    choose = new choosepoint;
    choose->setGeometry(0,0,480,270);
    choose->setWindowFlags(Qt::FramelessWindowHint);
    connect(this, SIGNAL(start()), choose, SLOT(show()));

    //绑定当前界面 发射的start开始游戏的信号 给选择关卡界面choose 让它显示
    connect(choose, SIGNAL(choosesceneback()), this, SLOT(show()));
}
void Start::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, 480, 270, pix);
}
void Start::mousePressEvent(QMouseEvent *event)
{
    //点击密码的显示与隐藏
    if(event->pos().x() > 200 && event->pos().x() < 270 && event->pos().y() > 100 && event->pos().y() < 170)
    {
        //qDebug("emit start");
        emit start();
        hide();//隐藏当前界面
    }
}
