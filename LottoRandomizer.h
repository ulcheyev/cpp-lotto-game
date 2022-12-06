//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_LOTTORANDOMIZER_H
#define UNTITLED_LOTTORANDOMIZER_H


#include <cstdlib>
#include <random>
#include "ScoreCard.h"

#define  MAX_NUMBER  99
#define  MIN_NUMBER  1


class LottoRandomizer {
public:
    LottoRandomizer() = default;
    size_t generateNumberForKeg();
    size_t generateNumberForCell();
    ScoreCard& generateScoreCardWithRandomNumbers(size_t width, size_t height, float fullness);
    static bool yesOrNo(float probabilityOfYes);
    static size_t findDigitsCount(int number);
private:

    std::vector<size_t> kegsNumbers;
    std::vector<size_t> cellsNumbers;

    std::random_device seed;
    std::mt19937 gen{seed()};
    std::uniform_int_distribution<> dist{MIN_NUMBER, MAX_NUMBER};
};


#endif //UNTITLED_LOTTORANDOMIZER_H
