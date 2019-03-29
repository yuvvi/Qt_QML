#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "applicationlayer.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    /*------------------------------------------------------
     *          EXPORT CLASS AS COMPONENT
     * -----------------------------------------------------
     * (arg1: import module name.Ex: import ApplnLayer 1.0
     * arg2: Major version
     * arg3: Minor version
     * arg4: component name to be used in QML)*/
    qmlRegisterType<ApplicationLayer>("ApplnLayer",1,0,"Applyr_comp");
    /*------------------------------------------------------
     *          EXPORT CLASS OBJECT
     * -----------------------------------------------------
     *
     * */
    ApplicationLayer *al_obj = new ApplicationLayer;
    engine.rootContext()->setContextProperty("appObj",al_obj);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
