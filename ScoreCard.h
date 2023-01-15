//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_SCORECARD_H
#define UNTITLED_SCORECARD_H

#include <cstdlib>
#include <memory>
#include <vector>
#include <ostream>
#include "Cell.h"

/**
 * Class represents score card with numbers
 */
class ScoreCard {
public:

    ScoreCard() = default;
    ScoreCard(size_t wdh, size_t hgth);
    ScoreCard(const ScoreCard&);
    ScoreCard(ScoreCard&&) noexcept ;
    ScoreCard& operator=(const ScoreCard&);
    ScoreCard& operator=(ScoreCard&&) noexcept;

    /**
     * Returns score card width
     * @return score card width
     */
    size_t getWidth() const;

    /**
     * Returns score card height
     * @return score card height
     */
    size_t getHeight() const;

    /**
     * Add cell to score card
     * @param value cell value to add
     */
    void addCell(const size_t value);
    /**
     * Swap current score card with specified score card.
     */
    void swap(ScoreCard&);

    friend std::ostream& operator<<(std::ostream& out, ScoreCard& scoreCard);

    /**
     * Returns cells from score card
     * @return cells from score card
     */
    const std::vector<std::unique_ptr<Cell>> &getCells() const;

private:

    size_t width;
    size_t height;
    size_t totalCharactersQuantityInRow;
    std::vector<std::unique_ptr<Cell>> cells;
};


#endif //UNTITLED_SCORECARD_H
