#include <vector>
#include "MutationBlock.hpp"

namespace GA {
	class RealValuePercentageMutation : public MutationBlock
	{
		private:
			double probability;
			double percentage;
		public:
			RealValuePercentageMutation(double, double);
			void mutate(Individual*);
			void setMutationParameters(double, double);
	};
}