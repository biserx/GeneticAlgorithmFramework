#include "RealValuePercentageMutation.hpp"
#include "../utils/Randomizer.hpp"
#include <cassert>

namespace GA {
	RealValuePercentageMutation::RealValuePercentageMutation(double probability, double percentage) : probability(probability), percentage(percentage) {}

	void RealValuePercentageMutation::mutate(Individual *in) {
		vector<GENOTYPE_TYPE> *values = in->getChromosome()->getValues();
		for (int i = 0; i < values->size(); i++) {
			if (Randomizer::getRandomValue(0, 1) < probability) {
				(*values)[i] += (GENOTYPE_TYPE) ((*values)[i] * Randomizer::getRandomValue(-1, 1) * percentage);
			}
		}
	}

	void RealValuePercentageMutation::setMutationParameters(double probability, double percentage) {
		assert(probability <= 1);
		this->probability = probability;
		this->percentage = percentage;
	}
}
