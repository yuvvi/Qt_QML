#include <QtTest>

// add necessary includes here
#include "substraction.h"

class substract_unitTest : public QObject
{
    Q_OBJECT

public:
    substract_unitTest();
    ~substract_unitTest();

private slots:
    void test_case1();
private:
    substraction m_sub;

};

substract_unitTest::substract_unitTest()
{

}

substract_unitTest::~substract_unitTest()
{

}

void substract_unitTest::test_case1()
{
    QCOMPARE(m_sub.minus(10,20), -10);//PASS
    QVERIFY(m_sub.minus(10,20) == 10);//FAIL
    QVERIFY2(m_sub.minus(10,20) == -10, "Incorrect substraction output");//PASS

//    QTRY_VERIFY_WITH_TIMEOUT(m_sub.minus(10,20) == -10,1000);
    //QVERIFY_EXCEPTION_THROWN
}

QTEST_APPLESS_MAIN(substract_unitTest)

#include "tst_substract_unittest.moc"
