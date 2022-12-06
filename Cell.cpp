//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "Cell.h"



size_t Cell::getCellValue() const {
    return cellValue;
}


Cell::Cell(size_t value) {
    cellValue = value;
}


void Cell::fillCell() {
    filled = true;
}

bool Cell::getFilled() const {
    return filled;
}

