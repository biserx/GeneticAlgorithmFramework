#include "RealValueAbsAmountMutation.hpp"
#include "../utils/Randomizer.hpp"
#include <cassert>

namespace GA {
	RealValueAbsAmountMutation::RealValueAbsAmountMutation(double probability, double amount) : probability(probability), amount(amount) {}

	void RealValueAbsAmountMutation::mutate(Individual *in) {
		vector<GENOTYPE_TYPE> *values = in->getChromosome()->getValues();
		for (int i = 0; i < values->size(); i++) {
			if (Randomizer::getRandomValue(0, 1) < probability) {
				(*values)[i] += (GENOTYPE_TYPE) (Randomizer::getRandomValue(-amount, amount));
			}
		}
	}

	void RealValueAbsAmountMutation::setMutationParameters(double probability, double amount) {
		assert(probability <= 1);
		this->probability = probability;
		this->amount = amount;
	}
}
