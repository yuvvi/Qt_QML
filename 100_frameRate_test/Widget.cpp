#include "Widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent),m_frameCount(0)
{
    qDebug()<<Q_FUNC_INFO<<endl;
}

Widget::~Widget()
{

}

void Widget ::paintEvent(QPaintEvent *e) {
qDebug()<<Q_FUNC_INFO<<" #start"<<endl;
    if (m_frameCount == 0) {
        qDebug()<<Q_FUNC_INFO<<" : m_frameCount # "<<m_frameCount<<endl;
         m_time.start();
    } else {
        qDebug()<<Q_FUNC_INFO<<"1"<<endl;
        qDebug()<<"FPS1 : "<<m_time.elapsed() / float(m_frameCount)<<endl;
        qDebug()<<"FPS2 : "<<m_frameCount / (float(m_time.elapsed()) / 1000.0f)<<endl;
        qDebug()<<"FPS3 : "<<(m_frameCount / (float(m_time.elapsed()))) / 1000.0f<<endl;
    }
    m_frameCount++;
    qDebug()<<Q_FUNC_INFO<<" #end"<<endl;
  //  QDeclarativeView::paintEvent(event);
//
    paintEvent(e);

    // Painting goes here...

}
