#ifndef GA_CROSSOVER_BLOCK
#define GA_CROSSOVER_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

namespace GA {
	class CrossoverBlock
	{
		public:
			virtual void crossover(Parents*) = 0;
	};
}
#endif
