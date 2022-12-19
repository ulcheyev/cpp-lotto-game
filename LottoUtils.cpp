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
std::vector<size_t> LottoUtils::kegsNumbers;
std::vector<size_t> LottoUtils::cellsNumbers;


size_t LottoUtils::generateNumberForKeg() {
    size_t num = dist(gen);
    while(true) {
        auto search_res = std::find(kegsNumbers.begin(), kegsNumbers.end(), num);
        if(search_res == kegsNumbers.end()){
            kegsNumbers.push_back(num);
            return num;
        }
        num = dist(gen);
    }
}



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
std::unique_ptr<ScoreCard> LottoUtils::generateScoreCardWithRandomNumbers(std::string id, size_t width, size_t height, float fullness) {
    //TODO exception if fullness < 0.1

    std::unique_ptr<ScoreCard> res( new ScoreCard(id, width, height));

    for(size_t height = 0; height < res->getHeight(); ++height){

        for(size_t width = 0; width < res->getWidth(); ++width){
            Cell *cell;
            if(yesOrNo(fullness)) {
                size_t cellNumber = generateNumberForCell();
                cell = new Cell(cellNumber);
            }else{
                cell = new Cell;
            }
            res->addCell(cell);
        }
    }

    return res;
}

bool LottoUtils::yesOrNo(float probabilityOfYes) {
    return rand()%100 < (probabilityOfYes * 100);
}


size_t LottoUtils::findDigitsCount(int number){
    int digits = 0;
    do
    { number /= 10; digits++; }
    while (number != 0);
    return digits;
}




