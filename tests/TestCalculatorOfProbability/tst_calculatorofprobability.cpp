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
    void pushCardsToArray(QVector<CardNumber>& tableCards, CardNumber card);
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

void testCalculator::pushCardsToArray(QVector<CardNumber>& array, CardNumber card)
{
    if(card > 0 && card < 52)
        array << card;
}

void testCalculator::test_tryToCalculatePair_data()
{
    QTest::addColumn<CardNumber>("firstHandCard");
    QTest::addColumn<CardNumber>("secondHandCard");
    QTest::addColumn<CardNumber>("firstFlop");
    QTest::addColumn<CardNumber>("secondFlop");
    QTest::addColumn<CardNumber>("thirdFlop");
    QTest::addColumn<CardNumber>("turn");
    QTest::addColumn<CardNumber>("river");
    QTest::addColumn<double>("result");

    QTest::addRow("Pair of 10") << CardNumber::clubs_10
                                << CardNumber::diamonds_10
                                << CardNumber::clubs_3
                                << CardNumber::diamonds_4
                                << CardNumber::diamonds_6
                                << CardNumber::hearts_9
                                << CardNumber::spades_jack
                                << 1.0;

    QTest::addRow("Nothing pair") << CardNumber::clubs_2
                                  << CardNumber::clubs_3
                                  << CardNumber::clubs_4
                                  << CardNumber::clubs_5
                                  << CardNumber::clubs_6
                                  << CardNumber::clubs_7
                                  << CardNumber::clubs_8
                                  << 0.0;

    QTest::addRow("Preflop no pair") << CardNumber::clubs_2
                                     << CardNumber::clubs_3
                                     << CardNumber::unopen_card
                                     << CardNumber::unopen_card
                                     << CardNumber::unopen_card
                                     << CardNumber::unopen_card
                                     << CardNumber::unopen_card
                                     << (double)(6/50);
    QTest::addRow("Preflop pair") << CardNumber::diamonds_8
                                  << CardNumber::hearts_8
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << 1.0;
}



void testCalculator::test_tryToCalculatePair()
{
    QFETCH(CardNumber, firstHandCard);
    QFETCH(CardNumber, secondHandCard);
    QFETCH(CardNumber, firstFlop);
    QFETCH(CardNumber, secondFlop);
    QFETCH(CardNumber, thirdFlop);
    QFETCH(CardNumber, turn);
    QFETCH(CardNumber, river);
    QFETCH(double, result);
    
    QVector<CardNumber> handCards;
    pushCardsToArray(handCards, firstHandCard);
    pushCardsToArray(handCards, secondHandCard);
    
    QVector<CardNumber> tableCards;

    pushCardsToArray(tableCards, firstFlop);
    pushCardsToArray(tableCards, secondFlop);
    pushCardsToArray(tableCards, thirdFlop);
    pushCardsToArray(tableCards, turn);
    pushCardsToArray(tableCards, river);

    QCOMPARE(calculator.CalculatePair(handCards, tableCards), result);
}

QTEST_APPLESS_MAIN(testCalculator)
#include "tst_calculatorOfProbability.moc"
