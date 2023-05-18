#ifndef DATACHECK_H
#define DATACHECK_H

#include <QWidget>
#include "bird.h"
#include "obstacles.h"
#include <QPoint>
#include <QVector>
#include <QMap>
#include "pig.h"



class datacheck : public QObject
{
    Q_OBJECT
signals:
    void Crash_sign(int);

public slots:
    void Crash(QPoint);
    void Pig_Crash(QPoint);
    void cope_collision(int);
    void setflag() {flag = true;}

public:
    datacheck(int c,  QWidget * q);


    void paintEvent(QPaintEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);



    QMap<int, QVector<QPoint> >mpoint;
    QMap<int, QVector<QString> >mstring;
    QVector<QPoint> ppoint;
    QVector<pig *> ppig;

    bird * b;
    pig * p;
    ObstAcles * acl_1;
    ObstAcles * acl_2;
    ObstAcles * acl_3;
    ObstAcles * wood;

    int check;

    bool flag;



};
#endif // WIDGET_H
