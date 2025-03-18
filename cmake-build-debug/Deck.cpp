//
// Created by karson on 3/5/2025.
//

#include "Deck.h"
#include "Suit.h"
#include <random>

void Deck::initialize() {
    cards.resize(52);
    //set cards
     int counter=0;
     for (int i = 0; i<4; i++) {
         for (int j = 1; j<=13; j++) {
             switch (i) {
                 case 0: this->cards.at(counter).setSuit(CLUBS); break;
                 case 1: this->cards.at(counter).setSuit(DIAMONDS); break;
                 case 2: this->cards.at(counter).setSuit(HEARTS); break;
                 case 3: this->cards.at(counter).setSuit(SPADES); break;
                 default: this->cards.at(counter).setSuit(CLUBS); break;
                 break;
             }
             this->cards.at(counter).setFace(j);
             counter++;
         }
     }
 }
int Deck::getRNG() {
    std::random_device rd;  //seed
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 51);

    return dist(gen);

}
Deck::Deck() {
     initialize();
 }
Card Deck::dealCard() {
    Card c = cards.back();
    cards.pop_back();
    return c;

}
bool Deck::moreCards() {
    if (cards.size()>0) {
        return true;
    }
    return false;
}

Card Deck::getCard(int index) {
    return cards.at(index);
}

void Deck::shuffle() {
    Card temp;
    int rng;
    for (int i = 0; i < cards.size(); ++i) {
        rng = getRNG();
        temp = cards.at(i);
        cards.at(i) = cards.at(rng);
        cards.at(rng) = temp;
    }
    return;
}