#include "CrossoverBlock.hpp"

namespace GA {
	class BitsOnePointCrossover : public CrossoverBlock
	{
		private:
			double crossover_point_min;
			double crossover_point_max;
		public:
			BitsOnePointCrossover(double, double);
			void crossover(Parents*);
	};
}