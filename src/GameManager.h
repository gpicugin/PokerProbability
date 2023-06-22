
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <QObject>
#include <QSet>
#include <EnumOfCards.h>

class GameManager : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString cardName READ getCurrentCardName  NOTIFY currentCardChanged)
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
    void currentCardChanged();
};

#endif // GAMEMANAGER_H
