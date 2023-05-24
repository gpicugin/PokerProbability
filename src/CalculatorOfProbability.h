#ifndef CALCULATOROFPROBABILITY_H
#define CALCULATOROFPROBABILITY_H

#include <QObject>
#include <QVector>
class CalculatorOfProbability : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorOfProbability(QObject *parent = nullptr);

    double CalculatePair(QVector<int> handCards, QVector<int> descCards);

signals:

private:
    double tryToCalculatePair(QVector<int> handCards, QVector<int> descCards);
};

#endif // CALCULATOROFPROBABILITY_H
