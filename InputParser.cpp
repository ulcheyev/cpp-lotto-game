//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iostream>
#include "InputParser.h"

std::istream &operator>>(std::istream &input, InputParser &parser) {
    std::cout << "Enter width: ";
    input >> parser.width;
    std::cout << "Enter height: ";
    input >> parser.height;
    std::cout << "Enter fullness: ";
    input >> parser.fullness;
    return input;
}

size_t InputParser::getWidth() const {
    return width;
}


size_t InputParser::getHeight() const {
    return height;
}



float InputParser::getFullness() const {
    return fullness;
}


