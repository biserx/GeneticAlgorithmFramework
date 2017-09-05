#include <cassert>
#include "FitnessCalculator.hpp"

FitnessCalculator::FitnessCalculator(double (*foo)(ChromosomeValues*)) {
	this->foo = foo;
}

void FitnessCalculator::calc(Generation *generation) {
	for (int i = 0; i < generation->size(); i++) {
		double f = (*foo)((*generation)[i]->getChromosome()->getValues());
		assert(f > 0);
		(*generation)[i]->setFitness(f);
	}
}
