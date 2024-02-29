#include "AppEngine.h"
#include <QRandomGenerator>
#include <QDebug>
#include <TableModel.h>
AppEngine::AppEngine(QObject *parent)
    : QObject{parent},
    m_currentCard(CardNumber::unopen_card)
{
    for(int i = 0; i < CardNumber::sizeOfDesc; i++)
    {
        m_desc << (CardNumber)(i);
        m_descBackUp << (CardNumber)(i);
    }
    m_playersCounter = 1;
    m_stepNumber = preFlop;

}

AppEngine::~AppEngine()
{

}

void AppEngine::doNextStep()
{
    static QVector<CardNumber> mainPlayerHand;
    switch (m_stepNumber) {
    case preFlop: {
        for(int i = 0; i < m_playersCounter * 2; i++)
        {
            m_handCards << pullCurrentCard() << pullCurrentCard();
            if( i % 2 == 1)
            {
                QString url1 = cards.value(m_handCards[i-1]);
                QString url2 = cards.value(m_handCards[i]);
                emit newHand(url1, url2);
            }
        }
        mainPlayerHand = { m_handCards[0], m_handCards[1] };
        break;
    }
    case flop: {
        for(int i = 0; i < 3; i++)
            pullCardOnTable();
        break;
    }
    case river: {
        pullCardOnTable();
        break;
    }
    case turn: {
        pullCardOnTable();
        break;
    }
    case end: {
        m_tableCards.clear();
        mainPlayerHand.clear();
        emit tableHasCleared();
        break;
    }
    default:
        break;
    }
    if(m_stepNumber == end) {
        m_stepNumber = preFlop;
        m_desc = m_descBackUp;
    }
    else
        m_stepNumber++;

    calculateTable(mainPlayerHand + m_tableCards);
}

void AppEngine::calculateTable(QVector<CardNumber> cards)
{
    m_probArr = m_calc.CalculateAll(cards);
    emit probTableHasChanged(m_probArr);
}

void AppEngine::pullCardOnTable()
{
    Card card(pullCurrentCard());
    m_tableCards << card.m_name;
    emit tableHasChanged(card);
}

CardNumber AppEngine::pullCurrentCard()
{
    QRandomGenerator rand = QRandomGenerator::securelySeeded();
    int randomValue = rand.generate() % 52;

    while(1)
    {
        if( m_desc.remove((CardNumber)(randomValue)) )
        {
            return (CardNumber)(randomValue);
            break;
        }
        else
            randomValue = rand.generate() % 52;
    }
}




