//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H

#include <cstdlib>

class Cell {
public:
    Cell() = default;
    Cell(size_t  value);
    size_t  getCellValue() const;
    void fillCell();
    bool getFilled() const;
private:

    /*
     *0 = empty cell. Flag variable, because in lotto 0 does not exist.
     * */
    size_t cellValue = 0;
    bool filled = false;
};


#endif //UNTITLED_CELL_H
