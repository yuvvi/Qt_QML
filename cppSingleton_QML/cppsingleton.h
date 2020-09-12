#ifndef CPPSINGLETON_H
#define CPPSINGLETON_H

#include <QObject>
#include <QDebug>
#include <QQmlEngine>
#include <QJSEngine>

class cppSingleton : public QObject
{
    Q_OBJECT
private:
    static cppSingleton *cppSobj;
    Q_DISABLE_COPY(cppSingleton)
    explicit cppSingleton(QObject *parent = 0);
    ~cppSingleton(){}
//    cppSingleton(const cppSingleton*){}
//    const cppSingleton* operator=(const cppSingleton*){}

public:
    static cppSingleton* getNetworkinstance();
    static QObject *getinstance(QQmlEngine *engine, QJSEngine *scriptEngine){
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
        qDebug()<<Q_FUNC_INFO<<endl;

            if(cppSobj == nullptr){
                cppSobj = new cppSingleton;
            }
            return cppSobj;
    }

    Q_INVOKABLE QString getData() const;
    Q_INVOKABLE void setData(const QString &data);

signals:

public slots:
private:
    QString m_data;
};

#endif // CPPSINGLETON_H
