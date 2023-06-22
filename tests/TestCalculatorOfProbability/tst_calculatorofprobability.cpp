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
    void pushCardsToArray(QVector<Card>& tableCards, Card card);
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

void testCalculator::pushCardsToArray(QVector<Card>& array, Card card)
{
    if(card > 0 && card < 52)
        array << card;
}

void testCalculator::test_tryToCalculatePair_data()
{
    QTest::addColumn<Card>("firstHandCard");
    QTest::addColumn<Card>("secondHandCard");
    QTest::addColumn<Card>("firstFlop");
    QTest::addColumn<Card>("secondFlop");
    QTest::addColumn<Card>("thirdFlop");
    QTest::addColumn<Card>("turn");
    QTest::addColumn<Card>("river");
    QTest::addColumn<double>("result");

    QTest::addRow("Pair of 10") << clubs_10
                                << diamonds_10
                                << clubs_3
                                << diamonds_4
                                << diamonds_6
                                << hearts_9
                                << spades_jack
                                << 1.0;

    QTest::addRow("Nothing pair") << clubs_2
                                  << clubs_3
                                  << clubs_4
                                  << clubs_5
                                  << clubs_6
                                  << clubs_7
                                  << clubs_8
                                  << 0.0;

    QTest::addRow("Preflop no pair") << clubs_2
                                     << clubs_3
                                     << uncopen_card
                                     << uncopen_card
                                     << uncopen_card
                                     << uncopen_card
                                     << uncopen_card
                                     << (double)(6/50);
    QTest::addRow("Preflop pair") << diamonds_8
                                  << hearts_8
                                  << uncopen_card
                                  << uncopen_card
                                  << uncopen_card
                                  << uncopen_card
                                  << uncopen_card
                                  << 1.0;
}



void testCalculator::test_tryToCalculatePair()
{
    QFETCH(Card, firstHandCard);
    QFETCH(Card, secondHandCard);
    QFETCH(Card, firstFlop);
    QFETCH(Card, secondFlop);
    QFETCH(Card, thirdFlop);
    QFETCH(Card, turn);
    QFETCH(Card, river);
    QFETCH(double, result);
    
    QVector<Card> handCards;
    pushCardsToArray(handCards, firstHandCard);
    pushCardsToArray(handCards, secondHandCard);
    
    QVector<Card> tableCards;

    pushCardsToArray(tableCards, firstFlop);
    pushCardsToArray(tableCards, secondFlop);
    pushCardsToArray(tableCards, thirdFlop);
    pushCardsToArray(tableCards, turn);
    pushCardsToArray(tableCards, river);

    QCOMPARE(calculator.CalculatePair(handCards, tableCards), result);
}

QTEST_APPLESS_MAIN(testCalculator)

#include "tst_calculatorOfProbability.moc"
