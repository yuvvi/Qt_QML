#ifndef LAMBDA_H
#define LAMBDA_H

#include <QObject>
#include <QDebug>
#include <QtGlobal>
#include <stdio.h>
#include <functional>

using namespace std;

class Lambda : public QObject
{
    Q_OBJECT
public:
    explicit Lambda(QObject *parent = 0);
signals:
    void finish(int);
public slots:
    void onFinished(int);
private:
    struct Native{
        void (QObject::*mySlot3)(int);
        std::function<void(int val)> m_cb;

    };
    Native nobj;

};

#endif // LAMBDA_H
