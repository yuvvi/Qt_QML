#ifndef FRAMECOUNTER_H
#define FRAMECOUNTER_H

#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QObject>
#include <QTimer>
#include <QDebug>

class FrameCounter : public QObject
{
    Q_OBJECT
public:
    explicit FrameCounter();
    void initFPScounter(QQuickWindow *window);
    ~FrameCounter();

signals:

private slots:
    void updateFrameCount();
    void displayFrameCount();

private:
    int m_refreshRate;
    QList<int> m_frameList;
    QTimer  m_timer;
};

#endif // FRAMECOUNTER_H
