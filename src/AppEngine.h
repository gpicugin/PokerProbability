
#ifndef APP_ENGINE_H
#define APP_ENGINE_H

#include <QObject>
#include <QSet>
#include <QVector>
#include <QPair>
#include "Cards.h"
#include "CalculatorOfProbability.h"
#include "HandsModel.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();    

private:    
    int                             m_playersCounter;
    CardNumber                      m_currentCard;
    //QVector<QPair<CardNumber>>    m_handCards;
    QVector<CardNumber>             m_tableCards;
    QSet<CardNumber>                m_desc;
    CalculatorOfProbability         m_calc;
    HandsModel                      m_handsModel;

public slots:
    void            pullCurrentCard();
    QString         getCurrentCardUrl();
    //QVector<double> getProbabilities();
    void            doNextStep();


signals:
    void    newPulledCardUrl(QString url);
    void    newHand(QString url1, QString url2);
};

#endif // APP_ENGINE_H
