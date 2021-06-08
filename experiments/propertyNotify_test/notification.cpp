#include "notification.h"

notification::notification(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
    mTimer = new QTimer(this);
    connect(mTimer,SIGNAL(timeout()),this,SLOT(slt_timerTriggered()));
    mTimer->start(3000);
}

int notification::getData()
{
    qDebug()<<Q_FUNC_INFO<<" #data :"<<m_data;
    return m_data;
}

QString notification::getStrData()
{
    qDebug()<<Q_FUNC_INFO<<" #data :"<<m_data;
    return m_StrData;
}

void notification::setMystrData(QString str)
{
    qDebug()<<Q_FUNC_INFO<<" #data :"<<str;
    m_StrData = str;
}

void notification::slt_timerTriggered()
{
    qDebug()<<Q_FUNC_INFO;
    m_data = m_data + 1;
//    m_StrData = QString::number(m_data);
    setMystrData(QString::number(m_data));
    m_overclock = !m_overclock;
    emit overclockCPU();
    emit myTimerTriggered();
}
