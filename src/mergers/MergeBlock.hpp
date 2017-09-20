#ifndef GA_MERGE_BLOCK
#define GA_MERGE_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

namespace GA {
	class MergeBlock
	{
		public:
			virtual void merge(const Generation&, const Generation&, Generation*, int) = 0;
	};
}
#endif
