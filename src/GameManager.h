
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <QObject>
#include <QSet>
#include <EnumOfCards.h>

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    ~GameManager();

private:
    QSet<Card> desc;

signals:

};

#endif // GAMEMANAGER_H
