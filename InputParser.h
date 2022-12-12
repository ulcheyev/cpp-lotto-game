//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_INPUTPARSER_H
#define UNTITLED_INPUTPARSER_H


#include <istream>

class InputParser {
public:
    friend std::istream &operator>>( std::istream  &input, InputParser & parser );
    size_t getWidth() const;
    size_t getHeight() const;
    float getFullness() const;
private:
    size_t width;
    size_t height;
    float fullness;
};

#endif //UNTITLED_INPUTPARSER_H
