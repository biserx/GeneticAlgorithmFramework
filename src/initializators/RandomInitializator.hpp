#include "InitializationBlock.hpp"

namespace GA {
	class RandomInitializator : public InitializationBlock
	{
		private:
			GENOTYPE_TYPE init_center;
			GENOTYPE_TYPE init_radius;
		public:
			RandomInitializator(GENOTYPE_TYPE init_center, GENOTYPE_TYPE init_diameter);
			void init(Generation *generation);
	};
}
