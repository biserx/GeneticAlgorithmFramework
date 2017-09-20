#include "ValueOnePointCrossover.hpp"
#include "../utils/Randomizer.hpp"

namespace GA {
	ValueOnePointCrossover::ValueOnePointCrossover(double min, double max) : crossover_point_min(min), crossover_point_max(max) {}

	void ValueOnePointCrossover::crossover(Parents *parents) {
		assert(parents->size() == 2);

		vector<GENOTYPE_TYPE> *vals1 = (*parents)[0]->getChromosome()->getValues();
		vector<GENOTYPE_TYPE> *vals2 = (*parents)[1]->getChromosome()->getValues();
		double rnd = Randomizer::getRandomValue(0, 1); // [0 - 1) //
		int point = (int) ((crossover_point_min + (rnd * (crossover_point_max - crossover_point_min))) * vals1->size());
		assert(point >= 0 && point < vals1->size());

		if (point == 0) point = 1;
		if (point == vals1->size()) point = vals1->size() - 1;

		// Swap values between untill the point
		for (int i = 0; i < point; i++) {
			double val = (*vals1)[i];
			(*vals1)[i] = (*vals2)[i];
			(*vals2)[i] = val;
		}

	}
}
