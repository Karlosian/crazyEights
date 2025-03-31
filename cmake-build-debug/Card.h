//
// Created by karson on 2/27/2025.
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include "Face.h"
#include "Suit.h"
#include <iostream>

class Card {
    /*
     * We will assign numbers for special cards as such:
     *  1: Ace
     *  11: Jack
     *  12: Queen
     *  13: King
     */
private:
    //chose to use enum instead for readability
    enum Face face;
    enum Suit suit;
public:
    Card(enum Face face, enum Suit suit);
    Card(const Card &card);
    Card();
    enum Face getFace() const;
    enum Suit getSuit() const;
    void setFace(enum Face face);
    void setFace(int face);
    void setSuit(enum Suit suit);
    Card& operator=(const Card &card);
    bool operator==(const Card& other) const;
    bool operator<(const Card &card) const;

};
std::ostream& operator<<(std::ostream& os, const Card& card);



#endif //CARD_H
