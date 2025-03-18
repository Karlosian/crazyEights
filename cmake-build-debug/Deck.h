//
// Created by karson on 3/5/2025.
//

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

class Deck {
private:
    //using vector as it stores on heap by default and is resizable
    //when dealing a card, we will discard it using pop_back
    //this implementation makes the most sense for the game im making, crazy eights
    std::vector<Card> cards;
    int getRNG();
    public:
    Deck(const Deck &other);
    Deck();
    void initialize();
    void shuffle();
    Card dealCard();
    bool moreCards();
   // void addCard(Card c);
    Card getCard(int index);



};



#endif //DECK_H
