//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "LottoRandomizer.h"
#include <vector>
#include <ctime>
#include<bits/stdc++.h>


size_t LottoRandomizer::generateNumberForKeg() {
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



size_t LottoRandomizer::generateNumberForCell() {
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
ScoreCard& LottoRandomizer::generateScoreCardWithRandomNumbers(size_t width, size_t height, float fullness) {
    //TODO exception if fullness < 0.1

    auto *scoreCard = new ScoreCard(width,height);

    for(size_t height = 0; height < scoreCard->getHeight(); ++height){

        for(size_t width = 0; width < scoreCard->getWidth(); ++width){
            Cell *cell;
            if(yesOrNo(fullness)) {
                size_t cellNumber = generateNumberForCell();
                cell = new Cell(cellNumber);
            }else{
                cell = new Cell;
            }
            scoreCard->addCell(cell);
        }
    }

    return *scoreCard;
}

bool LottoRandomizer::yesOrNo(float probabilityOfYes) {
    return rand()%100 < (probabilityOfYes * 100);
}

size_t LottoRandomizer::findDigitsCount(int number){
    int digits = 0;
    do
    { number /= 10; digits++; }
    while (number != 0);
    return digits;
}