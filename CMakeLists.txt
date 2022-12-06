cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Keg.cpp Keg.h Cell.cpp Cell.h Lotto.cpp Lotto.h ScoreCard.cpp ScoreCard.h BoxWithKegs.cpp BoxWithKegs.h InputParser.cpp InputParser.h LottoRandomizer.cpp LottoRandomizer.h)
