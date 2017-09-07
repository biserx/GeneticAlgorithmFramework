#ifndef GA_FITNESS_BLOCK
#define GA_FITNESS_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

namespace GA {
	class FitnessBlock
	{
		public:
			virtual void calc(Generation*) = 0;
	};
}
#endif
