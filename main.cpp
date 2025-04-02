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



    int main() {

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


    while (!userDeck.empty() && !aiDeck.empty()) {
        readGameStatus(userDeck, aiDeck);
        while (!validated) {
            readAllCards(userDeck);
            std::cout << "Current card at the top of the deck: " << topCard << std::endl;
            //ask if want to draw


            std::cout << "What card would you like to play? (state the number)" << std::endl;
            std::cin >> playingIndex;
            validated = (topCard.getFace() == userDeck.at(playingIndex-1).getFace() || topCard.getSuit() == userDeck.at(playingIndex-1).getSuit());
            if (userDeck.at(playingIndex-1).getFace() == EIGHT) {
                validated = true;
                isEight = true;
                std::cout << "Pick a suit: " << "\n"  << "1: Clubs \n 2: Diamonds \n 3: Hearts \n 4: Spades "<< std::endl;
                int num = -1;
                while (num>4 || num<1) {
                    std::cin >> num;
                }
                switch (num) {
                    case 1: topCard.setSuit(CLUBS); break;
                    case 2: topCard.setSuit(DIAMONDS); break;
                    case 3: topCard.setSuit(HEARTS); break;
                    case 4: topCard.setSuit(SPADES); break;
                    default: topCard.setSuit(CLUBS);
                }
                topCard.setFace(EIGHT);
            }


        }
        if (!isEight) {
            topCard.setFace(userDeck.at(playingIndex-1).getFace());
            topCard.setSuit(userDeck.at(playingIndex-1).getSuit());
            userDeck.erase(userDeck.begin() + (playingIndex - 1));
        }

        isEight = false;
        validated = false;
        //then AI Plays
        int playable = false;
        int index = -1;
        for (int i = 0; i < aiDeck.size(); ++i) {
            if (aiDeck.at(i).getFace() == topCard.getFace() || aiDeck.at(i).getSuit() == topCard.getSuit()) {
                playable = true;
                index = i;
            }
        }
        if (!playable) {
            std::cout << "AI Draws card" << std::endl;
            aiDeck.push_back(dealingDeck.dealCard());
        }
        else {
            std::cout << "AI Plays card " << aiDeck.at(index) << std::endl;
            topCard = aiDeck.at(index);
            aiDeck.erase(aiDeck.begin() + (index));
        }
    playable = false;

    }

    return 0;
}


