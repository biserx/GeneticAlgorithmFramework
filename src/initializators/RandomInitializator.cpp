#include <cassert>
#include "RandomInitializator.hpp"
#include "../utils/Randomizer.hpp"

namespace GA {
	RandomInitializator::RandomInitializator(GENOTYPE_TYPE init_center, GENOTYPE_TYPE init_diameter) :
		init_center(init_center),
		init_radius(init_diameter/2) {};

	void RandomInitializator::init(Generation *generation) {
		assert(generation != NULL);
		Individuals *individuals = generation->getIndividuals();
		for (int i = 0; i < individuals->size(); i++) {
			randomizeValues((*individuals)[i].getChromosome()->getValues(), init_center, init_radius);
		}
	}
}