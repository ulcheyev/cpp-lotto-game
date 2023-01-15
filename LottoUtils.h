//
// Created by Ulchenkov Yevgeniy on 05.12.2022.
//

#ifndef UNTITLED_LOTTOUTILS_H
#define UNTITLED_LOTTOUTILS_H


#include <cstdlib>
#include <random>
#include  <iterator>
#include <algorithm>
#include <set>
#include "ScoreCard.h"
#include "Constants.h"


/**
 * Class contains the necessary tools to maintain the moves of the game.
 */
class LottoUtils {
public:

    LottoUtils() = default;
    /**
     * Generates number for cell in score card.
     * @return generated random number
     */
    static size_t generateNumberForCell();

    /**
     * Generates score card with random numbers.
     * @param width card width
     * @param height card height
     * @return generates score card
     */
    static std::unique_ptr<ScoreCard>  generateScoreCardWithRandomNumbers(size_t width, size_t height);

    /**
     * Converts vector values to string separated by whitespace
     * @return converted vector
     */
    static std::string vecToString(std::vector<size_t>&);

    /**
     * Checks, if vector has duplicate values
     * @tparam Iter type of iterator
     * @param start start of vector
     * @param end end of vector
     * @return true, if vector has duplicates
     */
    template<typename Iter>
    static bool checkHasDuplicates(Iter start, Iter end) {
        std::sort(start, end);
        auto it = std::unique(start, end);
        bool wasUnique = (it == end);
        return !wasUnique;
    }

    /**
     * Select random element from specified start and end of the container.
     * @tparam Iter type of iterator
     * @param start start of container
     * @param end end of container
     * @return randomly selected element from container
     */
    template<typename Iter>
    Iter static select_randomly(Iter start, Iter end) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }

    /**
     * Check, if specified vector contains specified element
     * @tparam type type of vector
     * @param v specified vector
     * @param val specified element
     * @return true, if specified vector contains specified element
     */
    template<typename type>
    static bool checkContainingElement(std::vector<type>& v, type val) {
        if(std::find(v.begin(),  v.end(), val) != v.end()){
            return true;
        };
        return false;
    }

    /**
     * Counts digits in specified number
     * @param number
     * @return digits count in specified number
     */
    static size_t findDigitsCount(int number);

    /**
    * Controls, if specified vector with number presents in score card.
    * @param vector1 specified vecor with numbers
    * @return true, if all numbers are in score card
    */
    static bool checkNumbersPresentInCard(std::vector<size_t> vector1);

private:

    template<typename Iter, typename RandomGenerator>
    Iter static select_randomly(Iter start, Iter end, RandomGenerator& g) {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
        std::advance(start, dis(g));
        return start;
    }
    static std::vector<size_t> cellsNumbers;
    static std::random_device seed;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dist;

};


#endif //UNTITLED_LOTTOUTILS_H
