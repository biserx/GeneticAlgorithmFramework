#ifndef RANDOMIZER
#define RANDOMIZER

#include "../Chromosome.hpp"

using namespace GA;

class Randomizer {
	public:
		static void randomizeValues(ChromosomeValues*, GENOTYPE_TYPE, GENOTYPE_TYPE);
		static double getRandomValue(double, double);
};

#endif
