#include "../config.hpp"
#include "../Chromosome.hpp"

using namespace GA;

typedef vector<bool> Bits;

class BinaryConverter
{
	public:
		static void getBits(const Chromosome&, Bits*);
		static void setBits(const Bits&, Chromosome*);
};

