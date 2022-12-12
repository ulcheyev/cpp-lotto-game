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

    InputParser inputParser;
    std::cin >> inputParser;

    LottoRandomizer lottoRandomizer;
    ScoreCard scoreCard = lottoRandomizer.generateScoreCardWithRandomNumbers(
            inputParser.getWidth(),
            inputParser.getHeight(),
            inputParser.getFullness()
            );



    std::cout << scoreCard;

    return 0;
}
