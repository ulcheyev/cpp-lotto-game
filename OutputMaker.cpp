//
// Created by Ulchenkov Yevgeniy on 07.01.2023.
//

#include "OutputMaker.h"
#include <iostream>
#include <iomanip>
#include "Constants.h"
#include "ScoreCard.h"

using namespace std;

void set_raw(bool set) {
    if (set) {
        system("stty raw");
        system("stty -raw");
    }
}

void printLogo() {
   printOne(COLOR_CYAN, MY_LOGO);
}

void printLine() {
    std::stringstream  ss;
    ss << COLOR_LINE;
    for(int i = 0; i < CHARS_IN_LINE; i++){
        ss << "=";
    }
    cout << ss.str() << ANSI_COLOR_RESET << endl;
}

void printError(const std::string& error){
    printOne(ERROR_COLOR, error);
}



void printArgs() {
    cout  << endl <<  ANSI_COLOR_RESET;
}

void resetConsole(){
    cout <<  ANSI_CLEAR << ANSI_COLOR_RESET;
}

void printCard(std::unique_ptr<ScoreCard>& card){
    printOne(*card);
}











