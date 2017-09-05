#include <vector>

#include "MutationBlock.hpp"

class RealValueProbabilityMutation : public MutationBlock
{
private:
	double probability;
	double percentage;
public:
	RealValueProbabilityMutation(double, double);
	void mutate(Individual*);
	void setMutationParameters(double, double);
};