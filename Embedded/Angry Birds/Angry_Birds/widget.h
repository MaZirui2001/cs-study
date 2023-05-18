#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QLineEdit>
#include <QGroupBox>
#include "start.h"
#include <QApplication>
#include <QPainter>

class Widget : public QWidget
{
    Q_OBJECT
signals:
    void login_successed();//发射登录成功的信号，用来触发跳转到下一个界面
public slots:
    void regiser(bool);
    void login(bool);
    void exit(){
        QApplication* app;
        app->exit(0);
    }

public:
    Widget(QWidget *parent = 0);
    QPixmap show_;
    QPixmap hide_;
    QPixmap log_;
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);



private:
    QLineEdit *le_account;
    QLineEdit *le_password;
    QPushButton *bt_rgt;
    QPushButton *bt_log;

    bool show_key;

    QWidget *box;
    QSqlDatabase db;

    Start *start_ui;
};

#endif // WIDGET_H
