#ifndef APPLICATIONLAYER_H
#define APPLICATIONLAYER_H

#include <QObject>
#include <QDebug>
/*
 * Q_INVOKABLE:
 *      A function can be used in QML only when declared with Q_INVOKABLE
 * Q_PROPERTY:
 *Q_PROPERTY(type name
           (READ getFunction [WRITE setFunction] |
            MEMBER memberName [(READ getFunction | WRITE setFunction)])
           [RESET resetFunction]
           [NOTIFY notifySignal]
           [REVISION int]
           [DESIGNABLE bool]
           [SCRIPTABLE bool]
           [STORED bool]
           [USER bool]
           [CONSTANT]
           [FINAL])
*/

class ApplicationLayer : public QObject
{
    Q_OBJECT
    /*  1st arg can be given different name (other than m_printCount),
     *  But the given name will be used in QML side*/
    //Q_PROPERTY(int m_printCount READ printCount WRITE setPrintCount NOTIFY printCountChanged)
    Q_PROPERTY(int printCountQML READ printCount WRITE setPrintCount NOTIFY printCountChanged)

    /*With change of pCount in QML side,
     * SIGNAL:printCountChanged is emitted & updates m_printCount.*/
    Q_PROPERTY(int pCount MEMBER m_printCount NOTIFY printCountChanged)
public:
    explicit ApplicationLayer(QObject *parent = nullptr);
    Q_INVOKABLE void print_operation();

    int printCount() const;
    void setPrintCount(int printCount);

signals:
    void printCountChanged();

public slots:
private:
    int m_printCount;
};

#endif // APPLICATIONLAYER_H
