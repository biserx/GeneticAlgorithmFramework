#ifndef CHROMOSOME
#define CHROMOSOME

#include <vector>
#include "config.hpp"

using namespace std;

namespace GA {

	typedef vector<GENOTYPE_TYPE> ChromosomeValues;

	class Chromosome
	{
		private:
			ChromosomeValues values;
		public:
			Chromosome() {
				DEBUG("\tChromosome: Default constructor");
			}
			Chromosome(const Chromosome& another) : values(another.getValues()) {
	    		DEBUG("\tChromosome: Copy constructor");
			}
			Chromosome(const ChromosomeValues& vals) : values(vals) {
				DEBUG("\tChromosome: Constructor by chromosome vals");
			}
			Chromosome(int chromosomeSize) : values(chromosomeSize, 0) {
				DEBUG("\tChromosome: Constructor by chromosome size");
			}

			inline bool operator==(const Chromosome c) {
				for (int i = 0; i < values.size(); i++) {
					if (values[i] != c.getValues()[i]) {
						return false;
					}
				}
				return true;
			}

			int size() const {
				return values.size();
			}

			void setValues(const ChromosomeValues& vals) {
				values = ChromosomeValues(vals.begin(), vals.end());
			}

			const ChromosomeValues& getValues() const { return values; }
			ChromosomeValues* getValues() { return &values; }

			string to_string2() const {
				string out;
				out.reserve(values.size() * 10);
				for(int i = 0; i < values.size() - 1; i++)
					out += to_string(values[i]) + ", ";
				out += to_string(values[values.size() - 1]);
				return out;
			}
	};
}

#endif