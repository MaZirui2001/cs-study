#include "choosepoint.h"
#include <QMenuBar>
#include <QPainter>
//#include <QDebug>
#include "mybushbutton.h"
#include <QTimer>
#include <QLabel>


choosepoint::choosepoint(QWidget *parent) : QMainWindow(parent)
{
    //选择关卡场景
    setFixedSize(480,270);
    setGeometry(0,0,480,270);
    this->setWindowIcon(QIcon(":/img/icon.png"));
    this->setWindowTitle("scene");
    pix.load(":/img/background.jpeg");
    //返回按钮
    mybushbutton * backbtn = new mybushbutton(":/img/BackButton.png",":/img/BackButtonSelected.png");

    backbtn->setParent(this);
    backbtn->move(400, 0);
    backbtn->resize(20, 10);
    //跳转到上一个界面
    connect(backbtn, SIGNAL(clicked()),this, SLOT(hide_itself()));
    int i;
    //跳转到关卡界面   创建选择关卡的按钮
    for( i = 0; i < 20; i++)
    {
        mybushbutton * menubtn = new mybushbutton(":/img/LevelIcon.png");

        menubtn->setParent(this);

        menubtn->move( 50 + i % 5 * 76, 35 + i / 5 * 50);  //一维数构造二维数组
//        connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot()));
        switch(i){
            case 0: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot1())); break;
            case 1: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot2())); break;
            case 2: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot3())); break;
            case 3: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot4())); break;
            case 4: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot5())); break;
            case 5: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot6())); break;
            case 6: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot7())); break;
            case 7: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot8())); break;
            case 8: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot9())); break;
            case 9: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot10())); break;
            case 10: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot11())); break;
            case 11: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot12())); break;
            case 12: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot13())); break;
            case 13: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot14())); break;
            case 14: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot15())); break;
            case 15: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot16())); break;
            case 16: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot17())); break;
            case 17: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot18())); break;
            case 18: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot19())); break;
            case 19: connect(menubtn, SIGNAL(clicked()), this, SLOT(create_slot20())); break;
        default:;

        }


        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menubtn->width(),menubtn->height());
        label->setText(QString::number(i+1));
        label->move(50 + i % 5 * 76, 35 + i / 5 * 50);

        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt:: AlignVCenter);
        //设置鼠标穿透事件  51号
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}
//重写绘图事件
void choosepoint::hide_itself(){
    emit this->choosesceneback(); //为了看到动画效果
    hide();
}
void choosepoint::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //加载图片

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void choosepoint::create_slot1(){
    this->hide();//隐藏当前界面
    shot = new slingshot(1);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));

}
void choosepoint::create_slot2(){
    this->hide();//隐藏当前界面
    shot = new slingshot(2);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot3(){
    this->hide();//隐藏当前界面
    shot = new slingshot(3);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot4(){
    this->hide();//隐藏当前界面
    shot = new slingshot(4);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}

void choosepoint::create_slot5(){
    this->hide();//隐藏当前界面
    shot = new slingshot(5);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot6(){
    this->hide();//隐藏当前界面
    shot = new slingshot(6);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot7(){
    this->hide();//隐藏当前界面
    shot = new slingshot(7);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot8(){
    this->hide();//隐藏当前界面
    shot = new slingshot(8);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot9(){
    this->hide();//隐藏当前界面
    shot = new slingshot(9);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot10(){
    this->hide();//隐藏当前界面
    shot = new slingshot(10);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot11(){
    this->hide();//隐藏当前界面
    shot = new slingshot(11);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot12(){
    this->hide();//隐藏当前界面
    shot = new slingshot(12);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}

void choosepoint::create_slot13(){
    this->hide();//隐藏当前界面
    shot = new slingshot(13);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot14(){
    this->hide();//隐藏当前界面
    shot = new slingshot(14);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot15(){
    this->hide();//隐藏当前界面
    shot = new slingshot(15);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot16(){
    this->hide();//隐藏当前界面
    shot = new slingshot(16);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot17(){
    this->hide();//隐藏当前界面
    shot = new slingshot(17);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot18(){
    this->hide();//隐藏当前界面
    shot = new slingshot(18);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot19(){
    this->hide();//隐藏当前界面
    shot = new slingshot(19);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
void choosepoint::create_slot20(){
    this->hide();//隐藏当前界面
    shot = new slingshot(20);
    shot->setGeometry(this->geometry());
    shot->show();
    connect(shot, SIGNAL(backto()), this, SLOT(game_go_back()));
}
