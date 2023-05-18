#ifndef MYBUSHBUTTON_H
#define MYBUSHBUTTON_H

#include <QPushButton>

class mybushbutton : public QPushButton
{
    Q_OBJECT
public:
    //构造函数  参数1 正常显示的图片路径 参数2 按下后显示的图片路径
    mybushbutton(QString normalImg,QString pressImg = "");

    //成员属性 保存用户传入的默认显示路径 按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();
    void zoom2();
    //重写按钮 按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);



signals:
};

#endif // MYBUSHBUTTON_H
