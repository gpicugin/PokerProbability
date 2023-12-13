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
    m_playersCounter = 1;


    //m_hands.resize(m_playersCounter);
    for(int i = 0; i < m_playersCounter; i++) {
       // m_hands[i].resize(2);
    }
}

AppEngine::~AppEngine()
{

}

void AppEngine::doNextStep()
{
    for(int i = 0; i < m_playersCounter; i++)
    {
        pullCurrentCard();
        QString url1 = getCurrentCardUrl();
        pullCurrentCard();
        QString url2 = getCurrentCardUrl();
        emit newHand(url1, url2);
    }
}

void AppEngine::pullCurrentCard()
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

QString AppEngine::getCurrentCardUrl()
{
    QString url = cards.value(m_currentCard).m_url;
    emit newPulledCardUrl(url);
    return url;
}



// QVector<double> getProbabilities()
// {
//     QVector<double> result;
//     return result;
//     // static int cardsCounter = 0;
//     // pullNewCardFromDesc();

//     // if(cardsCounter < 2 * m_playersCounter)
//     //     m_hands[cardsCounter / 2][cardsCounter % 2] = m_currentCard;
//     // else
//     //     m_tableDesc.push_back(m_currentCard);



//     // if(cardsCounter == 2 * m_playersCounter + 4)
//     //     cardsCounter = 0;
//     // else
//     //     cardsCounter++;
// }





