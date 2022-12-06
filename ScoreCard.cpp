//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iomanip>
#include "ScoreCard.h"
#include "LottoRandomizer.h"




ScoreCard::ScoreCard(size_t wdh, size_t hgth) :width (wdh), height(hgth){
        quantityOfBorders = width + 1;

        totalCharactersQuantityInRow =
        width
        *
        THE_QUANTITY_OF_CELL_CHARACTERS
        +
        quantityOfBorders;
}

size_t ScoreCard::getWidth() const {
    return width;
}

size_t ScoreCard::getHeight() const {
    return height;
}


size_t ScoreCard::getTotalNumbersInRow() const {
    return totalCharactersQuantityInRow;
}



std::ostream &operator<<(std::ostream &out, ScoreCard &scoreCard) {
    if(scoreCard.cells.empty()){
        out << "ScoreCard cells field is  empty" << std::endl;
        return out;
    }

    //Add -
    for(size_t w_idx = 0; w_idx < scoreCard.totalCharactersQuantityInRow; ++w_idx){
        out<<"-";
    }
    out<<std::endl;

    //Add numbers and |
    for(size_t idx = 0; idx <= scoreCard.height * scoreCard.width - 1; ++idx){

        size_t val = scoreCard.cells[idx]->getCellValue();

        const size_t digitsCount = LottoRandomizer::findDigitsCount(val);
        const size_t W = ScoreCard::THE_QUANTITY_OF_CELL_CHARACTERS - digitsCount + 1;

        out<< "|" << std::setw(3);

        //When cell is not fiilled
        if(!scoreCard.cells[idx]->getFilled()) {
            if (val != 0) {
                out  << val << " ";
            } else {
                out << ' ' << " ";
            }
        }

        //When cell is filled
        else{
            out << 'X' << " ";
        }



        if((idx + 1)%scoreCard.width == 0){
            out <<"|"<< std::endl;
            //Add the line between the rows
            for (size_t w_idx = 0; w_idx < scoreCard.totalCharactersQuantityInRow ; ++w_idx) {
                out << "-";
            }
            out << std::endl;
        }


    }
    return out;

}

void ScoreCard::addCell(Cell *cell) {
    cells.push_back(cell);
}

void ScoreCard::fillCell(size_t idx) {
    cells[idx]->fillCell();
}




