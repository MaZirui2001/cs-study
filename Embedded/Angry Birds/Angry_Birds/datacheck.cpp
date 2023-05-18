#include "datacheck.h"
//#include <QDebug>
#include <QTimer>
#include <QtGlobal>

datacheck::datacheck(int c, QWidget * shot) //c为关卡 shot为关卡界面
{
    QVector< QPoint > v1;
    b = new bird(":/img/red_bird.png");
    b->setParent(shot);
    b->move(19 , 173);

    flag = true;

    if(c == 1)
    {
        for(int i = 0; i < 10; i++)
        {
            acl_1 = new ObstAcles(":/img/obstacles_1.png");
            acl_1->setParent(shot);
            acl_1->move(91 + i%10 * acl_1->width(), 39 + i/10 * acl_1->height());
            v1.push_back(QPoint(acl_1->mid_pos->x() + acl_1->geometry().topLeft().x() ,
                                acl_1->mid_pos->y() + acl_1->geometry().topLeft().y()));
        }

        for(int i = 0; i < 10; i++)
        {
            acl_2 = new ObstAcles(":/img/obstacles_2.png");
            acl_2->setParent(shot);
            acl_2->move(0 + i%10 * acl_2->width(), 95 + i/10 * acl_2->height());
            v1.push_back(QPoint(acl_2->mid_pos->x() + acl_2->geometry().topLeft().x() ,
                                acl_2->mid_pos->y() + acl_2->geometry().topLeft().y()));
        }

        for(int i = 0; i < 10; i++)
        {
            acl_3 = new ObstAcles(":/img/obstacles_3.png");
            acl_3->setParent(shot);
            acl_3->move(181 + i%10 * acl_3->width(), 95 + i/10 * acl_3->height());
            v1.push_back(QPoint(acl_3->mid_pos->x() + acl_3->geometry().topLeft().x() ,
                                acl_3->mid_pos->y() + acl_3->geometry().topLeft().y()));
        }

        for(int i = 0; i < 5; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(173 + i%10 * p->width(),181 + i/10 * p->height());
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }

    }

    if(c == 2)
    {
        for(int i = 0; i < 10; i++)
        {
            acl_1 = new ObstAcles(":/img/obstacles_1.png");
            acl_1->setParent(shot);
            acl_1->move(91 + i%10 * acl_1->width(), 103 + i/10 * acl_1->height());
            v1.push_back(QPoint(acl_1->mid_pos->x() + acl_1->geometry().topLeft().x() ,
                                acl_1->mid_pos->y() + acl_1->geometry().topLeft().y()));
        }

        for(int i = 0; i < 10; i++)
        {
            acl_2 = new ObstAcles(":/img/obstacles_2.png");
            acl_2->setParent(shot);
            acl_2->move(0 + i%10 * acl_2->width(), 57 + i/10 * acl_2->height());
            v1.push_back(QPoint(acl_2->mid_pos->x() + acl_2->geometry().topLeft().x() ,
                                acl_2->mid_pos->y() + acl_2->geometry().topLeft().y()));
        }

        for(int i = 0; i < 10; i++)
        {
            acl_3 = new ObstAcles(":/img/obstacles_3.png");
            acl_3->setParent(shot);
            acl_3->move(181 + i%10 * acl_3->width(), 57 + i/10 * acl_3->height());
            v1.push_back(QPoint(acl_3->mid_pos->x() + acl_3->geometry().topLeft().x() ,
                                acl_3->mid_pos->y() + acl_3->geometry().topLeft().y()));
        }

        for(int i = 0; i < 5; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(173 + i%10 * p->width(), 181 + i/10 * p->height());
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }

    }

    if(c == 3)
    {
        for(int i = 0; i < 20; i++)
        {
            acl_1 = new ObstAcles(":/img/obstacles_1.png");
            acl_1->setParent(shot);
            acl_1->move(0 + i%1 * acl_1->width(), 0 + i/1 * acl_1->height());
            v1.push_back(QPoint(acl_1->mid_pos->x() + acl_1->geometry().topLeft().x() ,
                                acl_1->mid_pos->y() + acl_1->geometry().topLeft().y()));
        }

        for(int i = 0; i < 20; i++)
        {
            acl_2 = new ObstAcles(":/img/obstacles_2.png");
            acl_2->setParent(shot);
            acl_2->move(423 + i%1 * acl_2->width(), 0 + i/1 * acl_2->height());
            v1.push_back(QPoint(acl_2->mid_pos->x() + acl_2->geometry().topLeft().x() ,
                                acl_2->mid_pos->y() + acl_2->geometry().topLeft().y()));
        }

        for(int i = 0; i < 30; i++)
        {
            acl_3 = new ObstAcles(":/img/obstacles_3.png");
            acl_3->setParent(shot);
            acl_3->move(0 + i%30 * acl_3->width(), 207 + i/30 * acl_3->height());
            v1.push_back(QPoint(acl_3->mid_pos->x() + acl_3->geometry().topLeft().x() ,
                                acl_3->mid_pos->y() + acl_3->geometry().topLeft().y()));
        }

        for(int i = 0; i < 9; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(353 + i%3 * p->width(), 150 + i/3 * p->height());
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }

    }
    if(c == 4)
    {
        for(int i = 0; i < 20; i++)
        {
            acl_1 = new ObstAcles(":/img/obstacles_1.png");
            acl_1->setParent(shot);
            acl_1->move(0 + i%1 * acl_1->width(), 30 + i/1 * acl_1->height());
            v1.push_back(QPoint(acl_1->mid_pos->x() + acl_1->geometry().topLeft().x() ,
                                acl_1->mid_pos->y() + acl_1->geometry().topLeft().y()));
        }

        for(int i = 0; i < 20; i++)
        {
            acl_2 = new ObstAcles(":/img/obstacles_2.png");
            acl_2->setParent(shot);
            acl_2->move(400 + i%1 * acl_2->width(), 0 + i/1 * acl_2->height());
            v1.push_back(QPoint(acl_2->mid_pos->x() + acl_2->geometry().topLeft().x() ,
                                acl_2->mid_pos->y() + acl_2->geometry().topLeft().y()));
        }

        for(int i = 0; i < 30; i++)
        {
            acl_3 = new ObstAcles(":/img/obstacles_3.png");
            acl_3->setParent(shot);
            acl_3->move(0 + i%30 * acl_3->width(), 207 + i/30 * acl_3->height());
            v1.push_back(QPoint(acl_3->mid_pos->x() + acl_3->geometry().topLeft().x() ,
                                acl_3->mid_pos->y() + acl_3->geometry().topLeft().y()));
        }
        for(int i = 0; i < 30; i++)
        {
            acl_3 = new ObstAcles(":/img/obstacles_3.png");
            acl_3->setParent(shot);
            acl_3->move(0 + i%30 * acl_3->width(), 20 + i/30 * acl_3->height());
            v1.push_back(QPoint(acl_3->mid_pos->x() + acl_3->geometry().topLeft().x() ,
                                acl_3->mid_pos->y() + acl_3->geometry().topLeft().y()));
        }


        for(int i = 0; i < 3; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(173 + i%3 * p->width(), 181 + i/3 * p->height());
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }
        for(int i = 0; i < 5; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(27 + i%3 * p->width()*2, 40 + i/3 * p->height()*2);
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }
        for(int i = 0; i < 6; i ++)
        {
            p = new pig;
            p->setParent(shot);
            p->move(96 + i%2 * p->width(), 56 + i/2 * p->height());
            ppoint.push_back(QPoint(p->mid_pos->x() + p->geometry().topLeft().x() ,
                                    p->mid_pos->y() + p->geometry().topLeft().y()));

            ppig.push_back(p);
        }

    }



    mpoint.insert(1, v1);


    v1.clear();
    //测试数据
    for( QMap<int, QVector< QPoint > >::iterator it = mpoint.begin();it != mpoint.end();it++ )
    {
         for(QVector<QPoint>::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
         {
             qDebug() << it2->x() << it2->y();
         }
         qDebug() << endl;
    }

    connect(b, SIGNAL(bird_move(QPoint)), this,
            SLOT(Pig_Crash(QPoint))); //小鸟与猪碰撞

    connect(b, SIGNAL(bird_move(QPoint)),
            this, SLOT(Crash(QPoint)));   //小鸟与墙碰撞

    connect(this, SIGNAL(Crash_sign(int)), this,
            SLOT(cope_collision(int)));

}
void datacheck::cope_collision(int direc){
    if(direc == 0)
    {
        qDebug() << "sss";
        b->current_vy *= (-1);

    }
    //下碰撞
    else if(direc == 1)
    {

        qDebug() << "sss";
        b->current_vy *= (-1);

    }
    //左碰撞
    else if(direc == 2)
    {

        b->current_vx *= (-1);

    }
    //右碰撞
    else if(direc == 3)
    {

        b->current_vx *= (-1);

    }
    //对角碰撞
    else
    {
        b->current_vx *= (-1);
        b->current_vy *= (-1);


    }

}
void datacheck::Pig_Crash(QPoint pos)
{
         QVector<pig *>::iterator it1 = ppig.begin();
         for(QVector<QPoint>::iterator it2 = ppoint.begin(); it2!= ppoint.end();it2++)
         {
             if(flag == true)
             {
             if(qAbs(it2->x() - pos.x()) <= qAbs(10) && qAbs(it2->y() - pos.y()) <= qAbs(10) )
             {
                 //碰撞
                 p->boom(*it1);
                 qDebug() << "collision pig" << it2->x() << it2->y();
             }
             }else
             {
                 QTimer::singleShot(400, this, SLOT(setflag()));
             }
             it1++;
         }
}



void datacheck::Crash(QPoint pos)
{
    int count = 0;
    for( QMap<int, QVector< QPoint > >::iterator it = mpoint.begin();it != mpoint.end();it++ )
    {

         for(QVector<QPoint>::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
         {

             if(flag == true)
             {
             if(qAbs(it2->x() - pos.x()) <= qAbs(30) && qAbs(it2->y() - pos.y()) <= qAbs(30) )
             {
                 //碰撞

                 qDebug() << "collision" << it2->x() << it2->y();


                 if( (it2->x() - pos.x()) > 0 && (it2->y() - pos.y()) > 0)
                 {

                     if(qAbs(it2->x() - pos.x()) - qAbs(it2->y() - pos.y()) > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "left";
                         emit Crash_sign(2);

                     }else if(qAbs(it2->y() - pos.y())  - qAbs(it2->x() - pos.x())  > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "up";
                         emit Crash_sign(0);
                     }else
                     {
                         emit Crash_sign(4);
                         //对角撞
                     }

                     //第二象限
                     qDebug() << "2 xiangxian";
                 }else if( (it2->x() - pos.x()) > 0 && (it2->y() - pos.y()) < 0)
                 {
                     if(  qAbs(it2->x() - pos.x()) - qAbs(it2->y() - pos.y()) > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "left";
                         emit Crash_sign(2);
                     }else if(qAbs(it2->y() - pos.y()) - qAbs(it2->x() - pos.x())  > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "down";
                         emit Crash_sign(1);
                     }else
                     {
                         //对角撞
                         emit Crash_sign(5);
                     }
                     //第三象限
                     qDebug() << "3 xiangxian";
                 }else if( (it2->x() - pos.x()) < 0 && (it2->y() - pos.y()) > 0)
                 {
                     if(qAbs(it2->x() - pos.x()) > qAbs(it2->y() - pos.y()) &&  qAbs(it2->y() - pos.y()) > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "右边";
                         emit Crash_sign(3);
                     }else if(qAbs(it2->y() - pos.y()) - qAbs(it2->x() - pos.x())   > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "up";
                         emit Crash_sign(0);
                     }else
                     {
                         //对角撞
                         emit Crash_sign(6);
                     }
                     //第一象限
                     //qDebug() << "1 xiangxian";
                 }else if( (it2->x() - pos.x()) < 0 && (it2->y() - pos.y()) < 0)
                 {
                     if(qAbs(it2->x() - pos.x()) - qAbs(it2->y() - pos.y()) > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->x() - it2->x()) <= qAbs(30) && qAbs((it2+1)->x() - it2->x()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "right";
                         emit Crash_sign(3);
                     }else if(qAbs(it2->y() - pos.y()) - qAbs(it2->x() - pos.x())  > qAbs(0))
                     {

                         if((it2+1) != NULL)
                         {
                             if(qAbs((it2+1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         if((it2-1) != NULL)
                         {
                             if(qAbs((it2-1)->y() - it2->y()) <= qAbs(30) && qAbs((it2+1)->y() - it2->y()) >= qAbs(30))
                                 continue;
                         }
                         qDebug() << "down";
                         emit Crash_sign(1);
                     }else
                     {
                         //对角撞
                         emit Crash_sign(7);
                     }
                     //第四象限
                     qDebug() << "4 xiangxian";
                 }
                 flag = false;

                 }

             }else
             {
                 QTimer::singleShot(200, this, SLOT(setflag()));
             }
             count++;
         }
    }


}

void datacheck::paintEvent(QPaintEvent *event)
{

}

void datacheck::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << b->x() << b->y();
}

void datacheck::mousePressEvent(QMouseEvent *event)
{

}

