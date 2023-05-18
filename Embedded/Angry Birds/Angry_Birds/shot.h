#ifndef SHOT_H
#define SHOT_H

#include <QWidget>
#include "bird.h"
#include "datacheck.h"
#include <QPoint>
#include <QTimer>
#include "shot.h"
#include <QMouseEvent>
#include <QPainter>
#include <QIcon>
#include <QMessageBox>
class slingshot : public QWidget
{
    Q_OBJECT

public slots:
    void slig(QPoint);
    void set_timer(){
//        qDebug() << "set" ;
        check->b->timer->start(30);
    }
    void debug();

    void emit_port(){
        emit this->info(vx, vy, resistance_const, accg);
    }

signals:
    void Releaseline();
    void backto();//返回上一个界面
    void info(qreal ,qreal ,qreal ,qreal);
    //lxy 2022/8/6


public:
    explicit slingshot(int xx, QWidget *parent = NULL);

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPixmap bk;
    QPixmap ex;
    //lxy 2022/8/6

    qreal vx;
    qreal vy;
    qreal resistance_const;
    qreal accg;



private:
    QPoint posline;//皮筋的起始位置
    bool pullflag;
    //lxy 2022/8/6
    datacheck * check;

    bool flag;

};

#endif // WIDGET_H
