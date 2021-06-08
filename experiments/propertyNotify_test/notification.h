#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class notification : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(int myData  READ getData NOTIFY myTimerTriggered)

public:
    explicit notification(QObject *parent = nullptr);
    Q_INVOKABLE int getData();
    Q_INVOKABLE QString getStrData();
    void setMystrData(QString str);

//    Q_PROPERTY(QString myStrData  READ getStrData NOTIFY myTimerTriggered)
    Q_PROPERTY(QString myStrData MEMBER m_StrData WRITE setMystrData NOTIFY myTimerTriggered)
    Q_PROPERTY (bool isOverclock MEMBER m_overclock NOTIFY overclockCPU)
signals:
    void myTimerTriggered();
    void overclockCPU();
public slots:
    void slt_timerTriggered();
private:
    int m_data=0;
    QString m_StrData;
    QTimer *mTimer;
    bool m_overclock = false;

};

#endif // NOTIFICATION_H
