#ifndef MYCOLOR_H
#define MYCOLOR_H

#include <QObject>
#include <QtQml>

class MyColor : public QObject
{
    Q_OBJECT
public:
    explicit MyColor(QObject *parent = 0);
    enum class Color{
        RED,
        GREEN,
        BLUE
    };
    Q_ENUMS(Color);

    static void init();
};

#endif // MYCOLOR_H
