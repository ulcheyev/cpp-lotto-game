//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_LOTTO_H
#define UNTITLED_LOTTO_H

#include <memory>
#include "ScoreCard.h"
#include "BoxWithKegs.h"
#include "LottoUtils.h"
#include "InputParser.h"

class Lotto {

public:

    Lotto();
    void play_game(std::ostream &out);
    void makeTurn(std::unique_ptr<ScoreCard>&);
    void identifyObjects();
    void parseInput(std::istream &istream);
    void printCard(std::unique_ptr<ScoreCard>& card);
    void print(std::ostream &out, std::string& );
    void handleCards();
private:

    void identifyScoreCard();
    bool isFinished = false;

    std::unique_ptr<BoxWithKegs> box;
    std::vector<std::unique_ptr<ScoreCard>> scoreCards;
    std::unique_ptr<InputParser> input;
    std::unique_ptr<LottoUtils> utils;

};


#endif //UNTITLED_LOTTO_H
