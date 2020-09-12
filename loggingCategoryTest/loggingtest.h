#ifndef LOGGINGTEST_H
#define LOGGINGTEST_H

#include <QObject>
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(NETWORK_LOG)
class LoggingTest : public QObject
{
    Q_OBJECT
public:
    explicit LoggingTest(QObject *parent = 0);
    ~LoggingTest();
    void func();

signals:

public slots:
};

#endif // LOGGINGTEST_H
