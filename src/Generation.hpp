#ifndef GENERATION
#define GENERATION

#include <algorithm>
#include "config.hpp"
#include "Individual.hpp"

using namespace std;

namespace GA {
	extern bool searchForMaximum;

	class Generation {
		private:
			Individuals individuals;
		public:
			Generation() : Generation(0,0) {}
			Generation(int generationSize, int chromosomeSize)  {
				DEBUG("Generation: Constructor by parameters == Start");
				// Reserve enough space in vector to prevent unnecessary
				// vector resizes
				individuals.reserve(generationSize);
				// Make one individual
				Individual individual(chromosomeSize);
				// Now add this individual to the vector n times
				// as vector is making a copy of an object on push_back
				// this should be ok to do
				for(int i = 0; i < generationSize; i++) {
					individuals.push_back(individual);
				}
				DEBUG("Generation: Constructor by parameters == Done");
			}

			Generation(const Generation& generation) : individuals(generation.getIndividuals()) {
				DEBUG("Generation: Copy constructor");
			}

			int size() const {
				return individuals.size();
			}

			void addKids(const Generation& g) {
				for (int i = 0; i < g.getIndividuals().size(); i++)
					individuals.push_back(g.getIndividuals()[i]);
			}

			void clear() {
				individuals.clear();
			}
			const Individual& operator[](int i) const {
				return individuals[i];
			}
			Individual* operator[](int i) {
				return &individuals[i];
			}
			const Individuals& getIndividuals() const { return individuals; }
			Individuals* getIndividuals() { return &individuals; }

			void sortIndividualsByFitness() {
				sort(individuals.begin(), individuals.end());
			}

			const Individual& getBestIndividual() const {
				int individualIndex = 0;
				for (int i = 1; i < individuals.size(); i++) {
					if (individuals[individualIndex] < individuals[i]) {
						individualIndex = i;
					}
				}
				return individuals[individualIndex];
			}

			string to_string2() const {
				string out;
				out.reserve(individuals.size() * individuals[0].getChromosome().size() * 10);
				for (int i = 0; i < individuals.size(); i++) {
					out += individuals[i].to_string2() + "\n";
				}
				return out;
			}
	};

	typedef Generation Parents;
}
#endif