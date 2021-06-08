#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "notification.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    notification notiObj;
    engine.rootContext()->setContextProperty("notify",&notiObj);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
//    notification *notiObj1 = new notification;
//    qDebug()<<"1 condition Test :"<<(notiObj1 ? notiObj1 : 0)<<endl;
//    notiObj1 = nullptr;
//    qDebug()<<"2 condition Test :"<<(notiObj1 ? notiObj1 : (QObject*)0)<<endl;

    return app.exec();
}
