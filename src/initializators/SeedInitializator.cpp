#include <cassert>
#include "SeedInitializator.hpp"
#include "../utils/Randomizer.hpp"

SeedInitializator::SeedInitializator(ChromosomeValues init_seed, GENOTYPE_TYPE init_diameter) :
	init_seed(init_seed),
	init_radius(init_diameter/2) {
		chromosome_size = init_seed.size();
};

void SeedInitializator::init(Generation *generation) {
	assert(generation != NULL);
	Individuals *individuals = generation->getIndividuals();
	assert(chromosome_size == ((*individuals)[0].getChromosome()->getValues())->size());

	for (int i = 0; i < individuals->size(); i++) {
		randomizeValues((*individuals)[i].getChromosome()->getValues(), 0, init_radius);
		for (int j = 0; j < chromosome_size; j++) {
			(*((*individuals)[i].getChromosome()->getValues()))[j] += init_seed[j];
		}
	}
}