//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <memory>
#include "Cell.h"



size_t Cell::getCellValue() const {
    return cellValue;
}


Cell::Cell(size_t value) {
    cellValue = value;
}



