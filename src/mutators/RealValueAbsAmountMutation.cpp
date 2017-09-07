#include <cassert>
#include "RealValueAbsAmountMutation.hpp"

namespace GA {
	RealValueAbsAmountMutation::RealValueAbsAmountMutation(double probability, double amount) : probability(probability), amount(amount) {}

	void RealValueAbsAmountMutation::mutate(Individual *in) {
		vector<GENOTYPE_TYPE> *values = in->getChromosome()->getValues();
		for (int i = 0; i < values->size(); i++) {
			if (rand() % PRECISION * 1.0 / PRECISION < probability) {
				(*values)[i] += (GENOTYPE_TYPE) ((rand() % PRECISION) * 2.0 / PRECISION - 1) * amount;
			}
		}
	}

	void RealValueAbsAmountMutation::setMutationParameters(double probability, double amount) {
		assert(probability <= 1);
		this->probability = probability;
		this->amount = amount;
	}
}