#ifndef GA_INIT_BLOCK
#define GA_INIT_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

namespace GA {
	class InitializationBlock
	{
		public:
			virtual void init(Generation*) = 0;
	};
}

#endif
