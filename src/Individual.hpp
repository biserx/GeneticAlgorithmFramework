#ifndef INDIVIDUAL
#define INDIVIDUAL

#include "config.hpp"
#include "Chromosome.hpp"
#include <vector>

using namespace std;

namespace GA {
	extern bool searchForMaximum;

	class Individual {
		private:
			Chromosome chromosome;
			double fitness;
		public:
			Individual() : chromosome() {
				DEBUG("\tIndividual: Default constructor");
			}
			Individual(const Individual& another) : chromosome(another.getChromosome()), fitness(another.getFitness()) {
	    		DEBUG("\tIndividual: Copy constructor");
			}
			Individual(const Chromosome& c) : chromosome(c) {
				DEBUG("\tIndividual: Constructor by chromosome");
			}
			Individual(int chromosomeSize) : chromosome(chromosomeSize) {
				DEBUG("\tIndividual: Constructor by chromosome size");
			}

			inline bool operator<(const Individual& in) const {
				if (searchForMaximum)
					return fitness < in.getFitness();
				else
					return fitness > in.getFitness();
			}

			inline bool operator==(const Individual& in) {
				return chromosome == in.getChromosome();
			}

			void setFitness(GENOTYPE_TYPE newFitness) { fitness = newFitness; }
			GENOTYPE_TYPE getFitness() const { return fitness; }

			const Chromosome& getChromosome() const { return chromosome; }
			Chromosome* getChromosome() { return &chromosome; }

			string to_string2() const {
				string out = chromosome.to_string2();
				out = "(" + out + ") : " + to_string(fitness);
				return out;
			}
	};

	typedef vector<Individual> Individuals;
}
#endif
