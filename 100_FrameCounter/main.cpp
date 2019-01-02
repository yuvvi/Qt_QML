#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "FrameCounter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    FrameCounter fcObj;
    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickWindow *wndw = qobject_cast<QQuickWindow*>(engine->rootObjects().at(0));
    fcObj.initFPScounter(wndw);

    return app.exec();
}
