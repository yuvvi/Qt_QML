#include "AsyncHTTPConnection.h"
int AsyncHTTPConnection::receivedData=0;
AsyncHTTPConnection::AsyncHTTPConnection(QObject *parent):QObject(parent){
    logObj = logP::getInstance();
    NA_manager = new QNetworkAccessManager;
}

int AsyncHTTPConnection::sendRequest(QByteArray array){
    logObj->debug(QString::fromStdString(Q_FUNC_INFO)+"RouteURL::"+this->getRouteURL());
    logObj->debug(QString::fromStdString(Q_FUNC_INFO)+"Param::"+m_URL);
    receivedData=0;
#ifdef WITHOUT_ROUTE_URL
    N_request.setUrl(QUrl(m_URL));
#endif
#ifdef WITH_ROUTE_URL
    N_request.setUrl(QUrl(this->getRouteURL()));
#endif
    connect(NA_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(Receive_Packet(QNetworkReply*)));
    N_request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant(QString("application/xml;charset=utf-8")));
#ifdef WITH_ROUTE_URL
    N_request.setRawHeader("service",m_URL.toLocal8Bit());
#endif
    N_request.setHeader(QNetworkRequest::ContentLengthHeader,QVariant(qulonglong(array.size())));
    NA_manager->post(N_request,array);
    return DMError::CMD_SUCCESSFUL;
}

void AsyncHTTPConnection::setURL(QString url){
    m_URL=url;
}

void AsyncHTTPConnection:: Receive_Packet(QNetworkReply* reply){
    QString data= reply->readAll();
    logObj->info(QString::fromStdString(Q_FUNC_INFO)+">received Data::"+data);
    receivedData=data.toInt();
    emit success();
}

int AsyncHTTPConnection::getResult(){
    return receivedData;
}

void AsyncHTTPConnection::setRouteURL(QString url){
    m_RouteURL=url;
}

QString AsyncHTTPConnection::getRouteURL(){
    return m_RouteURL;
}

AsyncHTTPConnection::~AsyncHTTPConnection(){
//    delete NA_manager;
}
