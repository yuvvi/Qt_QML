#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "loggingtest.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    LoggingTest lgtobj;
    lgtobj.func();

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
