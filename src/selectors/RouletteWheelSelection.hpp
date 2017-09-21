#include "SelectionBlock.hpp"
#include <vector>

namespace GA {
	class RouletteWheelSelection : public SelectionBlock
	{
		private:
			double total_fitness;

			struct ExtendedIndividual : public Individual {
				double normalized_fitness;
				ExtendedIndividual(const Individual& individual, double normalized_fitness) : Individual(individual), normalized_fitness(normalized_fitness) {	}
				bool operator<(const ExtendedIndividual& ss) const {
		        	return normalized_fitness < ss.normalized_fitness;
		    	}
			};
			vector<ExtendedIndividual> lGeneration;

		public:
			RouletteWheelSelection();

			void add_candidates(const Generation&);
			void get_selected(Generation*, int);
			void reset();
	};
}