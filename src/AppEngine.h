
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
    QVector<Card>             m_tableCards;
    QSet<CardNumber>          m_desc;
    QSet<CardNumber>          m_descBackUp;
    CalculatorOfProbability   m_calc;

    enum {
        preFlop = 0,
        flop,
        river,
        turn,
        end
    };

public slots:
    CardNumber      pullCurrentCard();
    void            doNextStep();

signals:
    void    tableHasChanged(Card card);
    void    tableHasCleared();
    void    newHand(QString url1, QString url2);
};

#endif // APP_ENGINE_H
