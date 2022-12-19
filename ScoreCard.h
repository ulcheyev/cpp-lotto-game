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

class ScoreCard {
public:

    ScoreCard() = default;
    ScoreCard(std::string& id, size_t wdh, size_t hgth);
    ScoreCard(const ScoreCard&);
    ScoreCard(ScoreCard&&) noexcept ;
    ScoreCard& operator=(const ScoreCard&);
    ScoreCard& operator=(ScoreCard&&) noexcept;

    size_t getWidth() const;
    size_t getHeight() const;
    size_t getTotalNumbersInRow() const;
    const std::string &getIdentifier() const;
    size_t searchCell(size_t ) const;
    void addCell(Cell* cell);
    void fillCell(size_t idx);
    void swap(ScoreCard&);


    friend std::ostream& operator<<(std::ostream& out, ScoreCard& scoreCard);
private:

    size_t width;
    size_t height;
    size_t quantityOfBorders;
    size_t totalCharactersQuantityInRow;

    std::string identifier;

    std::vector<std::unique_ptr<Cell>> cells;

};


#endif //UNTITLED_SCORECARD_H
