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
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
        default: return "Unknown";
    }
}

#endif //SUIT_H
