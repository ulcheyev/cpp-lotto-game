//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "Lotto.h"
#include <unistd.h>
#include <thread>
#include "Constants.h"
#include "OutputMaker.h"


Lotto::Lotto() {
    printLogo();
    identifyObjects();
}

void Lotto::identifyObjects(){
    box = std::make_unique<BoxWithKegs>();
    input = std::make_unique<InputParser>();
    utils = std::make_unique<LottoUtils>();
}

void Lotto::identifyCardData(std::istream  &istream) {
    InputParser *pParser = this->input.get();
    pParser->parseCardData();
}

void Lotto::identifyScoreCard() {
    scoreCard = (
            utils->generateScoreCardWithRandomNumbers(
                    input->getWidth(),
                    input->getHeight())
    );
    box->generateBox(scoreCard);
}


void Lotto::play_game() {
    printOne(PLAY_HEADER);
    identifyScoreCard();
    closeNumbers();
}

std::string Lotto::getPlayerMatchNumbers(std::vector<size_t> &nums) {
    std::vector<size_t> match;
    for(auto num: nums){
        if(LottoUtils::checkContainingElement(win_numbers, num)){
            match.push_back(num) ;
        }
    }
    return LottoUtils::vecToString(match);
}



void Lotto::makeTurn() {
    std::unique_lock<std::mutex> lg(m);

    if(box->isEmpty()) {

        printArgs(COLOR_RED, "===ᐅThe box is empty. Play again?",
                  LottoUtils::vecToString(win_numbers), "ᐊ===");

        takeInput = true;
        cv.notify_one();
        cv.wait(lg, [&] {return input->isContinue();});
        input->setContinue(false);
        if(isFinish){ return;}
        play_game();
        return;
    }
    for(auto idx = 0; idx < input->getSizeOfWinSequence(); idx++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        bool pl = false;

        printLine();
        size_t keg = box->randomKeg();
        win_numbers.push_back(keg);

        for (auto& player: numbers) {
            if(LottoUtils::checkContainingElement(player.second, keg)){
                pl = true;
                printArgs(
                        COLOR_GREEN, "===ᐅPlayer ", player.first,  " was lucky: ",
                        getPlayerMatchNumbers(player.second));
            }
        }
        if(!pl){
            printArgs(COLOR_RED, "===ᐅThere was no lucky person for this numberᐊ===");
        }
    }
    printLine();
    std::string &basicString = checkWinner();
    if(basicString.empty()){

        printArgs(COLOR_RED, "===ᐅThere was no lucky person for this chain: ",
                  LottoUtils::vecToString(win_numbers), "ᐊ===");
        printArgs(COLOR_BLUE, "===ᐅType yes to continue, no for quit:ᐊ===");

        takeInput = true;
        cv.notify_one();
        cv.wait(lg, [&] {return input->isContinue();});
        input->setContinue(false);
        if(isFinish){ return;}
        win_numbers.clear();

    }else{
        printArgs(COLOR_CYAN, "===ᐅ", basicString,
                  " WINᐊ===");
        printOne(COLOR_BLUE, "===ᐅPlay again?ᐊ===\n");

        takeInput = true;
        cv.notify_one();
        cv.wait(lg, [&] {return input->isContinue();});
        input->setContinue(false);
        if(isFinish){ return;}
        win_numbers.clear();
        numbers.clear();
        play_game();
    }


}


void Lotto::closeNumbers() {
    for(auto idx = 0; idx < input->getNumberOfPlayers(); idx++){
        printCard(scoreCard);
        std::string id = input->getIdentifiers()[idx];
        std::vector<size_t> vector = input->parseTurn(scoreCard, id);
        printArgs(COLOR_RED, "Filled numbers: ", LottoUtils::vecToString(vector));
        numbers.emplace_back(id, vector);
    }
}

std::string& Lotto::checkWinner() {
    bool flag = true;
    static std::string res;
    for (auto& player: numbers) {
        for(auto num: player.second){
            if(!LottoUtils::checkContainingElement(win_numbers, num)){
                flag = false;
            }
        }
        if(flag){
            res = player.first;
            break;
        }
    }
    return res;
}

bool Lotto::isFinished() {
    return isFinish;
}

void Lotto::parseInput() {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [&] {return takeInput;});
    takeInput = false;
    isFinish = input->parseInput();
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}





















