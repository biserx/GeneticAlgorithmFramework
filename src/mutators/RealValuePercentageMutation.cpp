#include <cassert>
#include "RealValuePercentageMutation.hpp"

namespace GA {
	RealValuePercentageMutation::RealValuePercentageMutation(double probability, double percentage) : probability(probability), percentage(percentage) {}

	void RealValuePercentageMutation::mutate(Individual *in) {
		vector<GENOTYPE_TYPE> *values = in->getChromosome()->getValues();
		for (int i = 0; i < values->size(); i++) {
			if (rand() % PRECISION * 1.0 / PRECISION < probability) {
				(*values)[i] += (GENOTYPE_TYPE) ((*values)[i] * ((rand() % PRECISION) * 2.0 / PRECISION - 1) * percentage);
			}
		}
	}

	void RealValuePercentageMutation::setMutationParameters(double probability, double percentage) {
		assert(probability <= 1);
		this->probability = probability;
		this->percentage = percentage;
	}
}