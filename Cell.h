//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H

#include <cstdlib>

/**
 * Class represents cell in score card.
 */
class Cell {
public:
    Cell() = default;
    /**
     * Constructor with cell value.
     * @param value cell value
     */
    Cell(size_t  value);

    /**
     * Returns cell value.
     * @return cell value
     */
    size_t  getCellValue() const;
private:

    /*
     *0 = empty cell. Flag variable, because in lotto 0 does not exist.
     * */
    size_t cellValue = 0;
};


#endif //UNTITLED_CELL_H
