#ifndef GA_SELECTION_BLOCK
#define GA_SELECTION_BLOCK

#include "../common.hpp"
#include "../Chromosome.hpp"
#include "../Individual.hpp"
#include "../Generation.hpp"

class SelectionBlock
{
	public:
		virtual void add_candidates(const Generation&) = 0;
		virtual void get_selected(Generation*, int) = 0;
		virtual void reset() = 0;
};

#endif