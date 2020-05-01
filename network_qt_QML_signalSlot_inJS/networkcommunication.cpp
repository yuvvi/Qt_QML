#include "networkcommunication.h"

QNetworkAccessManager *NetworkCommunication::NA_manager=nullptr;

NetworkCommunication::NetworkCommunication(QObject *parent) : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    if(NA_manager == nullptr){
        NA_manager = new QNetworkAccessManager;
    }
    connect(NA_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(receivePacket(QNetworkReply*)));
}
void NetworkCommunication::postRequest(QByteArray postData){
    qDebug()<<Q_FUNC_INFO<<endl;
    N_request.setUrl(QUrl(this->getRouteURL()));
//    N_request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant(QString("application/json;charset=UTF-8")));
    QNetworkReply *reply = NA_manager->post(N_request,postData);
//    connect(reply,SIGNAL(finished()),this,SIGNAL(rxPayload_1()));

    qDebug()<<Q_FUNC_INFO<<"--end"<<endl;
}

void NetworkCommunication::getRequest(QString url)
{
    qDebug()<<Q_FUNC_INFO<<endl;
    N_request.setUrl(QUrl(url));
    N_request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant(QString("application/json;charset=UTF-8")));
    connect(NA_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(receivePacket(QNetworkReply*)));
    NA_manager->get(N_request);
}


void NetworkCommunication::receivePacket(QNetworkReply *reply)
{
    qDebug()<<Q_FUNC_INFO<<" # -----------------------------------start"<<endl;
    qDebug()<< "status:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() << "url:" << reply->url().toString();
    int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QByteArray ary = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(ary);
    QJsonObject jsonObject = json.object();

    qDebug()<<Q_FUNC_INFO<<" #ary.size :"<<ary.size()<<endl;
    qDebug()<<Q_FUNC_INFO<< "status:" << status << endl;

//    emit rxPayload(status,QString(ary));
    emit rxPayload(status);
//    emit rxPayload_string(QString::fromStdString("hiiiiiiiiiiiiiiiiii"));
    //    emit rxPayload_string(QString::fromStdString(ary.toStdString()));
//    emit rxPayload_string("HIiiiiiiiii");
    //    emit rxPayload_json();
    emit rxPayload_json(jsonObject);
//    reply->deleteLater();
    qDebug()<<Q_FUNC_INFO<<" # -----------------------------------END"<<endl;

}

void NetworkCommunication::setRouteURL(QString url){
    qDebug()<<Q_FUNC_INFO<<endl;
    m_RouteURL=url;
}

QString NetworkCommunication::getRouteURL(){
    qDebug()<<Q_FUNC_INFO<<endl;
    return m_RouteURL;
}

