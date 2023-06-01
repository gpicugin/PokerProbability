#include <QtTest>
#include "../../src/CalculatorOfProbability.h"
// add necessary includes here

class testCalculator : public QObject
{
    Q_OBJECT

public:
    testCalculator();
    ~testCalculator();
private:
    void pushDescCardsToDescArray(QVector<int>& descCards, int card);
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

void testCalculator::pushDescCardsToDescArray(QVector<int>& descCards, int card)
{
    if(card > 0 && card < 52)
        descCards << card;
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
    QTest::addRow("Pair of 10") << 8 << 21 << 1 << 15 << 17 << 33 << 48 << 1.0;
    QTest::addRow("Nothing pair") << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 0.0;
    QTest::addRow("Preflop no pair") << 0 << 1 << -1 << -1 << -1 << -1 << -1 << 0.0;
    QTest::addRow("Preflop pair") << 19 << 32 << -1 << -1 << -1 << -1 << -1 << 1.0;


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

    pushDescCardsToDescArray(descCards, firstFlop);
    pushDescCardsToDescArray(descCards, secondFlop);
    pushDescCardsToDescArray(descCards, thirdFlop);
    pushDescCardsToDescArray(descCards, turn);
    pushDescCardsToDescArray(descCards, river);

    QCOMPARE(calculator.CalculatePair(handCards, descCards), result);
}

QTEST_APPLESS_MAIN(testCalculator)

#include "tst_calculatorOfProbability.moc"
