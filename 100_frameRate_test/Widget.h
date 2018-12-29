#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QGraphicsView>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    ~Widget();

    QTime m_time;
    int m_frameCount;

};

#endif // WIDGET_H
