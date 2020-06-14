#include "lambda.h"

Lambda::Lambda(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<endl;

    /*String based syntax*/
//    connect(this,SIGNAL(finish(int)),this,SLOT(onFinished(int)));

    /*Functor based syntax - 1st alternative*/
//    connect(this, &finish,this,static_cast<void (Lambda::*)(int)>(&Lambda::onFinished));

    /*Functor based syntax - 2nd alternative*/
//    void (Lambda::*mySlot)(int) = &Lambda::onFinished;
//    connect(this, &Lambda::finish,this, mySlot);

//    nobj.mySlot3 = static_cast<void (QObject::*)(int)>(&Lambda::onFinished);
//    connect(this, &Lambda::finish,this, nobj.mySlot3);

//    void (Lambda::*mySlot4)()= static_cast<void (QObject::*)(int)>([](){qDebug()<<"Lambda function"<<endl;});
//    connect(this, &Lambda::finish,this, mySlot4);

//CALLING
//    getDataFromUrl(QString(itemWindow.fetchPrevLink), [=](const bool requestFinishedSuccessfully, const QJsonObject &data, int requestId){/*lambda function internals*/}, prevItemWindow.requestId);
//FUNCTION DECLARATION
//    void SimpleListModel2::getDataFromUrl(const QString fetchUrl, std::function<void(const bool requestFinishedSuccessfully, const QJsonObject &data, int requestId)> cb, int requestId)

//    std::function<void(const bool requestFinishedSuccessfully, const QJsonObject &data, int requestId)> cb
//    cb(true, json.object(), requestId);

//    std::function<void(const bool requestFinishedSuccessfully, const QJsonObject &data, int requestId)> cb;
//    std::function<void(int val)> cb;
//    cb = [=](int val){qDebug()<<"Lambda function :"<<val<<endl;};
//    connect(this, &Lambda::finish,this, cb);

    nobj.m_cb = [=](int val){qDebug()<<"Lambda function :"<<val<<endl;};
    connect(this, &Lambda::finish,this, nobj.m_cb);

    emit finish(10);
}


void Lambda::onFinished(int val)
{
    qDebug()<<Q_FUNC_INFO<<" #val :"<<val<<endl;
}
