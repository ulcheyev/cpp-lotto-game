#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include<bits/stdc++.h>

#include "Keg.h"
#include "ScoreCard.h"
#include "BoxWithKegs.h"
#include "InputParser.h"
#include "LottoRandomizer.h"
#include "Cell.h"



int main() {

    //TODO pole mozhet byt tolko max 40 elementov

    size_t width = 10;
    size_t height = 3;
    float fullness = 1;

//    InputParser inputParser;
//    std::cin >> inputParser;

    LottoRandomizer lottoRandomizer;
//    ScoreCard scoreCard = lottoRandomizer.generateScoreCardWithRandomNumbers(
//            inputParser.getWidth(),
//            inputParser.getHeight(),
//            inputParser.getFullness()
//            );

    ScoreCard scoreCard = lottoRandomizer.generateScoreCardWithRandomNumbers(
            width,
            height,
            fullness
    );


    std::cout << scoreCard;

    scoreCard.fillCell(0);
    scoreCard.fillCell(5);

    std::cout << scoreCard;

//    scoreCard.
    return 0;
}
