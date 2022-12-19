//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include <iostream>
#include <limits>
#include "InputParser.h"
#include "Constants.h"
#include "Constants.h"
#include <Windows.h>
#include <conio.h>
#include <sstream>


std::string type_info(const char* val){

    switch (*val){
        case 'i': return "integer";
        case 'y': return "integer";
        case 'd': return "double";
        case 'f': return "float";
        case 's': return "string";
        default: return "Unknown type. Try to change type_info().";
    }
}


void InputParser::inputClear(std::istream &input) {
    input.clear();
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                InputParser::inputClear(input);
                std::cout << "MAX value: " << max << ", MIN value: " << min << std::endl;
            }
        }
        else{
            InputParser::inputClear(input);
            std::cout << "Incompatible types. Expected type - " <<  type_info(typeid(T).name()) << ". Try to enter correct value." << std::endl;
        }
    }
}


std::string readString(const std::string& show_message, size_t max, size_t min, std::istream &input) {
    std::string value_from_input;
    while (true) {
        std::cout << show_message;

        do{
            getline(input, value_from_input);
        }
        while (value_from_input.empty());

        value_from_input.shrink_to_fit();

        if (input.good()) {

            if (value_from_input.length() <= max && value_from_input.length() >= min) {
                return value_from_input;
            } else {
                InputParser::inputClear(input);
                std::cout << "MAX value: " << max << ", MIN value: " << min << std::endl;
            }
        }
    }
}

void InputParser::listener() {
   std::cout << "Press ENTER to start"<<std::endl;
   while(true){
       if (kbhit()) {
           inputClear(std::cin);
           std::cout << HEADER << std::endl;
           break;
       }
   }
}


std::istream &operator>>(std::istream &input, InputParser &parser) {
//    parser.listener();
    parser.width = readValue<size_t>("Enter width:", MAX_SCORE_CARD_WIDTH, MIN_SCORE_CARD_WIDTH, input);
    parser.height = readValue<size_t>("Enter height:", MAX_SCORE_CARD_HEIGHT, MIN_SCORE_CARD_HEIGHT, input);
    parser.fullness = readValue<float>("Enter fullness:", MAX_SCORE_CARD_FULLNESS, MIN_SCORE_CARD_FULLNESS, input);
    parser.numberOfPlayers = readValue<size_t>("Enter number of players:", MAX_CELL_NUMBER/(parser.width * parser.height), MIN_NUMBER_OF_PLAYERS, input);

    for(size_t num = 1; num <= parser.numberOfPlayers; num++){
        std::stringstream ss;
        ss << "Player N" << num << " name:";
        std::string res = ss.str();
        parser.identifiers.push_back(readString(res, MAX_IDENTIFIER_LENGTH, MIN_IDENTIFIER_LENGTH, input));
    }

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

size_t InputParser::getNumberOfPlayers() const {
    return numberOfPlayers;
}

const std::vector<std::string> &InputParser::getIdentifiers() const {
    return identifiers;
}

void InputParser::parseTurn(std::string& id) const {
    char ch;

    while(true) {

        std::cout << "Player " << id  <<", type r for make turn or q for quit:";
        std::cin >> ch;
        std::cin.clear();
        fflush(stdin);

        if(std::cin.good()) {

            if(ch == CHAR_TO_QUIT) {
                std::cout << "quit" << std::endl;
                return;
            }
            if(ch == CHAR_TO_CONTINUE) {
                return;
            }
            else {
                std::cout << "Invalid input, try again..." << std::endl;
            }
        }
    }
}


//TODO user mozher vvesti probely -- vyrezat ich.
//TODO proverka resov - prinitm carti i vudaem pobeditelya.







