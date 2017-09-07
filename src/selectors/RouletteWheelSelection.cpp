#include "RouletteWheelSelection.hpp"

namespace GA {
	extern bool searchForMaximum;

	RouletteWheelSelection::RouletteWheelSelection() {}

	void RouletteWheelSelection::add_candidates(const Generation& generation) {
		total_fitness = 0;
		// Get minimum value
		double min_fitness = generation[0].getFitness();
		double max_fitness = generation[0].getFitness();
		total_fitness = generation[0].getFitness();
		for (int i = 1; i < generation.size(); i++) {
			if (min_fitness > generation[i].getFitness()) {
				min_fitness = generation[i].getFitness();
			}
			if (max_fitness < generation[i].getFitness()) {
				max_fitness = generation[i].getFitness();
			}
			total_fitness += generation[i].getFitness();
		}

		double maxToSubtract = 0;
		if (!searchForMaximum) {
			maxToSubtract = max_fitness * 2;
			total_fitness = generation.size() * maxToSubtract - total_fitness;
			max_fitness = maxToSubtract - min_fitness;
			min_fitness = maxToSubtract / 2;
		}

		lGeneration.reserve(generation.size());

		// This gives the chance to the worst individual with lowest fitness to be choosen
		// To be more precise, it will have 1/2n chance
		const double chance = 1.0 / generation.size() / 2;
		double fitness_correction = (total_fitness - 2 * generation.size() * min_fitness) / generation.size(); // (total_fitness * chance - min_fitness) / (1 - generation.size() * chance);
		total_fitness += fitness_correction * generation.size();

		for (int i = 0; i < generation.size(); i++) {
			if (!searchForMaximum) {
				lGeneration.push_back(SelectionStruct(generation[i], maxToSubtract - generation[i].getFitness() + fitness_correction));
			} else {
				lGeneration.push_back(SelectionStruct(generation[i], generation[i].getFitness() + fitness_correction));
			}
			assert(lGeneration[i].normalized_fitness >= 0);
		}

		sort(lGeneration.begin(), lGeneration.end());
	}

	void RouletteWheelSelection::get_selected(Generation* outGeneration, int count) {
		assert(outGeneration != NULL);
		while (count != 0) {
			double pocket = rand() % PRECISION * 1.0 / PRECISION;
			pocket *= total_fitness;
			double start = 0;
			bool selection_done = false;
			ChromosomeValues *choosenChromosomeValues = NULL;
			double choosenFitness = 0;
			for (int j = 0; j < lGeneration.size(); j++) {
				if (pocket >= start && pocket < start + lGeneration[j].normalized_fitness) {
					selection_done = true;
					choosenChromosomeValues = lGeneration[j].individual.getChromosome()->getValues();
					choosenFitness = lGeneration[j].individual.getFitness();
					break;
				}
				start += lGeneration[j].normalized_fitness;
			}
			if (!selection_done) {
				choosenChromosomeValues = lGeneration.back().individual.getChromosome()->getValues();
				choosenFitness = lGeneration.back().individual.getFitness();
			}
			assert(choosenChromosomeValues != NULL);
			outGeneration->getIndividuals()->push_back(Chromosome(*choosenChromosomeValues));
			outGeneration->getIndividuals()->back().setFitness(choosenFitness);
			count--;
		}

	}

	void RouletteWheelSelection::reset() {
		lGeneration.clear();
	}
}