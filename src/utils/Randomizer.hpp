#ifndef RANDOMIZER
#define RANDOMIZER

#include <cstdlib>
#include <cassert>

#include "../common.hpp"
#include "../Chromosome.hpp"

void randomizeValues(ChromosomeValues *v, GENOTYPE_TYPE init_center, GENOTYPE_TYPE init_radius) {
	assert(v != NULL);
	for (int i = 0; i < v->size(); i++) {
		// TODO: if int, may not initialize correctly
		(*v)[i] = (GENOTYPE_TYPE) (rand() % ((int)(2 * init_radius * PRECISION)) * 1.0 / PRECISION - init_radius + init_center);
	}

}

#endif