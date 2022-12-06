//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_SCORECARD_H
#define UNTITLED_SCORECARD_H





#include <cstdlib>
#include <vector>
#include <ostream>
#include "Cell.h"

class ScoreCard {
public:

    //whitespace + 2 digits + whitespace
    const static size_t  THE_QUANTITY_OF_CELL_CHARACTERS = 4;



    ScoreCard() = default;
    ScoreCard(size_t wdh, size_t hgth);

    size_t getWidth() const;
    size_t getHeight() const;
    size_t getTotalNumbersInRow() const;
    void addCell(Cell* cell);
    void fillCell(size_t idx);

    friend std::ostream& operator<<(std::ostream& out, ScoreCard& scoreCard);
private:
    size_t width;
    size_t height;
    size_t quantityOfBorders;
    size_t totalCharactersQuantityInRow;
    std::vector<Cell*> cells;


};


#endif //UNTITLED_SCORECARD_H
