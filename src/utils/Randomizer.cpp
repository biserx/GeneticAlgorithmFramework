#include "Randomizer.hpp"
#include "../config.hpp"
#include <cstdlib>
#include <cassert>

using namespace GA;

void Randomizer::randomizeValues(ChromosomeValues *v, GENOTYPE_TYPE init_center, GENOTYPE_TYPE init_radius) {
	assert(v != NULL);
	double low = init_center - init_radius;
	double high = init_center + init_radius;
	for (int i = 0; i < v->size(); i++) {
		(*v)[i] = static_cast<GENOTYPE_TYPE>(getRandomValue(low, high));
	}

}
#define DECIMAL_PLACES 1000000
double Randomizer::getRandomValue(double low = 0, double high = 1) {
	double rnd = ((rand() % DECIMAL_PLACES) * 1.0 / DECIMAL_PLACES); // [0 - 1)
	return low + (high - low) * rnd;
}
