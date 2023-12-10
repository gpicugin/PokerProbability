#ifndef CALCULATOROFPROBABILITY_H
#define CALCULATOROFPROBABILITY_H

#include <QObject>
#include <QVector>
#include <QSet>
#include "Cards.h"

class CalculatorOfProbability : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorOfProbability(QObject *parent = nullptr);

public slots:
    double CalculatePair(QVector<CardNumber> handCards, QVector<CardNumber> tableCards);

signals:

private:
    double tryToCalculatePair(QVector<CardNumber> handCards, QVector<CardNumber> tableCards);
};

#endif // CALCULATOROFPROBABILITY_H
