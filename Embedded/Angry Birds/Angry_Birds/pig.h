#ifndef PIG_H
#define PIG_H

#include "QWidget"
#include <QPoint>

class pig : public QWidget
{
    Q_OBJECT
public:
    explicit pig();
    void paintEvent(QPaintEvent *event);
    QPoint *mid_pos;
    QPixmap pix;




signals:

public slots:
    void boom( pig *p);
    void hide_pig(pig *p);

private:
    bool isboom;// = false;

    pig* pp;

};

#endif // PIG_H
