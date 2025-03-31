    #include <iostream>
    #include <deque>
    #include "cmake-build-debug/Deck.h"

void readAllCards(std::deque<Card>& cards) {
        std::cout << "Your current cards: " << std::endl;
        for (int i = 0; i < cards.size(); ++i) {
            std::cout << i+1 << " " << cards.at(i) << std::endl;
        }
    }

void readGameStatus(std::deque<Card>& cards, std::deque<Card>& enemyCards) {
    std::cout << "Your opponent has " << enemyCards.size() << " cards" << std::endl;
    std::cout << "You currently have " << cards.size() << " cards." << std::endl;
    readAllCards(cards);
}



    int main(){
    /*
     *In main.cpp, you should create a DeckOfCards object,
     *shuffle the cards then deal the 52 cards.
     *The cards should be outputted to the screen as dealt.
     */
        bool gameDone = false;
        Deck dealingDeck = Deck();
        dealingDeck.shuffle();
        //deal 5 cards in an unordered set
        std::deque<Card> userDeck ={dealingDeck.dealCard(), dealingDeck.dealCard(), dealingDeck.dealCard(), dealingDeck.dealCard(), dealingDeck.dealCard()};
        std::deque<Card> aiDeck ={dealingDeck.dealCard(), dealingDeck.dealCard(),dealingDeck.dealCard(),dealingDeck.dealCard(),dealingDeck.dealCard()};

        std::cout << "Beginning game of Crazy Eights against AI opponent" << std::endl;
        Card topCard = dealingDeck.dealCard();
        int playingIndex = 0;
        bool validated = false;
        bool isEight = false;
        while (userDeck.size() > 0 || aiDeck.size() > 0) {
            readGameStatus(userDeck, aiDeck);
            while (!validated) {
                readAllCards(userDeck);
                std::cout << "Current card at the top of the deck: " << topCard << std::endl;
                std::cout << "What card would you like to play? (state the number)" << std::endl;
                std::cin >> playingIndex;
                validated = (topCard.getFace() == userDeck.at(playingIndex-1).getFace() || topCard.getSuit() == userDeck.at(playingIndex-1).getSuit()){
                if (userDeck.at(playingIndex-1).getFace() == EIGHT) {
                    isEight = true;
                    validated = true;
                }
                }
                if (isEight) {
                    std::cout << "Pick a suit: " << "\n"  << "1: Clubs \n 2: Diamonds \n 3: Hearts \n 4: Spades "<< std::endl;
                    //take in num
                    isEight = false;
                }

            }
        }

        return 0;

    }



