//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iomanip>
#include <algorithm>
#include "ScoreCard.h"
#include "Constants.h"
#include "LottoUtils.h"

ScoreCard::ScoreCard(std::string& id, size_t wdh, size_t hgth) :width (wdh), height(hgth), identifier(id){
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

        const size_t digitsCount = LottoUtils::findDigitsCount(val);
        const size_t W = THE_QUANTITY_OF_CELL_CHARACTERS - digitsCount + 1;

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
    cells.push_back(std::make_unique<Cell>(*cell));
}

void ScoreCard::fillCell(size_t idx) {
    cells[idx]->fillCell();
}


void ScoreCard::swap(ScoreCard & rhs) {
    using std::swap;
    swap(this->width, rhs.width);
    swap(this->height , rhs.height);
    swap(this->totalCharactersQuantityInRow ,rhs.totalCharactersQuantityInRow);
    swap(this->quantityOfBorders, rhs.quantityOfBorders);
    swap(this->cells, rhs.cells);
}

ScoreCard::ScoreCard(const ScoreCard & rhs):
width(rhs.width)
, height(rhs.height)
, totalCharactersQuantityInRow(rhs.totalCharactersQuantityInRow),
quantityOfBorders(rhs.quantityOfBorders)
{
    for(auto& cell: rhs.cells){
        this->addCell(cell.get());
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

const std::string &ScoreCard::getIdentifier() const {
    return identifier;
}

size_t ScoreCard::searchCell(size_t num) const {
    auto it = std::find_if(
            cells.begin(),
            cells.end(),
            [&num](const std::unique_ptr<Cell>& ptr) { return ptr->getCellValue() == num;});

    if(it != cells.end()){
        auto index = std::distance(cells.begin(), it);
        return index;
    }
    throw std::invalid_argument(std::to_string(num) + " does not exist in score card");
}










