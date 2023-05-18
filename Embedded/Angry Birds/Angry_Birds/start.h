#ifndef START_H
#define START_H

#include <QWidget>
#include "choosepoint.h"

class Start : public QWidget
{
    Q_OBJECT
public:
    explicit Start(QWidget *parent = NULL);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPixmap pix;

signals:
    void start();//开始游戏，进入关卡选择界面
    void back();//返回上一个界面

public slots:
    void show_choose(){
        qDebug("get to choose");
        choose->show();
    }
    void hide_itself(){
        emit this->back(); //为了看到动画效果
        hide();
    }




public slots:

private:
    choosepoint *choose;
};

#endif // START_H
