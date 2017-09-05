#include <cassert>
#include "RealValueProbabilityMutation.hpp"

RealValueProbabilityMutation::RealValueProbabilityMutation(double probability, double percentage) : probability(probability), percentage(percentage) {}

void RealValueProbabilityMutation::mutate(Individual *in) {
	vector<GENOTYPE_TYPE> *values = in->getChromosome()->getValues();
	for (int i = 0; i < values->size(); i++) {
		if (rand() % PRECISION * 1.0 / PRECISION < probability) {
			(*values)[i] += (GENOTYPE_TYPE) ((*values)[i] * ((rand() % PRECISION) * 2.0 / PRECISION - 1) * percentage);
		}
	}
}

void RealValueProbabilityMutation::setMutationParameters(double probability, double percentage) {
	assert(probability <= 1);
	this->probability = probability;
	this->percentage = percentage;
}
