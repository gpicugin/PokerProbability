#ifndef CALCULATOROFPROBABILITY_H
#define CALCULATOROFPROBABILITY_H

#include <QObject>
#include <QVector>
#include <QSet>
#include <EnumOfCards.h>




class CalculatorOfProbability : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorOfProbability(QObject *parent = nullptr);

    double CalculatePair(QVector<Card> handCards, QVector<Card> tableCards);

signals:

private:
    double tryToCalculatePair(QVector<Card> handCards, QVector<Card> tableCards);
};

#endif // CALCULATOROFPROBABILITY_H
