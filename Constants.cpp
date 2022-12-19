//
// Created by Yevgeniy on 12.12.2022.
//

#include "Constants.h"

#define ANSI_CLEAR  "\x1B[2J\x1B[H"
#define ANSI_COLOR_RESET "\x1B[m"
#define COLOR_RED   "\x1B[91m"
#define COLOR_GREEN "\x1B[92m"
#define COLOR_WIN   "\x1B[48;5;52m\x1B[38;5;208m"
#define COLOR_DRAW  "\x1B[48;5;17m\x1B[38;5;75m"

size_t THE_QUANTITY_OF_CELL_CHARACTERS = 4;
size_t MAX_SCORE_CARD_HEIGHT = 4;
size_t MIN_SCORE_CARD_HEIGHT = 1;
size_t MAX_SCORE_CARD_WIDTH = 10;
size_t MIN_SCORE_CARD_WIDTH = 3;
float MAX_SCORE_CARD_FULLNESS = 1;
float MIN_SCORE_CARD_FULLNESS = 0.1;
size_t MIN_NUMBER_OF_PLAYERS = 1;
int  MIN_CELL_NUMBER = 1;
int MAX_CELL_NUMBER = 99;
size_t MAX_IDENTIFIER_LENGTH = 20;
size_t MIN_IDENTIFIER_LENGTH = 1;
char CHAR_TO_QUIT = 'q';
char CHAR_TO_CONTINUE = 'r';

std::string PLAY_HEADER = "***********\nPLAY\n***********";
std::string HEADER = "***********\nLOTTO GAME\n***********";
std::string HANDLING_CARDS = "\n++++++++++CARDS ARE HANDLING OUT++++++++++\n";

