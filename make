#!/bin/bash
cd "$(dirname "$0")"

if [ ! -d "lib" ]; then
  mkdir lib
fi
if [ ! -d "obj" ]; then
  mkdir obj
else
  rm obj/*
fi

COMPILER="g++ -std=c++11 -DUSE_REAL_VALUES"

$COMPILER -c src/initializators/RandomInitializator.cpp -o obj/RandomInitializator.o
$COMPILER -c src/initializators/SeedInitializator.cpp -o obj/SeedInitializator.o

$COMPILER -c src/fitness/FitnessCalculator.cpp -o obj/FitnessCalculator.o

$COMPILER -c src/selectors/RouletteWheelSelection.cpp -o obj/RouletteWheelSelection.o

$COMPILER -c src/crossovers/BitsOnePointCrossover.cpp -o obj/BitsOnePointCrossover.o
$COMPILER -c src/crossovers/RealValCrossover.cpp -o obj/RealValCrossover.o
$COMPILER -c src/crossovers/ValueOnePointCrossover.cpp -o obj/ValueOnePointCrossover.o

$COMPILER -c src/mutators/BitProbabilityMutation.cpp -o obj/BitProbabilityMutation.o
$COMPILER -c src/mutators/RealValueAbsAmountMutation.cpp -o obj/RealValueAbsAmountMutation.o
$COMPILER -c src/mutators/RealValuePercentageMutation.cpp -o obj/RealValuePercentageMutation.o

$COMPILER -c src/mergers/ProportionMerge.cpp -o obj/ProportionMerge.o

$COMPILER -c src/utils/Randomizer.cpp -o obj/Randomizer.o
$COMPILER -c src/utils/BinaryConverter.cpp -o obj/BinaryConverter.o

ar rcs lib/libGA.a obj/*
