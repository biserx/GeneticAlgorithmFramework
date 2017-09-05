#ifndef GA_MUTATION_BLOCK
#define GA_MUTATION_BLOCK

#include "../common.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"

class MutationBlock
{
	public:
		virtual void mutate(Individual*) = 0;
};

#endif