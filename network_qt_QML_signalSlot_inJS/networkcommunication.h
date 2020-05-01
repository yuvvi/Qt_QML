#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H

#include <QObject>
#include <QNetworkReply>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkConfiguration>
#include <QDebug>
#include <QHttpPart>
#include <QHttpMultiPart>
#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


class NetworkCommunication : public QObject
{
    Q_OBJECT
public:

    explicit NetworkCommunication(QObject *parent = nullptr);
    Q_INVOKABLE void setRouteURL(QString);
    QString getRouteURL();

    Q_INVOKABLE void postRequest(QByteArray postData);
    Q_INVOKABLE void getRequest(QString url);

signals:
//    void rxPayload(int stts, QString payload);
    void rxPayload_1();
    void rxPayload(int stts);
    void rxPayload_string(QString payload);
    void rxPayload_json(QJsonObject jsondata);

public slots:
    void receivePacket(QNetworkReply*reply);

private:
    static QNetworkAccessManager *NA_manager;
    QNetworkRequest N_request;
    QString m_RouteURL;

};

#endif // NETWORKCOMMUNICATION_H
