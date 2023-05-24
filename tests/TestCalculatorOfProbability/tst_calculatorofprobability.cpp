#include <QtTest>
#include "../../src/CalculatorOfProbability.h"
// add necessary includes here

class testCalculator : public QObject
{
    Q_OBJECT

public:
    testCalculator();
    ~testCalculator();

private slots:
    void test_tryToCalculatePair_data();
    void test_tryToCalculatePair();

private:
    CalculatorOfProbability calculator;

};

testCalculator::testCalculator()
{

}

testCalculator::~testCalculator()
{

}

void testCalculator::test_tryToCalculatePair_data()
{
    QTest::addColumn<int>("firstHandCard");
    QTest::addColumn<int>("secondHandCard");
    QTest::addColumn<int>("firstFlop");
    QTest::addColumn<int>("secondFlop");
    QTest::addColumn<int>("thirdFlop");
    QTest::addColumn<int>("turn");
    QTest::addColumn<int>("river");
    QTest::addColumn<double>("result");
    QTest::addRow("pair of 10") << 8 << 21 << 1 << 15 << 17 << 33 << 46 << 1.0;
}

void testCalculator::test_tryToCalculatePair()
{
    QFETCH(int, firstHandCard);
    QFETCH(int, secondHandCard);
    QFETCH(int, firstFlop);
    QFETCH(int, secondFlop);
    QFETCH(int, thirdFlop);
    QFETCH(int, turn);
    QFETCH(int, river);
    QFETCH(double, result);

    QVector<int> handCards;
    handCards << firstHandCard << secondHandCard;

    QVector<int> descCards;
    descCards << firstFlop << secondFlop << thirdFlop << turn << river;

    QCOMPARE(calculator.CalculatePair(handCards, descCards), result);
}

QTEST_APPLESS_MAIN(testCalculator)

#include "tst_calculatorOfProbability.moc"
