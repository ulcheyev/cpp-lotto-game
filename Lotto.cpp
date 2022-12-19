//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#include "Lotto.h"
#include <unistd.h>
#include <iostream>
#include "Constants.h"

Lotto::Lotto() {
    identifyObjects();
}

void Lotto::identifyObjects(){
    box = std::make_unique<BoxWithKegs>();
    input = std::make_unique<InputParser>();
    utils = std::make_unique<LottoUtils>();
}

void Lotto::parseInput(std::istream  &istream) {
    InputParser *pParser = this->input.get();
    istream >> *pParser;
    identifyScoreCard();
}

void Lotto::identifyScoreCard() {
    size_t score_card_numbers = input->getNumberOfPlayers();

    for(auto idx = 0; idx < score_card_numbers; idx++){
        scoreCards.push_back(utils->generateScoreCardWithRandomNumbers(input->getIdentifiers()[idx],
                input->getWidth(), input->getHeight(), input->getFullness()
        ));
    }

}



void Lotto::print(std::ostream &out, std::string & str) {
    out << std::endl << str << std::endl;
}


void Lotto::play_game(std::ostream &out) {

    print(out, PLAY_HEADER);
    sleep(1);
    handleCards();

    while(true){
        if(box->isEmpty()){ break; isFinished = true;}
        for(auto& card: scoreCards){
            makeTurn(card);
        }
    }
}

void Lotto::makeTurn(std::unique_ptr<ScoreCard>& card) {
    std::string id = card->getIdentifier();

    std::cout << std::endl << "***Player " <<  id << " makes turn***" << std::endl;
    input->parseTurn(id);
    size_t kegNumber = box->randomKeg();

    try{
        size_t res = card->searchCell(kegNumber);
        std::cout << "***The player " << id << " was lucky***" << std::endl;
        card->fillCell(res);
        printCard(card);
    }catch(std::invalid_argument& e) {
        std::cout << "***No luck. You'll be lucky next time :)***" << std::endl;
    }

}

void Lotto::printCard(std::unique_ptr<ScoreCard>& card) {
    std::cout << *card;
}

void Lotto::handleCards() {
    std::cout << HANDLING_CARDS << std::endl;

    for(auto& card: scoreCards){
        sleep(1);
        std::cout <<"\n***" << card->getIdentifier() << "'s card****\n" << std::endl;
        printCard(card);
    }
}











