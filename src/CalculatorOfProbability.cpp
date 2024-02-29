#include "CalculatorOfProbability.h"
#include <QDebug>

CalculatorOfProbability::CalculatorOfProbability(QObject *parent)
    : QObject{parent}
{
    m_results = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

QVector<double> CalculatorOfProbability::CalculateAll(QVector<CardNumber> cards)
{

    m_results[pair] = CalculatePair(cards);
    m_results[twoPairs] = CalculateTwoPairs(cards);

    return m_results;

}

double CalculatorOfProbability::CalculatePair(QVector<CardNumber> cards)
{
    double result = -1;

    try {
        result = tryToCalculatePair(cards);
        return result;
    }
    catch (QString error) {
        qDebug() << error << "/n";
    }
    return result;
}

double CalculatorOfProbability::tryToCalculatePair(QVector<CardNumber> cards)
{
    double result;
    
    for (int i = 0; i < cards.size(); i++) {
        if(cards[i] > 51 || cards[i] < 0)
            throw (QString)("Invalid Card Number");
    }

    if(cards.size() == 0)
        return std::round(((13 * 6 * Combinations(48, 5)) / Combinations(52, 7)) * 100.0) / 100.0;


    if(calcUniqueValues(cards) < cards.size())
        return 1.0;


    // Тут все карты уникальны по значению
    double reserveProbKoefMult = 1;
    double stepProb;
    result = 0.0;
    for(int i = cards.size(); i < 7; i++)
    {
        stepProb = 3.0/(52.0 - i);
        result += reserveProbKoefMult * stepProb;
        reserveProbKoefMult *= 1.0 - (3.0/ (52.0 - i));
    }
    result *= cards.size();

    if(cards.size() == 7 && calcUniqueValues(cards) == 7)
        result = 0.0;

    result = std::round(result * 100.0) / 100.0;
    return result;
}

double CalculatorOfProbability::CalculateTwoPairs(QVector<CardNumber> cards)
{
    double result = -1;

    try {
        result = tryToCalculateTwoPairs(cards);
        return result;
    }
    catch (QString error) {
        qDebug() << error << "/n";
    }
    return result;
}

double CalculatorOfProbability::tryToCalculateTwoPairs(QVector<CardNumber> cards)
{
    double result = -1.0;

    for (int i = 0; i < cards.size(); i++) {
        if(cards[i] > 51 || cards[i] < 0)
            throw (QString)("Invalid Card Number");
    }

    if(cards.size() == 0)
        result = 13 * 6 * 12 * 6 * Combinations(44,3) / Combinations(52, 7);
    else
    {
        double probOfFirstPair = m_results[pair];
        double probOfSecondPair = 0;
        for(int i = cards.size(); i < 7; i++)
        {
            double reserveProbKoefMult = 1;
            double stepProb;
            for(int i = cards.size()-2; i < 5; i++)
            {
                stepProb = 3.0/(52.0 - i);
                probOfSecondPair += reserveProbKoefMult * stepProb;
                reserveProbKoefMult *= 1.0 - (3.0/ (52.0 - i));
            }
            probOfSecondPair *= cards.size();

        }
        result = probOfFirstPair * probOfSecondPair;
    }

    result = std::round(result * 100.0) / 100.0;
    return result;
}

int CalculatorOfProbability::calcUniqueValues(QVector<CardNumber> cards)
{
    QSet<int> uniqueValues;

    for(int i = 0; i < cards.size(); i++)
    {
        uniqueValues << cards[i] % 13;
    }
    return uniqueValues.size();
}




