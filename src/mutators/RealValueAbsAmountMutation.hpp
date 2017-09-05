#include <vector>

#include "MutationBlock.hpp"

class RealValueAbsAmountMutation : public MutationBlock
{
	private:
		double probability;
		double amount;
	public:
		RealValueAbsAmountMutation(double, double);
		void mutate(Individual*);
		void setMutationParameters(double, double);
};