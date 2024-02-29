#ifndef CALCULATOROFPROBABILITY_H
#define CALCULATOROFPROBABILITY_H

#include <QObject>
#include <QVector>
#include <QSet>
#include "Cards.h"
#include "MyMath.h"

enum combNames {
    highCard    = 0,
    pair        = 1,
    twoPairs    = 2,
    set         = 3,
    street      = 4,
    flash       = 5,
    fullHouse   = 6,
    Care        = 7,
    streetFlash = 8,
    royalFlash  = 9,
    sizeOfComb  = 10
};

class CalculatorOfProbability : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorOfProbability(QObject *parent = nullptr);

public slots:
    QVector<double> CalculateAll(QVector<CardNumber> cards);
    double CalculatePair(QVector<CardNumber> cards);
    double CalculateTwoPairs(QVector<CardNumber> cards);

signals:

private:
    int   calcUniqueValues(QVector<CardNumber> cards);
    double tryToCalculatePair(QVector<CardNumber> cards);
    double tryToCalculateTwoPairs(QVector<CardNumber> cards);
    QVector<double> m_results = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


};

#endif // CALCULATOROFPROBABILITY_H
