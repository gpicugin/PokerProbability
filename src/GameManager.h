
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <QObject>
#include <QSet>
#include "CardClass.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    ~GameManager();

    Q_INVOKABLE QString getCurrentCardName();

private:
    void pullNewCardFromDesc();
private:
    Card        m_currentCard;
    QSet<Card>  m_desc;


signals:
    Q_INVOKABLE void doNextStep();
};

#endif // GAMEMANAGER_H
