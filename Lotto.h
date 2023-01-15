//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_LOTTO_H
#define UNTITLED_LOTTO_H

#include <memory>
#include <mutex>
#include <condition_variable>
#include "ScoreCard.h"
#include "BoxWithKegs.h"
#include "LottoUtils.h"
#include "InputParser.h"


/**
 * General class for game.
 */
class Lotto {

public:

    Lotto();
    /**
     * Starts the game. Identifies card and runs turn parsing.
     */
    void play_game();

    /**
     * Controls, if player's filled numbers match the winning chain
     */
    void makeTurn();

    /**
     * Parse input and identify card data: width, height.
     * Identify number of players.
     * @param istream istream
     */
    void identifyCardData(std::istream &istream);
    /**
     * Check. if game is finished
     * @return true, if game is finished
     */
    bool isFinished();

    /**
     * Parse input, when the user enters 'yes' or 'no'.
     */
    void parseInput();


private:
    bool  isFinish;
    bool takeInput  = false;
    std::vector<size_t> win_numbers; // win chain
    std::vector<std::pair<std::string, std::vector<size_t>>> numbers; //filled numbers by users


    std::unique_ptr<BoxWithKegs> box;
   std::unique_ptr<ScoreCard> scoreCard;
    std::unique_ptr<InputParser> input;
    std::unique_ptr<LottoUtils> utils;


    std::mutex m;
    std::condition_variable cv;

    /*
     * Identify necessary object: box, inputparser, utils..
     */
    void identifyObjects();
    void identifyScoreCard();
    std::string getPlayerMatchNumbers(std::vector<size_t>& nums);
    void closeNumbers();
    /*
     * Check if game has a winner. Returns winner name.
     */
    std::string& checkWinner();

};




#endif //UNTITLED_LOTTO_H
