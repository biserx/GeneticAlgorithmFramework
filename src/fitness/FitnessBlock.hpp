#ifndef GA_FITNESS_BLOCK
#define GA_FITNESS_BLOCK

#include "../common.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

class FitnessBlock
{
	public:
		virtual void calc(Generation *generation) = 0;
};

#endif
