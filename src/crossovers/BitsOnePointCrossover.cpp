#include "BitsOnePointCrossover.hpp"
#include "GenericPointCrossover.hpp"
#include "../utils/Randomizer.hpp"
#include "../utils/BinaryConverter.hpp"
#include <vector>
#include <cassert>

namespace GA {
	BitsOnePointCrossover::BitsOnePointCrossover(double min, double max) : crossover_point_min(min), crossover_point_max(max) {}

	void BitsOnePointCrossover::crossover(Parents *parents) {
		assert(parents->size() == 2);

		Bits vals1, vals2;
		BinaryConverter::getBits(*(*parents)[0]->getChromosome(), &vals1);
		BinaryConverter::getBits(*(*parents)[1]->getChromosome(), &vals2);

		genericPointCrossover<bool>(&vals1, &vals2, 1, crossover_point_min, crossover_point_max);

		BinaryConverter::setBits(vals1, (*parents)[0]->getChromosome());
		BinaryConverter::setBits(vals2, (*parents)[1]->getChromosome());
	}
}