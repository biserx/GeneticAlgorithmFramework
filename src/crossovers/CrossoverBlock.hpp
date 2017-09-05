#ifndef GA_CROSSOVER_BLOCK
#define GA_CROSSOVER_BLOCK

#include "../common.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

class CrossoverBlock
{
	public:
		virtual void crossover(Parents*) = 0;
};

#endif