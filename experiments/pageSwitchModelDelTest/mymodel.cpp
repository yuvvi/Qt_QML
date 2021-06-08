#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
    name = "AMD_MODEL";
}

ModelList::ModelList(QObject *parent)
{
qDebug()<<Q_FUNC_INFO;
mobj = new MyModel;
}

QObject *ModelList::getModelData()
{
    qDebug()<<Q_FUNC_INFO<<" #name: "<<mobj->getName();
    return mobj;
}

