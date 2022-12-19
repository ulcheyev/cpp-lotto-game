//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_LOTTOUTILS_H
#define UNTITLED_LOTTOUTILS_H


#include <cstdlib>
#include <random>
#include "ScoreCard.h"
#include "Constants.h"



class LottoUtils {
public:
    LottoUtils() = default;
    static size_t generateNumberForKeg();
    size_t generateNumberForCell();
    std::unique_ptr<ScoreCard>  generateScoreCardWithRandomNumbers(std::string id, size_t width, size_t height, float fullness);
    static bool yesOrNo(float probabilityOfYes);
    static size_t findDigitsCount(int number);

private:

    static std::vector<size_t> kegsNumbers;
    static std::vector<size_t> cellsNumbers;

    static std::random_device seed;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dist;
};


#endif //UNTITLED_LOTTOUTILS_H
