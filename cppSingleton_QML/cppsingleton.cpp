#include "cppsingleton.h"

cppSingleton *cppSingleton::cppSobj=nullptr;


cppSingleton::cppSingleton(QObject *parent)
{
    qDebug()<<Q_FUNC_INFO<<endl;
}

cppSingleton *cppSingleton::getNetworkinstance()
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(cppSobj == nullptr){
        cppSobj = new cppSingleton;
    }
    return cppSobj;
}


QString cppSingleton::getData() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_data;
}

void cppSingleton::setData(const QString &data)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    m_data = data;
}

