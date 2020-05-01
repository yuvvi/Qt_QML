#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "networkcommunication.h"
#include <qqml.h>


int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<NetworkCommunication>("com.network.xyz", 1, 0, "NetworkComm");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    NetworkCommunication ncobj;

    return app.exec();
}
