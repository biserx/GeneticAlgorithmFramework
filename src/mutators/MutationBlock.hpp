#ifndef GA_MUTATION_BLOCK
#define GA_MUTATION_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"

namespace GA {
	class MutationBlock
	{
		public:
			virtual void mutate(Individual*) = 0;
	};
}
#endif