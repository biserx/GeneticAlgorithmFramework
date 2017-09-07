#ifndef RANDOMIZER
#define RANDOMIZER

#include <cstdlib>
#include <cassert>
#include "../config.hpp"
#include "../Chromosome.hpp"

using namespace GA;

void randomizeValues(ChromosomeValues *v, GENOTYPE_TYPE init_center, GENOTYPE_TYPE init_radius) {
	assert(v != NULL);
	for (int i = 0; i < v->size(); i++) {
		(*v)[i] = static_cast<GENOTYPE_TYPE>(rand() % ((int)(2 * init_radius * PRECISION)) * 1.0 / PRECISION - init_radius + init_center);
	}

}

#endif