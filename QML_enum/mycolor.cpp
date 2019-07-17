#include "mycolor.h"

MyColor::MyColor(QObject *parent) : QObject(parent)
{

}

void MyColor::init()
{
    qRegisterMetaType<MyColor::Color>("MyColorQML::Color");
    qmlRegisterType<MyColor>("MyColorQMLModule",1,0,"MyColors");
}

