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

bool isDeckPlayable(std::deque<Card> hand, Card topCard) {
    bool playable = false;
    for (int i = 0; i < hand.size(); ++i) {
        if (hand.at(i).getFace() == topCard.getFace() || hand.at(i).getSuit() == topCard.getSuit() || hand.at(i).getFace() == EIGHT) {
            playable = true;
        }
    }
return playable;
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
    bool cardDrawn = false;

    while (!userDeck.empty() && !aiDeck.empty()) {
        readGameStatus(userDeck, aiDeck);
            std::cout << "Current card at the top of the deck: " << topCard << std::endl;
            //ask if want to draw
            int drawCard = -1;
            while (drawCard !=1 && drawCard !=0) {
                std::cout << "Would you like to draw a card? (0 = no, 1 = yes)" << std::endl;
                std::cin >> drawCard;
                if (drawCard == 0 && !isDeckPlayable(userDeck, topCard)) {
                    std::cout << "You have no playable cards" << std::endl;
                    drawCard = -1;
                }
            }
            if (drawCard == 1) {
                userDeck.push_front(dealingDeck.dealCard());
                validated = true;
                cardDrawn = true;
                std::cout << "You drew : " << userDeck.front() << std::endl;
            }
            else {
                while (!validated) {
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
                        userDeck.erase(userDeck.begin()+(playingIndex-1));
                    }
                }
            }


        if (!isEight && !cardDrawn) {
            //add card to top of pile then remove card from user deck
            topCard.setFace(userDeck.at(playingIndex-1).getFace());
            topCard.setSuit(userDeck.at(playingIndex-1).getSuit());
            userDeck.erase(userDeck.begin() + (playingIndex - 1));
        }
        //reset vars
        isEight = false;
        validated = false;
        cardDrawn = false;
        //then AI Plays
        if (!userDeck.empty()) {
            int playable = false;
            int index = -1;
            for (int i = 0; i < aiDeck.size(); ++i) {
                if (aiDeck.at(i).getFace() == topCard.getFace() || aiDeck.at(i).getSuit() == topCard.getSuit() || aiDeck.at(i).getFace() == EIGHT) {
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
                if (aiDeck.at(index).getFace() == EIGHT) {
                    //special logic, always go for suit of first card, or second if eight is index 0
                    if (index!=0) {
                        //if its not in index 0
                        std::cout << "AI sets suit to " << aiDeck.at(0).getSuit() << std::endl;
                        topCard.setSuit(aiDeck.at(0).getSuit());

                    }
                    else if ((int)aiDeck.size()>1) {
                        //if its in index 0
                        std::cout << "AI sets suit to " << aiDeck.at(1).getSuit() << std::endl;
                        topCard.setSuit(aiDeck.at(1).getSuit());

                    }
                    else {
                        //if its the last card
                        std::cout << "AI sets suit to " << aiDeck.at(index).getSuit() << std::endl;
                        topCard.setSuit(aiDeck.at(index).getSuit());

                    }
                    topCard.setFace(EIGHT);
                }
                else {
                    topCard = aiDeck.at(index);
                }
                aiDeck.erase(aiDeck.begin() + (index));

            }
            playable =  false;
        }    }

    if (aiDeck.empty()) {
        std::cout << "AI Wins!";
    }
    else {
        std::cout << "You win!";
    }

    return 0;
}


