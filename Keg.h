//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_KEG_H
#define UNTITLED_KEG_H

class Keg {
public:
    Keg() = default;
    Keg(char value);
    char getValue() const;
    void setValue(char value);
private:
    char kegValue;
};


#endif //UNTITLED_KEG_H
