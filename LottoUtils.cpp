//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "LottoUtils.h"
#include <vector>
#include <ctime>
#include<bits/stdc++.h>

std::random_device LottoUtils::seed;
std::mt19937 LottoUtils::gen{seed()};
std::uniform_int_distribution<> LottoUtils::dist{MIN_CELL_NUMBER, MAX_CELL_NUMBER};
std::vector<size_t> LottoUtils::cellsNumbers;





size_t LottoUtils::generateNumberForCell() {
    size_t num = dist(gen);
    while(true) {
        auto search_res = std::find(cellsNumbers.begin(), cellsNumbers.end(), num);
        if(search_res == cellsNumbers.end()){
            cellsNumbers.push_back(num);
            return num;
        }
        num = dist(gen);
    }
}

/*
 * Fullness parameter
 * MAX = 1 -> 100%
 * MIN = 0.1 -> 10%
 */
std::unique_ptr<ScoreCard> LottoUtils::generateScoreCardWithRandomNumbers(size_t width, size_t height) {
    //TODO exception if fullness < 0.1

    std::unique_ptr<ScoreCard> res( new ScoreCard(width, height));

    for(size_t height = 0; height < res->getHeight(); ++height){

        for(size_t width = 0; width < res->getWidth(); ++width){
            size_t cellNumber = generateNumberForCell();
            res->addCell(cellNumber);
        }
    }
    return res;
}

size_t LottoUtils::findDigitsCount(int number){
    int digits = 0;
    do
    { number /= 10; digits++; }
    while (number != 0);
    return digits;
}


bool LottoUtils::checkNumbersPresentInCard(std::vector<size_t> vector1) {
    for(size_t num: vector1){
        if(!checkContainingElement(cellsNumbers, num)){
            return false;
        }
    }
    return true;
}

std::string LottoUtils::vecToString(std::vector<size_t> & vec) {
    std::string res;
    for(auto num: vec){
       res.append(std::to_string(num)+" ");
    }
    return res;
}









