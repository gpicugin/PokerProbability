#include "CalculatorOfProbability.h"
#include <QDebug>

CalculatorOfProbability::CalculatorOfProbability(QObject *parent)
    : QObject{parent}
{

}

double CalculatorOfProbability::CalculatePair(QVector<int> handCards, QVector<int> descCards)
{
    double result = -1;

    try {
        result = tryToCalculatePair(handCards, descCards);
        return result;
    }
    catch (double error) {
        qDebug() << error << "/n";
    }
    return result;
}

double CalculatorOfProbability::tryToCalculatePair(QVector<int> handCards, QVector<int> descCards)
{
    double result = 0;

    QVector<int> allCards = handCards + descCards;

    for(int i = 0; i < allCards.size(); i++) {
        for(int j = i + 1; j < allCards.size(); j++) {
            if(allCards[i] % 13 == allCards[j] % 13)
                result =  1;
        }
    }

    return result;
}

