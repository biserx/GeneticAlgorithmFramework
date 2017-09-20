#ifndef GA_SELECTION_BLOCK
#define GA_SELECTION_BLOCK

#include "../config.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

namespace GA {
	class SelectionBlock
	{
		public:
			virtual void add_candidates(const Generation&) = 0;
			virtual void get_selected(Generation*, int) = 0;
			virtual void reset() = 0;
	};
}
#endif
