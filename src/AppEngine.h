
#ifndef APP_ENGINE_H
#define APP_ENGINE_H


#include <QObject>
#include <QSet>
#include "Cards.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

private:
    void pullNewCardFromDesc();

private:
    CardNumber        m_currentCard;
    QSet<CardNumber>  m_desc;

public slots:
    QString getCurrentCard();


signals:
    void doNextStep();
};

#endif // APP_ENGINE_H
