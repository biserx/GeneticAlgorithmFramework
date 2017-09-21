#include "MutationBlock.hpp"

namespace GA {
	class BitProbabilityMutation : public MutationBlock
	{
		private:
			double probability;
		public:
			BitProbabilityMutation(double);
			void mutate(Individual*);
	};
}
