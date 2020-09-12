#include "loggingtest.h"

Q_LOGGING_CATEGORY(NETWORK_LOG,"qt.app.max.network",QtWarningMsg)

LoggingTest::LoggingTest(QObject *parent) : QObject(parent)
{
//    export QT_LOGGING_RULES="qt.epgapp.info=true"

//    qCDebug(logtest)<<Q_FUNC_INFO<<endl;
//    if(qgetenv("QSG_INFO_1").compare("true")==0){
//    if (qEnvironmentVariableIsSet("QSG_INFO_1")){
//        ((QLoggingCategory &) QSG_LOG_INFO()).setEnabled(QtDebugMsg, true);
//    }else{
//        ((QLoggingCategory &) QSG_LOG_INFO()).setEnabled(QtDebugMsg, false);
//    }

    qCDebug(NETWORK_LOG)<<Q_FUNC_INFO;
}

LoggingTest::~LoggingTest()
{
    qDebug()<<Q_FUNC_INFO<<endl;
        qCDebug(NETWORK_LOG)<<Q_FUNC_INFO;
}

void LoggingTest::func()
{
    qDebug()<<Q_FUNC_INFO<<endl;
        qCDebug(NETWORK_LOG) <<Q_FUNC_INFO<<" - Debug -"<<endl;
        qCWarning(NETWORK_LOG) <<Q_FUNC_INFO<<" - Warning -"<<endl;
}

