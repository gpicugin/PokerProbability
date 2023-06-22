
#include "GameManager.h"

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    for(int i = 0; i < Card::size; i++)
    {
        desc << (Card)(i);
    }
}

GameManager::~GameManager()
{

}

