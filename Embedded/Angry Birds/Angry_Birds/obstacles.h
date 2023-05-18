#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QPoint>

class ObstAcles : public QWidget
{
    Q_OBJECT
public:
    explicit ObstAcles(QString normalImg);

    void paintEvent(QPaintEvent *event);

    QPoint *mid_pos;
    int mid_height;
    int mid_width;

signals:

private:
    QPixmap * pix;
    QString ImagPath;

};

#endif // OBSTACLES_H
