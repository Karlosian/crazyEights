#include <iostream>

#include "cmake-build-debug/Deck.h"



    Deck deck = Deck();
    std::cout << "Unshuffled" << std::endl;
    for (int i = 0; i<52; i++) {
        std::cout << deck.getCard(i) << std::endl;
    }

    std::cout << "Shuffled" << std::endl;

    deck.shuffle();

    for (int i = 0; i<52; i++) {
        std::cout << deck.dealCard() << std::endl;
    }

    return 0;

}

