#include "CrossoverBlock.hpp"

namespace GA {
	class RealValCrossover : public CrossoverBlock
	{
		private:
			double a;
		public:
			RealValCrossover(double);
			void crossover(Parents*);
	};
}