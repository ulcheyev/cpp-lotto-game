//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_INPUTPARSER_H
#define UNTITLED_INPUTPARSER_H


#include <istream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "OutputMaker.h"
#include "Constants.h"

/**
 * Class represents manager to work with input.
 */
class InputParser {
public:

    /**
     * Parses card data: width. height, size of win sequence and number of players.
     */
    void parseCardData();

    /**
     * Clears input.
     * @param input input to clear
     */
    static void inputClear(std::istream &input);

    /**
     * Parses input yes/no.
     * @return true if yes, otherwise false
     */
    bool parseInput();

    /**
     * Parses turn to fill numbers in card.
     * @param card card, which will be filled
     * @return values from input
     */
    std::vector<size_t> parseTurn(std::unique_ptr<ScoreCard>& card,  std::string&) ;

    /**
     * Read  value and validate it by comparing with max, min.
     * @tparam T type of  value
     * @param show_message message to show
     * @param max max value
     * @param min min value
     * @param input input
     * @return validated value from input
     */
    template  <typename T> static  T readValue(const std::string& show_message, T max, T min, std::istream &input);

    /**
     * Read  string and validate it by comparing with max, min.
     * @param show_message message to show
     * @param max max value
     * @param min min value
     * @param input nput
     * @return validated value from input
     */
    std::string static readString(const std::string& show_message, size_t max, size_t min, std::istream &input);

    /**
     * Read specified string and validate it.
     * @tparam Ts type of specified expected strings
     * @param msg message to show
     * @param ts specified expected strings
     * @return validated string from input, which equals to value from varargs
     */
    template<typename... Ts>
    std::string  readSpecifiedString(const std::string& msg, Ts const&... ts){
        std::string res;
        while(true){
            const std::string &string = readString(msg, 0, 0, std::cin);
            for(auto arg: {ts...}){
                if(string.compare(arg) == 0){
                    res = arg;
                    return res;
                }
            }
            printError("Invalid input, try again. ");
        }
    }

    void listener() ;


    /*
     * Getters and setters.
     */
    size_t getWidth() const;
    size_t getHeight() const;
    bool isContinue() const;
    void setContinue(bool cont);
    size_t getSizeOfWinSequence() const;
    size_t getNumberOfPlayers() const;
    const std::vector<std::string>& getIdentifiers() const;


private:
    size_t width;
    size_t height;
    size_t sizeOfWinSequence;
    size_t numberOfPlayers;

    bool _continue = false;
    std::vector<std::string> identifiers;
};

#endif //UNTITLED_INPUTPARSER_H
