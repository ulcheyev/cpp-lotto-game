//
// Created by Ulchenkov Yevgeniy on 07.01.2023.
//

#ifndef UNTITLED_OUTPUTMAKER_H
#define UNTITLED_OUTPUTMAKER_H

#include <ostream>
#include <iostream>
#include "ScoreCard.h"
#include "Constants.h"


void resetConsole();

void set_raw(bool set);

/**
* Prevents recursion call
*/
void printArgs();

/**
 * Prints specified  card
 * @param card specified  card
 */
void printCard(std::unique_ptr<ScoreCard>& card);

/**
 * Function, that prints all varargs
 * @tparam T typename
 * @tparam Types typename...
 * @param var1 varargs
 * @param var2 varargs
 */
template<typename T, typename... Types>
void  printArgs(T var1, Types... var2) {
    std::cout << var1;
    printArgs(var2...);
}

/**
 *
 * Function, that prints all varargs
 * @tparam T typename
 * @tparam Types typename...
 * @param color color
 * @param var1 varargs
 * @param var2 varargs
 */
template<typename T, typename... Types>
void  printArgs(const std::string& color,  T var1, Types... var2) {
    std::cout << color  << var1;
    printArgs(var2...);
}

/**
 * Prints the dividing line
 */
void printLine();


/**
 * Print specified object
 * @tparam T type of object to print
 * @param var1 specified object
 */
template<typename T>
void  printOne(T var1){
    std::cout << var1;
}

/**
 * Print specified object with color
 * @tparam T type of object to print
 * @param color color
 * @param var1 specified object
 */
template<typename T>
void  printOne(const std::string& color, T var1){
    std::cout << color << var1 << ANSI_CLEAR << ANSI_COLOR_RESET;
}

/**
 * Prints logo
 */
void printLogo();

/**
 * Prints with error color
 * @param error error msg to print
 */
void printError(const std::string& error);

#endif //UNTITLED_OUTPUTMAKER_H
