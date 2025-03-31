//
// Created by karson on 2/27/2025.
//

#include "Card.h"
#include <iostream>
#include "Face.h"
#include "Suit.h"

Card::Card(enum Face face, enum Suit suit) {
    this->face = face;
    this->suit = suit;
    return;
}

Card::Card(const Card &card): face(card.face), suit(card.suit) {}

Card::Card(): face(ACE), suit(CLUBS) {}

Card &Card::operator=(const Card &card) {
    this->face = card.face;
    this->suit = card.suit;
    return *this;
}

enum Face Card::getFace() const {
    return this->face;
}
enum Suit Card::getSuit() const{
    return this->suit;
}
void Card::setFace(const enum Face face) {
    this->face = face;
}
void Card::setFace(const int face) {
    switch (face) {
        case 1: this->face = ACE; break;
        case 2: this->face = TWO; break;
        case 3: this->face = THREE; break;
        case 4: this->face = FOUR; break;
        case 5: this->face = FIVE; break;
        case 6: this->face = SIX;break;
        case 7: this->face = SEVEN;break;
        case 8: this->face = EIGHT;break;
        case 9: this->face = NINE;break;
        case 10: this->face = TEN;break;
        case 11: this->face = JACK;break;
        case 12: this->face = QUEEN;break;
        case 13: this->face = KING;break;
        default: this->face = ACE;break;
    }
    return;
}

bool Card::operator==(const Card& other) const{
return this->suit == other.suit && this->face == other.face;
}

bool Card::operator<(const Card& other) const{
    return this->face < other.face && this->suit < other.suit;
}


void Card::setSuit(enum Suit suit) {
    this->suit = suit;
}
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << ToString(card.getFace()) << " of "  << ToString(card.getSuit());
    return os;
}