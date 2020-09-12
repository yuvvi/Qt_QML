#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <qqml.h>
#include "cppsingleton.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    cppSingleton *cppSobj = cppSingleton::getNetworkinstance();
    cppSobj->setData("Hi ,welcome to cpp singleton");
    qDebug()<<"cpp:main :"<<cppSobj->getData()<<endl;
    qmlRegisterSingletonType<cppSingleton>("Qt.example.cppSingleton", 1, 0, "MySingleton",cppSingleton::getinstance);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qDebug()<<"main # cppsingleton :"<<QQmlEngine::objectOwnership(cppSobj)<<endl;
    qDebug()<<"0 - cppOwnerShip "<<endl<<"1 - QMLOwnerShip"<<endl;
    // 0 - cppOwnerShip
    // 1 - QMLOwnerShip
    return app.exec();
}
