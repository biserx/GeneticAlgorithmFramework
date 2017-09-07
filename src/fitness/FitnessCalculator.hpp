#include "FitnessBlock.hpp"

namespace GA {
	class FitnessCalculator : public FitnessBlock
	{
		private:
			double (*foo)(ChromosomeValues*);
		public:
			FitnessCalculator(double (*foo)(ChromosomeValues*));
			void calc(Generation *generation);
	};
}