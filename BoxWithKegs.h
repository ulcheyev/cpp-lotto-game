//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_BOXWITHKEGS_H
#define UNTITLED_BOXWITHKEGS_H


#include <vector>
#include <memory>

class BoxWithKegs {
public:
    BoxWithKegs();
    void generateBox();
    size_t randomKeg();
    bool isEmpty();
private:
    std::vector<size_t> kegs;
};


#endif //UNTITLED_BOXWITHKEGS_H
