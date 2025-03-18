//
// Created by karson on 3/7/2025.
//

#ifndef FACE_H
#define FACE_H

enum Face { ACE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

inline const char* ToString(Face f)
{
    switch (f)
    {
        case ACE:   return "Ace";
        case ONE:   return "One";
        case TWO:   return "Two";
        case THREE: return "Three";
        case FOUR:  return "Four";
        case FIVE:  return "Five";
        case SIX:   return "Six";
        case SEVEN: return "Seven";
        case EIGHT: return "Eight";
        case NINE:  return "Nine";
        case TEN:   return "Ten";
        case JACK:  return "Jack";
        case QUEEN: return "Queen";
        case KING: return "King";
        default: return "Unknown";
    }
}



#endif //FACE_H
