#include <iostream>
#include "Lotto.h"



int main() {

    Lotto lotto;
    lotto.parseInput(std::cin);
    lotto.play_game(std::cout);

    return 0;
}
