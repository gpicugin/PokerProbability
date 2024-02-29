#include <QCoreApplication>
#include "../../src/CalculatorOfProbability.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CalculatorOfProbability calc;

    QVector<CardNumber> arr;

    arr << CardNumber::clubs_2
        << CardNumber::clubs_3
        << CardNumber::clubs_4
        << CardNumber::clubs_5
        << CardNumber::clubs_6
        << CardNumber::clubs_7;
        //<< CardNumber::clubs_8;

    qDebug() << calc.CalculatePair(arr);

    return a.exec();
}
