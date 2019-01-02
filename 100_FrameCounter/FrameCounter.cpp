#include "FrameCounter.h"

FrameCounter::FrameCounter()
{
//    m_refreshRate = 1;
    m_frameList << 0;
}

void FrameCounter::initFPScounter(QQuickWindow *window)
{
    m_timer.setTimerType(Qt::PreciseTimer);
    m_timer.setInterval(1000);

    QObject::connect(window, &QQuickWindow::frameSwapped,this,&FrameCounter::updateFrameCount);
    QObject::connect(&m_timer,&QTimer::timeout,this,&FrameCounter::displayFrameCount);
    m_timer.start();
}

FrameCounter::~FrameCounter()
{
}

void FrameCounter::updateFrameCount()
{
    qDebug()<<Q_FUNC_INFO<<endl;
    m_frameList.last()++;
}

void FrameCounter::displayFrameCount()
{
    unsigned int fps = 0;
    for(int i=0;i< m_frameList.count();i++){
        fps += m_frameList[i];
    }
    fps *= (1/float(m_frameList.count()));
    qDebug()<<"Framerate per Second : "<<fps<<endl;
    m_frameList << 0;
    if (m_frameList.count() > 1){
        m_frameList.removeFirst();
    }
}

