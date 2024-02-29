
#ifndef APP_ENGINE_H
#define APP_ENGINE_H

#include <QObject>
#include <QSet>
#include <QVector>
#include <QPair>
#include "Cards.h"
#include "CalculatorOfProbability.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

private:
    int                       m_playersCounter;
    int                       m_stepNumber;
    Card                      m_currentCard;
    QVector<CardNumber>       m_handCards;
    QVector<CardNumber>       m_tableCards;
    QSet<CardNumber>          m_desc;
    QSet<CardNumber>          m_descBackUp;
    CalculatorOfProbability   m_calc;
    QVector<double>           m_probArr;

    enum {
        preFlop = 0,
        flop,
        river,
        turn,
        end
    };

    void pullCardOnTable();
public slots:
    CardNumber      pullCurrentCard();
    void            doNextStep();
    void            calculateTable(QVector<CardNumber> cards = {});
signals:
    void    newHand(QString url1, QString url2);
    void    tableHasChanged(Card card);
    void    tableHasCleared();
    void    probTableHasChanged(QVector<double> probArr);
};

#endif // APP_ENGINE_H
