#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include "config.hpp"
#include "Chromosome.hpp"
#include "Individual.hpp"
#include "Generation.hpp"

using namespace std;

namespace GA {
	class GeneticAlgorithm
	{
		public:
			GeneticAlgorithm() {
				auto now = std::chrono::system_clock::now();
			    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

			    auto value = now_ms.time_since_epoch();
			    long duration = value.count();

				srand(duration);
			};
	};
}
#endif