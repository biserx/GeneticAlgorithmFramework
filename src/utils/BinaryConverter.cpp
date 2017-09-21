#include "BinaryConverter.hpp"
#include <cassert>
#include <vector>

using namespace GA;

// Quite unsafe

#define BITS_IN_CHAR 8

void BinaryConverter::getBits(const Chromosome& chromosome, Bits *bits) {
	vector<GENOTYPE_TYPE> values = chromosome.getValues();
	for (auto v : values) {
		char *c = reinterpret_cast<char*>(&v);
		int valueSizeInChars = sizeof(GENOTYPE_TYPE) / sizeof(char);
		c += valueSizeInChars - 1;
		for (int i = 0; i < valueSizeInChars; i++) {
			for (int j = 0; j < BITS_IN_CHAR; j++) {
				bool isBitSet = *c & (0x1 << (BITS_IN_CHAR - 1 - j));
				bits->push_back(isBitSet);
			}
			c--;
		}
	}
}

void BinaryConverter::setBits(const Bits& bits, Chromosome *chromosome) {
	vector<GENOTYPE_TYPE> *values = chromosome->getValues();
	int valueSizeInChars = sizeof(GENOTYPE_TYPE) / sizeof(char);
	assert(bits.size() == chromosome->size() * sizeof(GENOTYPE_TYPE) * BITS_IN_CHAR);
	for (int i = 0; i < chromosome->size(); i++) {
		GENOTYPE_TYPE *tmp = &(*chromosome->getValues())[i];
		char *c = reinterpret_cast<char*>(tmp);
		c += valueSizeInChars - 1;
		for (int j = 0; j < valueSizeInChars; j++) {
			*c = 0;
			for (int b = 0; b < BITS_IN_CHAR; b++) {
				if (bits[i * valueSizeInChars * 8 + j * 8 + b]) {
					*c |= 0x1 << (7 - b);
				}
			}
			c--;
		}
	}
}
