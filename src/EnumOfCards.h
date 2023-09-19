#ifndef ENUMOFCARDS_H
#define ENUMOFCARDS_H
#include <QString>
enum Card {


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

QString CardToString(Card card);

#endif // ENUMOFCARDS_H
