#!/bin/bash
cd "$(dirname "$0")"

rm obj/*
g++ -c src/initializators/RandomInitializator.cpp  -std=c++11 -o obj/RandomInitializator.o
g++ -c src/initializators/SeedInitializator.cpp  -std=c++11 -o obj/SeedInitializator.o

g++ -c src/fitness/FitnessCalculator.cpp  -std=c++11 -o obj/FitnessCalculator.o

g++ -c src/selectors/RouletteWheelSelection.cpp  -std=c++11 -o obj/RouletteWheelSelection.o

g++ -c src/crossovers/ValueOnePointCrossover.cpp  -std=c++11 -o obj/ValueOnePointCrossover.o

g++ -c src/mutators/RealValueAbsAmountMutation.cpp  -std=c++11 -o obj/RealValueAbsAmountMutation.o

g++ -c src/mergers/ProportionMerge.cpp  -std=c++11 -o obj/ProportionMerge.o



ar rcs lib/libGA.a obj/*
