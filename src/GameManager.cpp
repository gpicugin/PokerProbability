
#include "GameManager.h"
#include <QRandomGenerator>
#include <QDebug>
GameManager::GameManager(QObject *parent)
    : QObject{parent},
    m_currentCard(Card::unopen_card)
{
    for(int i = 0; i < Card::size; i++)
    {
        m_desc << (Card)(i);
    }
}

GameManager::~GameManager()
{

}

QString GameManager::getCurrentCardName()
{
    //qDebug() << __PRETTY_FUNCTION__;
    pullNewCardFromDesc();
    //qDebug() << CardToString(m_currentCard);

    return CardToString(m_currentCard);
}

void GameManager::pullNewCardFromDesc()
{
    QRandomGenerator rand;
    int randomValue = rand.generate() % 53;

    while(1)
    {
        if(m_desc.remove((Card)(randomValue))) {
            m_currentCard = (Card)(randomValue);
            randomValue = rand.generate() % 53;
            break;
        }
        else
           randomValue = rand.generate() % 53;
    }
}

