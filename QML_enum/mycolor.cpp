#include "mycolor.h"

MyColor::MyColor(QObject *parent) : QObject(parent)
{

}
/*qmlRegisterUncreatableType - by this myColor instance cannot be created*/
void MyColor::init()
{
    qRegisterMetaType<MyColor::Color>("MyColorQML::Color");
    qmlRegisterUncreatableType<MyColor>("MyColorQMLModule",1,0,"MyColors","Instance not required");
    //qmlRegisterType<MyColor>("MyColorQMLModule",1,0,"MyColors");
}

