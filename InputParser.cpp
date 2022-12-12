//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iostream>
#include <limits>
#include "InputParser.h"
#include "Constants.h"


std::string type_info(const char* val){
    switch (*val){
        case 'i': return "integer"; break;
        case 'd': return "double"; break;
        case 'f': return "float"; break;
        case 's': return "string"; break;
        default: return "Unknown type. Try to change type_info.";
    }
}

template <typename T>
T readValue(const std::string& show_message, T max, T min, std::istream &input){
    T value_from_input;
    while (true){
        std::cout << show_message;
        input >> value_from_input;
        if(input.good()){

            if(value_from_input <= max && value_from_input >= min) {
                return value_from_input;
            }
            else{
                input.clear();
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "MAX value: " << max << ", MIN value: " << min << std::endl;
            }
        }
        else{
            input.clear();
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incompatible types. Expected type - " <<  type_info(typeid(T).name()) << ". Try to enter correct value." << std::endl;
        }
    }
}

std::istream &operator>>(std::istream &input, InputParser &parser) {
    parser.width = readValue<int>("Enter width:", MAX_SCORE_CARD_WIDTH, MIN_SCORE_CARD_WIDTH, input);
    parser.height = readValue<int>("Enter height:", MAX_SCORE_CARD_HEIGHT, MIN_SCORE_CARD_HEIGHT, input);
    parser.fullness = readValue<float>("Enter fullness:", MAX_SCORE_CARD_FULLNESS, MIN_SCORE_CARD_FULLNESS, input);
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


