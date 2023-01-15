//
// Created by Yevgeniy on 12.12.2022.
//

#ifndef UNTITLED_CONSTANTS_H
#define UNTITLED_CONSTANTS_H


#include <cstddef>
#include <string>

#define ANSI_CLEAR  "\x1B[2J\x1B[H"
#define ANSI_COLOR_RESET "\x1B[m"
#define COLOR_RED   "\x1B[91m"
#define COLOR_GREEN "\x1B[92m"
#define COLOR_LINE "\x1B[33m"
#define CARD_HEADER_COLOR "\x1B[96m"
#define COLOR_BLUE "\x1B[34m"
#define COLOR_CYAN "\x1B[36m"
#define ERROR_COLOR "\x1B[48;5;52m\x1B[38;5;208m"


extern std::string MY_LOGO;
extern size_t THE_QUANTITY_OF_CELL_CHARACTERS; //whitespace + 2 digits + whitespace = 4
extern size_t MAX_SCORE_CARD_HEIGHT;
extern float MAX_SCORE_CARD_FULLNESS; // 1 - 100%
extern float MIN_SCORE_CARD_FULLNESS; // 0.2 - 20%
extern size_t MIN_SCORE_CARD_WIDTH;
extern size_t MIN_SCORE_CARD_HEIGHT;
extern size_t MAX_SCORE_CARD_WIDTH;
extern size_t MIN_NUMBER_OF_PLAYERS;
extern size_t MAX_IDENTIFIER_LENGTH;
extern size_t MIN_IDENTIFIER_LENGTH;
extern int MIN_CELL_NUMBER;
extern int MAX_CELL_NUMBER;
extern std::string PLAY_HEADER;
extern char CHAR_TO_QUIT;
extern char CHAR_TO_CONTINUE;
extern  std::string HANDLING_CARDS;
extern  size_t CHARS_IN_LINE;
extern size_t W_FOR_0;
extern size_t W_FOR_NOT_0;
#endif //UNTITLED_CONSTANTS_H
