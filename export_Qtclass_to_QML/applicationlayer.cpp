#include "applicationlayer.h"

ApplicationLayer::ApplicationLayer(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<endl;
}

void ApplicationLayer::print_operation()
{
    qDebug()<<Q_FUNC_INFO<<endl;
}

int ApplicationLayer::printCount() const
{
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_printCount;
}

void ApplicationLayer::setPrintCount(int printCount)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(m_printCount == printCount)
        return;
    m_printCount = printCount;
    emit printCountChanged();
}
