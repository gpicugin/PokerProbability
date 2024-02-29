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
    void test_tryToCalculateTwoPairs_data();
    void test_tryToCalculateTwoPairs();

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
    if(card >= 0 && card < 52)
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



    QTest::addRow("Preflop pair") << CardNumber::diamonds_8
                                  << CardNumber::hearts_8
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << CardNumber::unopen_card
                                  << 1.0;

    QTest::addRow("Nothing pair but last card unopened")
                                  << CardNumber::clubs_2
                                  << CardNumber::clubs_3
                                  << CardNumber::clubs_4
                                  << CardNumber::clubs_5
                                  << CardNumber::clubs_6
                                  << CardNumber::clubs_7
                                  << CardNumber::unopen_card
                                  << (double)(6.0 * 3.0 / 46.0);
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
    
    QVector<CardNumber> cards;
    pushCardsToArray(cards, firstHandCard);
    pushCardsToArray(cards, secondHandCard);
    

    pushCardsToArray(cards, firstFlop);
    pushCardsToArray(cards, secondFlop);
    pushCardsToArray(cards, thirdFlop);
    pushCardsToArray(cards, turn);
    pushCardsToArray(cards, river);

    qDebug() << calculator.CalculatePair(cards);
    qDebug() << result;
    result = std::round(result * 100.0)/100.0;

    QCOMPARE(calculator.CalculatePair(cards), result);
    //QVERIFY(qFuzzyCompare(calculator.CalculatePair(cards), result));
}

void testCalculator::test_tryToCalculateTwoPairs_data()
{
    QTest::addColumn<CardNumber>("firstHandCard");
    QTest::addColumn<CardNumber>("secondHandCard");
    QTest::addColumn<CardNumber>("firstFlop");
    QTest::addColumn<CardNumber>("secondFlop");
    QTest::addColumn<CardNumber>("thirdFlop");
    QTest::addColumn<CardNumber>("turn");
    QTest::addColumn<CardNumber>("river");
    QTest::addColumn<double>("result");

    QTest::addRow("Two pairs")
        << CardNumber::clubs_2
        << CardNumber::diamonds_2
        << CardNumber::clubs_4
        << CardNumber::diamonds_4
        << CardNumber::clubs_6
        << CardNumber::clubs_7
        << CardNumber::clubs_8
        << 1.0;

    QTest::addRow("Nothing two pairs")
        << CardNumber::clubs_2
        << CardNumber::clubs_3
        << CardNumber::clubs_4
        << CardNumber::clubs_5
        << CardNumber::clubs_6
        << CardNumber::clubs_7
        << CardNumber::clubs_8
        << 0.0;
}

void testCalculator::test_tryToCalculateTwoPairs()
{
    QFETCH(CardNumber, firstHandCard);
    QFETCH(CardNumber, secondHandCard);
    QFETCH(CardNumber, firstFlop);
    QFETCH(CardNumber, secondFlop);
    QFETCH(CardNumber, thirdFlop);
    QFETCH(CardNumber, turn);
    QFETCH(CardNumber, river);
    QFETCH(double, result);

    QVector<CardNumber> cards;
    pushCardsToArray(cards, firstHandCard);
    pushCardsToArray(cards, secondHandCard);


    pushCardsToArray(cards, firstFlop);
    pushCardsToArray(cards, secondFlop);
    pushCardsToArray(cards, thirdFlop);
    pushCardsToArray(cards, turn);
    pushCardsToArray(cards, river);

    qDebug() << calculator.CalculateTwoPairs(cards);
    qDebug() << result;
    result = std::round(result * 100.0)/100.0;

    QCOMPARE(calculator.CalculateTwoPairs(cards), result);
}


QTEST_APPLESS_MAIN(testCalculator)
#include "tst_calculatorOfProbability.moc"
