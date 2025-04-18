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
        case ACE:   return "A ";
        case ONE:   return "1 ";
        case TWO:   return "2 ";
        case THREE: return "3 ";
        case FOUR:  return "4 ";
        case FIVE:  return "5 ";
        case SIX:   return "6 ";
        case SEVEN: return "7 ";
        case EIGHT: return "8 ";
        case NINE:  return "9 ";
        case TEN:   return "10";
        case JACK:  return "J ";
        case QUEEN: return "Q ";
        case KING: return "K ";
        default: return "Unknown";
    }
}



#endif //FACE_H
