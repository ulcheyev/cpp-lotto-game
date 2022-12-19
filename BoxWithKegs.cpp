//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iostream>
#include "BoxWithKegs.h"
#include "Constants.h"
#include "LottoUtils.h"

BoxWithKegs::BoxWithKegs() {
    generateBox();
}

void BoxWithKegs::generateBox() {
    for(size_t num = MIN_CELL_NUMBER; num <= MAX_CELL_NUMBER; num++ ){
        kegs.push_back(num);
    }
}

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}


size_t BoxWithKegs::randomKeg() {
    std::cout << "...Mix the box well..." << std::endl;
    auto iter = select_randomly(kegs.begin(), kegs.end());
    auto res = *iter;
    kegs.erase(iter);
    std::cout << "You got a keg with a number:" << " " << res << std::endl;
    return res;
}


bool BoxWithKegs::isEmpty() {
    return kegs.empty();
}
