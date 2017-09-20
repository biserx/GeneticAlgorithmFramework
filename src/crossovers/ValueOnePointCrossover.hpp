#include "CrossoverBlock.hpp"
#include <vector>
#include <cassert>

namespace GA {
	class ValueOnePointCrossover : public CrossoverBlock
	{
		private:
			double crossover_point_min;
			double crossover_point_max;
		public:
			ValueOnePointCrossover(double, double);
			void crossover(Parents*);
	};
}
