#ifndef CARDS_H
#define CARDS_H

#include <QString>
#include <QObject>
#include <QMap>


enum CardNumber {

    clubs_2 = 0, // крести
    clubs_3 = 1,
    clubs_4 = 2,
    clubs_5 = 3,
    clubs_6 = 4,
    clubs_7 = 5,
    clubs_8 = 6,
    clubs_9 = 7,
    clubs_10 = 8,
    clubs_jack = 9,
    clubs_queen = 10,
    clubs_king = 11,
    clubs_ace = 12,

    diamonds_2 = 13, // бубны
    diamonds_3 = 14,
    diamonds_4 = 15,
    diamonds_5 = 16,
    diamonds_6 = 17,
    diamonds_7 = 18,
    diamonds_8 = 19,
    diamonds_9 = 20,
    diamonds_10 = 21,
    diamonds_jack = 22,
    diamonds_queen = 23,
    diamonds_king = 24,
    diamonds_ace = 25,

    hearts_2 = 26, // червы
    hearts_3 = 27,
    hearts_4 = 28,
    hearts_5 = 29,
    hearts_6 = 30,
    hearts_7 = 31,
    hearts_8 = 32,
    hearts_9 = 33,
    hearts_10 = 34,
    hearts_jack = 35,
    hearts_queen = 36,
    hearts_king = 37,
    hearts_ace = 38,

    spades_2 = 39, // пики
    spades_3 = 40,
    spades_4 = 41,
    spades_5 = 42,
    spades_6 = 43,
    spades_7 = 44,
    spades_8 = 45,
    spades_9 = 46,
    spades_10 = 47,
    spades_jack = 48,
    spades_queen = 49,
    spades_king = 50,
    spades_ace = 51,
    shirt_card = 52,
    unopen_card = 53,
    size = 54
};

static QMap<CardNumber, QString> cards = {
    {clubs_2,  "qrc:/card_images/Cards/2_of_clubs.png"},
    {clubs_3,  "qrc:/card_images/Cards/3_of_clubs.png"},
    {clubs_4,  "qrc:/card_images/Cards/4_of_clubs.png"},
    {clubs_5,  "qrc:/card_images/Cards/5_of_clubs.png"},
    {clubs_6,  "qrc:/card_images/Cards/6_of_clubs.png"},
    {clubs_7,  "qrc:/card_images/Cards/7_of_clubs.png"},
    {clubs_8,  "qrc:/card_images/Cards/8_of_clubs.png"},
    {clubs_9,  "qrc:/card_images/Cards/9_of_clubs.png"},
    {clubs_10,  "qrc:/card_images/Cards/10_of_clubs.png"},
    {clubs_jack,  "qrc:/card_images/Cards/jack_of_clubs.png"},
    {clubs_queen,  "qrc:/card_images/Cards/queen_of_clubs.png"},
    {clubs_king,  "qrc:/card_images/Cards/king_of_clubs.png"},
    {clubs_ace,  "qrc:/card_images/Cards/ace_of_clubs.png"},

    {diamonds_2,  "qrc:/card_images/Cards/2_of_diamonds.png"},
    {diamonds_3,  "qrc:/card_images/Cards/3_of_diamonds.png"},
    {diamonds_4,  "qrc:/card_images/Cards/4_of_diamonds.png"},
    {diamonds_5,  "qrc:/card_images/Cards/5_of_diamonds.png"},
    {diamonds_6,  "qrc:/card_images/Cards/6_of_diamonds.png"},
    {diamonds_7,  "qrc:/card_images/Cards/7_of_diamonds.png"},
    {diamonds_8,  "qrc:/card_images/Cards/8_of_diamonds.png"},
    {diamonds_9,  "qrc:/card_images/Cards/9_of_diamonds.png"},
    {diamonds_10,  "qrc:/card_images/Cards/10_of_diamonds.png"},
    {diamonds_jack,  "qrc:/card_images/Cards/jack_of_diamonds.png"},
    {diamonds_queen,  "qrc:/card_images/Cards/queen_of_diamonds.png"},
    {diamonds_king,  "qrc:/card_images/Cards/king_of_diamonds.png"},
    {diamonds_ace,  "qrc:/card_images/Cards/ace_of_diamonds.png"},

    {hearts_2,  "qrc:/card_images/Cards/2_of_hearts.png"},
    {hearts_3,  "qrc:/card_images/Cards/3_of_hearts.png"},
    {hearts_4,  "qrc:/card_images/Cards/4_of_hearts.png"},
    {hearts_5,  "qrc:/card_images/Cards/5_of_hearts.png"},
    {hearts_6,  "qrc:/card_images/Cards/6_of_hearts.png"},
    {hearts_7,  "qrc:/card_images/Cards/7_of_hearts.png"},
    {hearts_8,  "qrc:/card_images/Cards/8_of_hearts.png"},
    {hearts_9,  "qrc:/card_images/Cards/9_of_hearts.png"},
    {hearts_10,  "qrc:/card_images/Cards/10_of_hearts.png"},
    {hearts_jack,  "qrc:/card_images/Cards/jack_of_hearts.png"},
    {hearts_queen,  "qrc:/card_images/Cards/queen_of_hearts.png"},
    {hearts_king,  "qrc:/card_images/Cards/king_of_hearts.png"},
    {hearts_ace,  "qrc:/card_images/Cards/ace_of_hearts.png"},

    {spades_2,  "qrc:/card_images/Cards/2_of_spades.png"},
    {spades_3,  "qrc:/card_images/Cards/3_of_spades.png"},
    {spades_4,  "qrc:/card_images/Cards/4_of_spades.png"},
    {spades_5,  "qrc:/card_images/Cards/5_of_spades.png"},
    {spades_6,  "qrc:/card_images/Cards/6_of_spades.png"},
    {spades_7,  "qrc:/card_images/Cards/7_of_spades.png"},
    {spades_8,  "qrc:/card_images/Cards/8_of_spades.png"},
    {spades_9,  "qrc:/card_images/Cards/9_of_spades.png"},
    {spades_10,  "qrc:/card_images/Cards/10_of_spades.png"},
    {spades_jack,  "qrc:/card_images/Cards/jack_of_spades.png"},
    {spades_queen,  "qrc:/card_images/Cards/queen_of_spades.png"},
    {spades_king,  "qrc:/card_images/Cards/king_of_spades.png"},
    {spades_ace,  "qrc:/card_images/Cards/ace_of_spades.png"},

    {unopen_card,  "qrc:/card_images/Cards/red_joker.png"}
};

struct Card {
    CardNumber m_name;
    QString m_URL;
    Card(CardNumber number = CardNumber::unopen_card) {
        m_name  = number;
        m_URL   = cards.value(m_name);
    }
};



#endif // CARDS_H
