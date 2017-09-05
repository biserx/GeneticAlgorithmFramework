#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>

#include "common.hpp"
#include "Chromosome.hpp"
#include "Individual.hpp"
#include "Generation.hpp"

#include "initializators/RandomInitializator.hpp"
#include "initializators/SeedInitializator.hpp"

#include "selectors/RouletteWheelSelection.hpp"

// #include "crossovers/BitMultiPointCrossover.hpp"
// #include "crossovers/BitOnePointCrossover.hpp"
// #include "crossovers/BitUniformCrossover.hpp"
// #include "crossovers/RealValCrossover.hpp"
#include "crossovers/ValueOnePointCrossover.hpp"
// #include "crossovers/ValueUniformCrossover.hpp"

// #include "mutators/BitProbabilityMutation.hpp"
// #include "mutators/NormalDistributionMutation.hpp"
#include "mutators/RealValueAbsAmountMutation.hpp"
#include "mutators/RealValueProbabilityMutation.hpp"

#include "mergers/ProportionMerge.hpp"

#include "fitness/FitnessCalculator.hpp"

using namespace std;

class GeneticAlgorithm
{
	public:
		GeneticAlgorithm() {
			auto now = std::chrono::system_clock::now();
		    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

		    auto value = now_ms.time_since_epoch();
		    long duration = value.count();

			srand(duration);
		};
};

#endif