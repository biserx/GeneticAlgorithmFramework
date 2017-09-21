#include "MergeBlock.hpp"

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
