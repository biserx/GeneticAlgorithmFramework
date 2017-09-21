#include "ValueOnePointCrossover.hpp"
#include "GenericPointCrossover.hpp"
#include "../utils/Randomizer.hpp"
#include <vector>
#include <cassert>

namespace GA {
	ValueOnePointCrossover::ValueOnePointCrossover(double min, double max) : crossover_point_min(min), crossover_point_max(max) {}

	void ValueOnePointCrossover::crossover(Parents *parents) {
		assert(parents->size() == 2);

		vector<GENOTYPE_TYPE> *vals1 = (*parents)[0]->getChromosome()->getValues();
		vector<GENOTYPE_TYPE> *vals2 = (*parents)[1]->getChromosome()->getValues();
		genericPointCrossover<GENOTYPE_TYPE>(vals1, vals2, 1, crossover_point_min, crossover_point_max);
	}
}
