#include "config.hpp"
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
#include "mutators/RealValuePercentageMutation.hpp"

#include "mergers/ProportionMerge.hpp"

#include "fitness/FitnessCalculator.hpp"

#include "GeneticAlgorithm.hpp"

