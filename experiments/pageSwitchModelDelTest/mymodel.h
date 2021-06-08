#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QDebug>

class MyModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString modelName MEMBER name)
public:
    explicit MyModel(QObject *parent = nullptr);
    ~MyModel(){qDebug()<<Q_FUNC_INFO<<endl;}
    QString getName(){return name;}

signals:
private:
    QString name;
};

class ModelList : public QObject
{
    Q_OBJECT
public:
    explicit ModelList(QObject *parent = nullptr);
    ~ModelList(){qDebug()<<Q_FUNC_INFO<<endl;}

    Q_INVOKABLE QObject* getModelData();
private:
    MyModel *mobj;
};
#endif // MYMODEL_H
