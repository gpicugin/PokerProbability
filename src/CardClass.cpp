#include "CardClass.h"
#include<QDebug>


QString CardToString(Card card)
{
    switch (card) {
    case Card::clubs_2: return "clubs_2";
    case Card::clubs_3: return "clubs_3";
    case Card::clubs_4: return "clubs_4";
    case Card::clubs_5: return "clubs_5";
    case Card::clubs_6: return "clubs_6";
    case Card::clubs_7: return "clubs_7";
    case Card::clubs_8: return "clubs_8";
    case Card::clubs_9: return "clubs_9";
    case Card::clubs_10: return "clubs_10";
    case Card::clubs_jack: return "clubs_jack";
    case Card::clubs_queen: return "clubs_queen";
    case Card::clubs_king: return "clubs_king";
    case Card::clubs_ace: return "clubs_ace";

    case Card::diamonds_2: return "diamonds_2";
    case Card::diamonds_3: return "diamonds_3";
    case Card::diamonds_4: return "diamonds_4";
    case Card::diamonds_5: return "diamonds_5";
    case Card::diamonds_6: return "diamonds_6";
    case Card::diamonds_7: return "diamonds_7";
    case Card::diamonds_8: return "diamonds_8";
    case Card::diamonds_9: return "diamonds_9";
    case Card::diamonds_10: return "diamonds_10";
    case Card::diamonds_jack: return "diamonds_jack";
    case Card::diamonds_queen: return "diamonds_queen";
    case Card::diamonds_king: return "diamonds_king";
    case Card::diamonds_ace: return "diamonds_ace";

    case Card::hearts_2: return "hearts_2";
    case Card::hearts_3: return "hearts_3";
    case Card::hearts_4: return "hearts_4";
    case Card::hearts_5: return "hearts_5";
    case Card::hearts_6: return "hearts_6";
    case Card::hearts_7: return "hearts_7";
    case Card::hearts_8: return "hearts_8";
    case Card::hearts_9: return "hearts_9";
    case Card::hearts_10: return "hearts_10";
    case Card::hearts_jack: return "hearts_jack";
    case Card::hearts_queen: return "hearts_queen";
    case Card::hearts_king: return "hearts_king";
    case Card::hearts_ace: return "hearts_ace";

    case Card::spades_2: return "spades_2";
    case Card::spades_3: return "spades_3";
    case Card::spades_4: return "spades_4";
    case Card::spades_5: return "spades_5";
    case Card::spades_6: return "spades_6";
    case Card::spades_7: return "spades_7";
    case Card::spades_8: return "spades_8";
    case Card::spades_9: return "spades_9";
    case Card::spades_10: return "spades_10";
    case Card::spades_jack: return "spades_jack";
    case Card::spades_queen: return "spades_queen";
    case Card::spades_king: return "spades_king";
    case Card::spades_ace: return "spades_ace";
    case Card::shirt_card: return "shirt_card";
    case Card::unopen_card: return "unopen_card";
    default: {
        qDebug() << "error";
        return "error";
        }
    }
}


CardClass::CardClass()
{

}
