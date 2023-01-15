//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_BOXWITHKEGS_H
#define UNTITLED_BOXWITHKEGS_H


#include <vector>
#include <memory>
#include "ScoreCard.h"

/**
 * Class represents the box with kegs.
 * To speed up the game, numbers are generated from the score card.
 */
class BoxWithKegs {
public:
    /**
     * Generate box with numbers, dependent on the numbers of the card.
     * @param scoreCard specified card
     */
    void generateBox(std::unique_ptr<ScoreCard>& scoreCard );

    /**
     * Return random keg value.
     * @return random keg value
     */
    size_t randomKeg();

    /**
     * Returns true, if box is empty, otherwise false.
     * @return true, if box is empty
     */
    bool isEmpty();

private:
    std::vector<size_t> kegs;  // kegs numbers
};


#endif //UNTITLED_BOXWITHKEGS_H
