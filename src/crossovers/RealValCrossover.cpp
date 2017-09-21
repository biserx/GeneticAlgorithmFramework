#include "RealValCrossover.hpp"
#include "../utils/Randomizer.hpp"
#include <vector>
#include <cassert>

namespace GA {
	RealValCrossover::RealValCrossover(double alpha) : a(alpha) {
		#ifndef USE_REAL_VALUES
			assert(!"RealValCrossover cant be used with non real values.");
		#endif
		assert(a > 0);
	}

	void RealValCrossover::crossover(Parents *parents) {
		#ifdef USE_REAL_VALUES
			assert(parents->size() == 2);

			vector<double> *vals1 = (*parents)[0]->getChromosome()->getValues();
			vector<double> *vals2 = (*parents)[1]->getChromosome()->getValues();
			assert(vals1->size() >= 1);
			assert(vals1->size() == vals2->size());

			for (int i = 0; i < vals1->size(); i++) {
				double tmp_a = Randomizer::getRandomValue(-a, 1 + a);

				GENOTYPE_TYPE x = (*vals1)[i];
				GENOTYPE_TYPE y = (*vals2)[i];
				GENOTYPE_TYPE z1 = x * tmp_a + y * (1 - tmp_a);
				GENOTYPE_TYPE z2 = x * (1 - tmp_a) + y * tmp_a;
				(*vals1)[i] = z1;
				(*vals2)[i] = z2;
			}
		#endif
	}
}
