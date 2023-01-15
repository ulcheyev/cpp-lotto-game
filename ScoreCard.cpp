//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iomanip>
#include <algorithm>
#include "ScoreCard.h"
#include "Constants.h"
#include "LottoUtils.h"
#include "OutputMaker.h"


ScoreCard::ScoreCard(size_t wdh, size_t hgth) :width (wdh), height(hgth){

        totalCharactersQuantityInRow =
        width
        *
        THE_QUANTITY_OF_CELL_CHARACTERS;
}

size_t ScoreCard::getWidth() const {
    return width;
}

size_t ScoreCard::getHeight() const {
    return height;
}


std::ostream &operator<<(std::ostream &out, ScoreCard& scoreCard) {

    if(scoreCard.cells.empty()){
        out << "ScoreCard cells  is  empty" << std::endl;
        return out;
    }
    resetConsole();
    std::ostringstream ss;

    //Add -
    for(size_t w_idx = 0; w_idx < scoreCard.width*2; ++w_idx){
        ss<<"－";
    }
    ss<<std::endl;

    //Add numbers and |
    for(size_t idx = 0; idx <= scoreCard.height * scoreCard.width-1; ++idx) {

        size_t val = scoreCard.cells[idx]->getCellValue();
        ss << '|';

        if (val != 0) {
            const size_t digitsCount = LottoUtils::findDigitsCount(val);
            ss << std::right << std::setw(W_FOR_NOT_0 - digitsCount * 2);
            ss << COLOR_RED << val;
            ss << ' ' << ANSI_COLOR_RESET;
        }

        if((idx + 1)%scoreCard.width == 0){
            ss <<'|'<< std::endl;
            //Add the line between the rows
            //Add -
            for(size_t w_idx = 0; w_idx < scoreCard.width*2; ++w_idx){
                ss<<"－";
            }
            ss << std::endl;
        }
    }
    out << ss.str();
    return out;
}


void ScoreCard::addCell(const size_t value) {
    cells.push_back(std::make_unique<Cell>(value));
}



void ScoreCard::swap(ScoreCard & rhs) {
    using std::swap;
    swap(this->width, rhs.width);
    swap(this->height , rhs.height);
    swap(this->totalCharactersQuantityInRow ,rhs.totalCharactersQuantityInRow);
    swap(this->cells, rhs.cells);
}

ScoreCard::ScoreCard(const ScoreCard & rhs):
width(rhs.width)
, height(rhs.height)
, totalCharactersQuantityInRow(rhs.totalCharactersQuantityInRow)
{
    for(auto& cell: rhs.cells){
        this->addCell(cell->getCellValue());
    }
}

ScoreCard &ScoreCard::operator=(const ScoreCard &rhs) {
    ScoreCard temp(rhs);
    this->swap(temp);
    return *this;
}

ScoreCard::ScoreCard(ScoreCard && rhs) noexcept {
    ScoreCard temp;
    this->swap(rhs);
    rhs.swap(temp);
}

ScoreCard &ScoreCard::operator=(ScoreCard && rhs) noexcept {
    ScoreCard temp(std::move(rhs));
    this->swap(temp);
    return *this;
}


const std::vector<std::unique_ptr<Cell>> &ScoreCard::getCells() const {
    return cells;
}










