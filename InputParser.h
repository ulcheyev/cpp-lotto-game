//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_INPUTPARSER_H
#define UNTITLED_INPUTPARSER_H


#include <istream>
#include <vector>

class InputParser {
public:

    friend std::istream &operator>>( std::istream  &input, InputParser & parser );
    static void inputClear(std::istream &input);
    size_t getWidth() const;
    size_t getHeight() const;
    float getFullness() const;
    size_t getNumberOfPlayers() const;
    void parseTurn(std::string&) const;
    void listener() ;

    const std::vector<std::string> &getIdentifiers() const;

private:
    size_t width;
    size_t height;
    float fullness;
    size_t numberOfPlayers;
    std::vector<std::string> identifiers;
};

#endif //UNTITLED_INPUTPARSER_H
