#include "AppEngine.h"
#include <QRandomGenerator>
#include <QDebug>
#include <TableModel.h>
AppEngine::AppEngine(QObject *parent)
    : QObject{parent},
    m_currentCard(CardNumber::unopen_card)
{
    for(int i = 0; i < CardNumber::size; i++)
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

    switch (m_stepNumber) {
    case preFlop: {
        for(int i = 0; i < m_playersCounter; i++)
        {
            QString url1 = cards.value(pullCurrentCard());
            QString url2 = cards.value(pullCurrentCard());
            emit newHand(url1, url2);
        }
        break;
    }
    case flop: {
        for(int i = 0; i < 3; i++) {
            Card card(pullCurrentCard());
            m_tableCards << card;
            emit tableHasChanged(card);
        }
        break;
    }
    case river: {
        Card card(pullCurrentCard());
        m_tableCards << card;
        emit tableHasChanged(card);
        break;
    }
    case turn: {
        Card card(pullCurrentCard());
        m_tableCards << card;
        emit tableHasChanged(card);
        break;
    }
    case end: {
        m_tableCards.clear();
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
}

CardNumber AppEngine::pullCurrentCard()
{
    QRandomGenerator rand;
    int randomValue = rand.generate() % 53;

    while(1)
    {
        if( m_desc.remove((CardNumber)(randomValue)) )
        {
            return (CardNumber)(randomValue);
            break;
        }
        else
            randomValue = rand.generate() % 53;
    }
}




