//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iostream>
#include <limits>
#include "InputParser.h"
#include "Constants.h"
#include "LottoUtils.h"
#include "OutputMaker.h"
#include <sstream>
#include <iterator>
#include <mutex>
#include <csignal>
#include "Lotto.h"


std::string type_info(const char* val){
    switch (*val){
        case 'i': return "integer";
        case 'y': return "integer";
        case 'd': return "double";
        case 'f': return "float";
        case 's': return "string";
        case 'm': return "integer";
        default: std:: cout << "type " << val; return "Unknown type. Try to change type_info().";
    }
}


void InputParser::inputClear(std::istream &input) {
    input.clear();
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T InputParser::readValue(const std::string& show_message, T max, T min, std::istream &input){
    T value_from_input;
    while (true){

        printOne(show_message);
        input >> value_from_input;

        if(input.good()) {
                if (value_from_input <= max && value_from_input >= min) {
                    return value_from_input;
                } else {
                    InputParser::inputClear(input);
                    printArgs(ERROR_COLOR, "MAX value: ", max, ", MIN value: ", min);
                }
            }
        else{
            InputParser::inputClear(input);
            printArgs(
                    ERROR_COLOR,
                    "Incompatible types. Expected type - ",
                    type_info(typeid(T).name()) ,
                    ". Try to enter correct value." );
        }
    }
}


std::string InputParser::readString(const std::string& show_message, size_t max, size_t min, std::istream &input) {
    std::string value_from_input;
    while (true) {
       printOne( show_message);
        do{
            getline(input, value_from_input);
        }
        while (value_from_input.empty());

        value_from_input.shrink_to_fit();

        if (input.good()) {

            if(max == 0 || min == 0) {
                return value_from_input;
            }
                if (value_from_input.length() <= max && value_from_input.length() >= min) {
                    return value_from_input;
                } else {
                    InputParser::inputClear(input);
                    printOne(show_message);
                    printArgs(ERROR_COLOR, "MAX value: ", max, ", MIN value: ", min);
                }
            }
    }
}

void InputParser::listener() {
    printOne("Press ENTER to start");
    // Set terminal to raw mode
    set_raw(true);
    getchar();
    // Echo input:
    set_raw(false);
}


void InputParser::parseCardData() {
   listener();
   width = InputParser::readValue<size_t>("Enter card width:", MAX_SCORE_CARD_WIDTH, MIN_SCORE_CARD_WIDTH, std::cin);
   height =  InputParser::readValue<size_t>("Enter card height:", MAX_SCORE_CARD_HEIGHT, MIN_SCORE_CARD_HEIGHT, std::cin);
    sizeOfWinSequence =  InputParser::readValue<size_t>("Enter size of win sequence:", width, width/2, std::cin);
    numberOfPlayers =  InputParser::readValue<size_t>("Enter number of players:", MAX_CELL_NUMBER/(width * height), MIN_NUMBER_OF_PLAYERS, std::cin);

    for(size_t num = 1; num <= numberOfPlayers; num++){
        std::stringstream ss;
        ss << "Player N" << num << " name:";
        std::string res = ss.str();
        identifiers.push_back(InputParser::readString(res, MAX_IDENTIFIER_LENGTH, MIN_IDENTIFIER_LENGTH, std::cin));
    }
}

size_t InputParser::getWidth() const {
    return width;
}

size_t InputParser::getHeight() const {
    return height;
}


size_t InputParser::getNumberOfPlayers() const {
    return numberOfPlayers;
}

const std::vector<std::string> &InputParser::getIdentifiers() const {
    return identifiers;
}



std::vector<size_t> InputParser::parseTurn(std::unique_ptr<ScoreCard>& card, std::string& playerId) {
    std::string s;
    const std::string &string = readSpecifiedString(
            playerId+", type 'random' for quick pick or 'manual' for manual enter:",
            "manual", "random");

    if (std::equal(string.begin(), string.end(), "random")) {
        std::vector<size_t> res;
        for (int i = 0; i < sizeOfWinSequence; i++) {
            size_t value = (*LottoUtils::select_randomly(
                    card->getCells().begin(), card->getCells().end()))->getCellValue();
            while (LottoUtils::checkContainingElement(res, value)) {
                value = (*LottoUtils::select_randomly(
                        card->getCells().begin(), card->getCells().end()))->getCellValue();
            }
            res.push_back(value);
        }

        return res;
    }
    else {
        while (true) {
            printArgs(
                    COLOR_BLUE,
                    playerId, ", your turn to close numbers. Type ",
                    sizeOfWinSequence, " numbers seperated by space: "
            );

            s.clear();
            std::cin.clear();
            fflush(stdin);

            std::getline(std::cin, s);
            std::istringstream is(s);
            std::vector<size_t> v((std::istream_iterator<size_t>(is)), std::istream_iterator<size_t>());

            if (std::cin.good()) {
                if (v.size() < sizeOfWinSequence || v.size() > sizeOfWinSequence) {
                    printArgs(ERROR_COLOR, playerId,
                              ", please, type ", sizeOfWinSequence, " numbers");
                } else if (LottoUtils::checkHasDuplicates(v.begin(), v.end())) {
                    printArgs(ERROR_COLOR, playerId,
                              ", please, type unique numbers.");
                } else if (!LottoUtils::checkNumbersPresentInCard(v)) {
                    printArgs(ERROR_COLOR, playerId,
                              ", please, type numbers, which presents in score card.");
                } else { return v; }
            }
        }
    }
}



size_t InputParser::getSizeOfWinSequence() const {
    return sizeOfWinSequence;
}

bool InputParser::parseInput() {
    auto res = readSpecifiedString("Enter yes/no:", "yes", "no");
    _continue = true;
    if(std::equal(res.begin(), res.end(),"yes")){
        return false;
    }
    return true;
}

bool InputParser::isContinue() const {
    return _continue;
}

void InputParser::setContinue(bool cont) {
    _continue = cont;
}












