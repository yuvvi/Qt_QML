/*****************************************************************************************************
 * Description 		 : It will send response of executed command to Server in Async Thread.
 *
 * External Objects called 	  : LogP
 *
 * Modification Log
 * Date                 Author                       Description
 * --------------------------------------------------------------
 * 01-Feb-2016			Infosys					 Initial Creation
 *
 ****************************************************************************************************/
#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <QObject>
#include <QNetworkReply>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkConfiguration>
#include "Log/Logp.h"
#include "Common/Constants.h"
#include "Common/DMError.h"

class AsyncHTTPConnection : public QObject
{
    Q_OBJECT
public:
    AsyncHTTPConnection(QObject *parent=0);

    /*****************************************************************************************************
         * Description          : It will send Async response to server.
         *
         * Parameters           : QByteArray - Async Data.
         *
         * Return Value         : int - status of response.
         *
    ****************************************************************************************************/
    int sendRequest(QByteArray);

    /*****************************************************************************************************
         * Description          : It helps to set URL of server to send response.
         *
         * Parameters           : QString - Server URL.
         *
         * Return Value         : NONE
         *
    ****************************************************************************************************/
    void setURL(QString);

    /*****************************************************************************************************
         * Description          : It will returns response of Server.
         *
         * Parameters           : NONE
         *
         * Return Value         : int - Response of Server.
         *
    ****************************************************************************************************/
    int getResult();

    /*****************************************************************************************************
         * Description          : It helps to set server's Route URL to send data.
         *
         * Parameters           : QString - Route URL.
         *
         * Return Value         : NONE
         *
    ****************************************************************************************************/
    void setRouteURL(QString);

    /*****************************************************************************************************
         * Description          : It returns server's Route URL to send data.
         *
         * Parameters           : NONE
         *
         * Return Value         : QString - Route URL.
         *
    ****************************************************************************************************/
    QString getRouteURL();

    ~AsyncHTTPConnection();

signals:
    void success();

public slots:

    /*****************************************************************************************************
         * Description          : It receives response from server.
         *
         * Parameters           : QNetworkReply - Server's response.
         *
         * Return Value         : NONE
         *
    ****************************************************************************************************/
    void Receive_Packet(QNetworkReply*);

private:
    static int  receivedData;
    QString m_URL;
    QString m_RouteURL;
    logP *logObj;
    QEventLoop *loop;
    QNetworkAccessManager *NA_manager;
    QNetworkRequest N_request;
    QNetworkReply   *N_reply;

};

#endif // HTTPCONNECTION_H
