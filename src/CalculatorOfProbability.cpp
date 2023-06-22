#include "CalculatorOfProbability.h"
#include <QDebug>

CalculatorOfProbability::CalculatorOfProbability(QObject *parent)
    : QObject{parent}
{

}

double CalculatorOfProbability::CalculatePair(QVector<Card> handCards, QVector<Card> tableCards)
{
    double result = -1;

    try {
        result = tryToCalculatePair(handCards, tableCards);
        return result;
    }
    catch (double error) {
        qDebug() << error << "/n";
    }
    return result;
}

double CalculatorOfProbability::tryToCalculatePair(QVector<Card> handCards, QVector<Card> tableCards)
{
    double result = 3/51;
    
    QVector<Card> allCards = handCards + tableCards;
    QSet<int> uniqueValues;

    for(int i = 0; i < allCards.size(); i++)
    {
        int prevSize = uniqueValues.size();
        uniqueValues << allCards[i] % 13;
        if(uniqueValues.size() == prevSize)
            return 1.0;
        else
            result = uniqueValues.size() * 3 / (52 - allCards.size());
    }

    if(allCards.size() == 7 && uniqueValues.size() == 7)
        result = 0.0;

    return result;
}

