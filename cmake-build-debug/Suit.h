//
// Created by karson on 3/5/2025.
//

#ifndef SUIT_H
#define SUIT_H

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

inline const char* ToString(Suit s)
{
    switch (s)
    {
        case HEARTS: return "♥";
        case DIAMONDS: return "♦";
        case CLUBS: return "♣";
        case SPADES: return "♠";
        default: return "Unknown";
    }
}

#endif //SUIT_H
