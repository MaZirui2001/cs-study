#ifndef CHOOSEPOINT_H
#define CHOOSEPOINT_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include "shot.h"
class choosepoint : public QMainWindow
{
    Q_OBJECT
public:
    explicit choosepoint(QWidget *parent = NULL);
    QPixmap pix;
    //重写绘图事件
    void paintEvent(QPaintEvent *);
public slots:
    void hide_itself();
    void create_slot1();
    void create_slot2();
    void create_slot3();
    void create_slot4();
    void create_slot5();
    void create_slot6();
    void create_slot7();
    void create_slot8();
    void create_slot9();
    void create_slot10();
    void create_slot11();
    void create_slot12();
    void create_slot13();
    void create_slot14();
    void create_slot15();
    void create_slot16();
    void create_slot17();
    void create_slot18();
    void create_slot19();
    void create_slot20();
    void game_go_back(){
        shot->deleteLater();
        this->show();
    }


signals:
    void choosesceneback();//返回上一个界面
    void level_1();//进入关卡 1

private:
    slingshot *shot;
};

#endif // CHOOSEPOINT_H
