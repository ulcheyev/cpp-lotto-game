//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "BoxWithKegs.h"
#include "Constants.h"
#include "LottoUtils.h"
#include "OutputMaker.h"

size_t BoxWithKegs::randomKeg() {
   printOne(COLOR_BLUE, "===ᐅMix the box wellᐊ===" );
    auto iter = LottoUtils::select_randomly(kegs.begin(), kegs.end());
    auto res = *iter;
    kegs.erase(iter);
    printArgs(COLOR_BLUE, "\n===ᐅThe keg with the number ",  res,  " is dropped outᐊ===");
    return res;
}


bool BoxWithKegs::isEmpty() {
    return kegs.empty();
}

void BoxWithKegs::generateBox(std::unique_ptr<ScoreCard> &scoreCard) {
        for(auto &cell: scoreCard->getCells()){
             kegs.push_back(cell->getCellValue());
        }
}
