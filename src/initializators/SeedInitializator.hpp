#include "InitializationBlock.hpp"


class SeedInitializator : public InitializationBlock
{
	private:
		int chromosome_size;
		ChromosomeValues init_seed;
		GENOTYPE_TYPE init_radius;
	public:
		SeedInitializator(ChromosomeValues init_seed, GENOTYPE_TYPE init_diameter);
		void init(Generation *generation);
};