//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "Keg.h"

Keg::Keg(char value) :kegValue(value) {}

char Keg::getValue() const {
    return kegValue;
}

void Keg::setValue(char value) {
    kegValue = value;
}
