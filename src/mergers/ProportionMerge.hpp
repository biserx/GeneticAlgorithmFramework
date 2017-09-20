#include "MergeBlock.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>

namespace GA {
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
}
