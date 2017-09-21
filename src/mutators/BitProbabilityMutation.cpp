#include "BitProbabilityMutation.hpp"
#include "../utils/Randomizer.hpp"
#include "../config.hpp"
#include <vector>
#include <cassert>

namespace GA {
	BitProbabilityMutation::BitProbabilityMutation(double probability) : probability(probability) {}
	void BitProbabilityMutation::mutate(Individual *in) {
		#ifdef USE_REAL_VALUES
			assert(!"Bit probability cant be used with real values.");
		#else
			vector<GENOTYPE_TYPE> *vals = in->getChromosome()->getValues();
			for (int i = 0; i < vals->size(); i++) {
				if (Randomizer::getRandomValue(0,1) < probability) {
					(*vals)[i] = (*vals)[i] xor 0x1;
				}
			}
		#endif
	}
}
