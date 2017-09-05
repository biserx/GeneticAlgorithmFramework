#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>

#include "MergeBlock.hpp"

class ProportionMerge : public MergeBlock
{
private:
	double proportion;
	Generation *g1 = NULL, *g2 = NULL;
public:
	ProportionMerge(double);
	~ProportionMerge();

	void merge(const Generation&, const Generation&, Generation*, int);
};