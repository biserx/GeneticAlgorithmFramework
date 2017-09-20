#include "SelectionBlock.hpp"
#include <vector>
#include <cassert>

namespace GA {
	class RouletteWheelSelection : public SelectionBlock
	{
		private:
			double total_fitness;

			struct SelectionStruct {
				Individual individual;
				double normalized_fitness;
				SelectionStruct(const Individual& individual, double normalized_fitness) : individual(individual), normalized_fitness(normalized_fitness) {	}
				bool operator<(const SelectionStruct& ss) const {
		        	return normalized_fitness < ss.normalized_fitness;
		    	}
			};
			vector<SelectionStruct> lGeneration;

		public:
			RouletteWheelSelection();

			void add_candidates(const Generation&);
			void get_selected(Generation*, int);
			void reset();
	};
}
