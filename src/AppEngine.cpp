#include "AppEngine.h"
#include <QRandomGenerator>
#include <QDebug>

AppEngine::AppEngine(QObject *parent)
    : QObject{parent},
    m_currentCard(CardNumber::unopen_card)
{
    for(int i = 0; i < CardNumber::size; i++)
    {
        m_desc << (CardNumber)(i);
    }
}

AppEngine::~AppEngine()
{

}

QString AppEngine::getCurrentCard()
{
    pullNewCardFromDesc();
    return cards.value(m_currentCard).m_url;
}

void AppEngine::pullNewCardFromDesc()
{
    QRandomGenerator rand;
    int randomValue = rand.generate() % 53;

    while(1)
    {
        if( m_desc.remove((CardNumber)(randomValue)) )
        {
            m_currentCard = (CardNumber)(randomValue);
            break;
        }
        else
           randomValue = rand.generate() % 53;
    }
}

