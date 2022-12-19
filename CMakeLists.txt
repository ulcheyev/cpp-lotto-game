cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Cell.cpp Cell.h Lotto.cpp Lotto.h ScoreCard.cpp ScoreCard.h BoxWithKegs.cpp BoxWithKegs.h InputParser.cpp InputParser.h LottoUtils.cpp LottoUtils.h Constants.cpp Constants.h)
