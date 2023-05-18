#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <QMouseEvent>
#include <QSqlQuery>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <mybushbutton.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //界面主题设置
    setFixedSize(480,270);
    setGeometry(0,0,480,270);
    this->setWindowIcon(QIcon(":/img/red_bird.png"));
    this->setWindowTitle("welcome");

//    this->setWindowFlags(Qt::FramelessWindowHint);
    show_key = true;
    //创建控件
    le_account = new QLineEdit ;
    le_account->setPlaceholderText("account");
    le_password = new QLineEdit ;
    le_password->setPlaceholderText("pass=word");
    bt_rgt = new QPushButton("register") ;
    bt_log = new QPushButton("login") ;
    //布局
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(bt_rgt);
    hbox->addWidget(bt_log);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(le_account);
    vbox->addWidget(le_password);
    vbox->addLayout(hbox);
    box = new QWidget;
    box->setLayout(vbox);
    box->setParent(this);
    box->setGeometry(250, 120,220,120);
    mybushbutton * backbtn = new mybushbutton(":/img/BackButton.png",":/img/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(0, 0);
    connect(backbtn, SIGNAL(clicked()),this, SLOT(exit()));
    //将按钮信号与对应信号与槽函数绑定
    connect(bt_rgt, SIGNAL(clicked(bool)), this, SLOT(regiser(bool)));
    connect(bt_log, SIGNAL(clicked(bool)), this, SLOT(login(bool)));

    //创建数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("userdb");
    db.open();
    //创建用户名注册表
    QString  str("create table usertable(account text, password text, username text, level text);");
    QSqlQuery query;
    query.exec(str);
    //界面跳转
    log_.load(":/img/log.jpeg");
    show_.load(":/img/show.jpeg");
    hide_.load(":/img/hide.jpeg");
    start_ui = new Start;
    connect(this, SIGNAL(login_successed()), start_ui, SLOT(show()));
    connect(start_ui, SIGNAL(back()), this, SLOT(show()));
}
void Widget::paintEvent(QPaintEvent *event)
{
    //画 界面 和 图标
    QPainter p(this);
    p.drawPixmap(0, 0, 480, 270, log_);
    if(show_key)
        p.drawPixmap(460, 250, 16, 16, show_);
    else
        p.drawPixmap(460, 250, 16, 16, hide_);
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    //点击密码的显示与隐藏
    if(event->pos().x() > 460 && event->pos().x() < 476 && event->pos().y() > 200 && event->pos().y() < 216)
    {
        show_key = !show_key;
        if(show_key)
            le_password->setEchoMode(QLineEdit::Normal);
        else
            le_password->setEchoMode(QLineEdit::Password);
    }
    update();
}
void Widget::regiser(bool)
{
    //查询用户是否已经存在
    QString  str = QString("select * from usertable where account='%0';")\
                                        .       arg(le_account->text());
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon(":/img/red_bird.png"));
        msgBox.setIconPixmap(QPixmap(":/img/icon.png"));
        msgBox.setText("exsited!");
        msgBox.exec();
        return ;
    }
    //不存在就注册
    bool ok;
    QString username = QInputDialog::getText(this, "Angry Birds",
                                               "User name:",QLineEdit::Normal,QDir::home().dirName(),
                                                &ok);

    if (ok && !username.isEmpty())
    {
        //向入据库中加入一条用户信息
        QString  str = QString("insert into usertable values('%0', '%1', '%2', '0');")\
                                .arg(le_account->text()).arg(le_password->text()).arg(username);//插入用户 账号，密码，用名
        QSqlQuery query;
        query.exec(str);

        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon(":/img/red_bird.png"));
        msgBox.setIconPixmap(QPixmap(":/img/icon.png"));
        msgBox.setText("good!success!");
        msgBox.exec();
    }
}
void Widget::login(bool)
{
//    emit login_successed();
//    hide();
    //账号√ 密码√
    QString  str = QString("select * from usertable where account='%0' and password='%1';")\
                                        .arg(le_account->text()).arg(le_password->text());
    QSqlQuery query;
    query.exec(str);
    while(query.next())
    {
        // // qDebug() << query.value(0).toString();
        // qDebug() << query.value(1).toString();
        // qDebug() << query.value(2).toString();
        // qDebug() << query.value(3).toString();
        emit login_successed();//发射登录成功的信号
        hide();//隐藏当前界面
        return ;
    }
    //账号√密码×
    str = QString("select * from usertable where account='%0';")\
                                        .arg(le_account->text());
    query.exec(str);
    while(query.next())
    {
        QMessageBox msgBox;
        msgBox.setWindowIcon(QIcon(":/img/red_bird.png"));
        msgBox.setIconPixmap(QPixmap(":/img/icon.png"));
        msgBox.setText("password wrong!");
        msgBox.exec();
        return ;
    }
    //账号x
    QMessageBox msgBox;
    msgBox.setWindowIcon(QIcon(":/img/red_bird.png"));
    msgBox.setIconPixmap(QPixmap(":/img/icon.png"));
    msgBox.setText("this user is not exsited!");
    msgBox.exec();
}
Widget::~Widget()
{

}
