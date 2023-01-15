#include <iostream>
#include <thread>
#include "Lotto.h"
#include "OutputMaker.h"

int main(){
    set_raw(true);
    Lotto lotto;




    lotto.identifyCardData(std::cin);
    lotto.play_game();

    auto computeThread = [](Lotto& player) {
        bool q = false;
        while (!q) {
            player.makeTurn();
            q = player.isFinished();
        }
    };

    auto inputThread = [](Lotto& player) {
        bool q = false;
        while (!q) {
            player.parseInput();
            q = player.isFinished();
        }
    };



    std::thread t1(computeThread, std::ref(lotto));
    std::thread t2(inputThread, std::ref(lotto));
    t1.join();
    t2.join();

    set_raw(false);

    return 0;
}
