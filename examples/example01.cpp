#include <iostream>
#include <chrono>
#include "../src/GeneticAlgorithm.hpp"

using namespace std;
using namespace std::chrono;

const int POPULATION_SIZE = 20;
const int CHROMOSOME_SIZE = 3;

const double INIT_CENTER = 0;
const double INIT_DIAMETER = 50;

const double CROSSOVER_RANGE_MIN = 0.1;
const double CROSSOVER_RANGE_MAX = 0.9;

const double MUTATION_PROBABILITY = 0.3;
const double MUTATION_MAX_AMOUNT = 0.4;

const double OLD_VS_NEW_GENERATION_RATIO = 0.1;

// Here we define a function that calculates fitness 
// for the problem we are trying to solve using GA
// In this example, we are solving three equations
// with three unknowns.
double foo(ChromosomeValues *input) {
	double x = (*input)[0];
	double y = (*input)[1];
	double z = (*input)[2];
	double e1 = 910 - (x *  4 + y * 33 + z * 71);
	double e2 = 357 - (x *  3 - y *  6 + z * 41);
	double e3 = 130 - (x * 23 + y * 14 - z * 22);
	double totalError = abs(e1) + abs(e2) + abs(e3);
	// GA rawards individuals with higher fitness
	// so we subtract totalError from some large value.
	// Individuals with lower totalError will have 
	// higher fitness that way. 
	return 100000 - totalError;
}


int main() {
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	// Initialize Genetic Algorithm class.
	GeneticAlgorithm();

	// Create appropriate blocks for running the algorithm.
	RandomInitializator init_block = RandomInitializator(INIT_CENTER, INIT_DIAMETER);
	RouletteWheelSelection sel_block = RouletteWheelSelection();
	ValueOnePointCrossover cros_block = ValueOnePointCrossover(CROSSOVER_RANGE_MIN, CROSSOVER_RANGE_MAX);
	RealValueAbsAmountMutation mut_block = RealValueAbsAmountMutation(MUTATION_PROBABILITY, MUTATION_MAX_AMOUNT);
	FitnessCalculator fit_block = FitnessCalculator(foo);
	ProportionMerge merge_block = ProportionMerge(OLD_VS_NEW_GENERATION_RATIO);

	Generation gen(POPULATION_SIZE, CHROMOSOME_SIZE);
	init_block.init(&gen); // Initialize generation to some starting values
		
	fit_block.calc(&gen); // Calculate fitness for each individual in starting generation

	cout << "Starting generation: " << endl;
	cout << gen.to_string2() << endl;

	int genNo = 1;
	double bestFitness = 0;
	while(genNo < 500) {
		// Check if there is an individual with better fitness and if there is one
		// update the best fitness and print info to console
		if (gen.getBestIndividual().getFitness() > bestFitness) {
			cout << genNo << "  " << gen.getBestIndividual().getFitness() << endl;
			bestFitness = gen.getBestIndividual().getFitness();
		}

		sel_block.reset();
		sel_block.add_candidates(gen); // Add generation to the selection block for later selections of parents
		
		Generation newGen(0, 0);
		for (int i = 0; i < POPULATION_SIZE; i+=2) {
			// Select parents for reproduction
			Parents parents;
			sel_block.get_selected(&parents, 2);
			// Force two different parents
			while (*(parents[0]) == *(parents[1])) {
				parents.clear();
				sel_block.get_selected(&parents, 2);
			}
		
			cros_block.crossover(&parents); 
			// At this point parents are actually children, so let's change the
			// variable name to avoid further confusion
			Parents children = parents;

			mut_block.mutate(children[0]);
			mut_block.mutate(children[1]);

			newGen.addKids(children);
		}
		fit_block.calc(&newGen);

		// Here we merge old with new generation, leaving some percentage 
		// of the best individuals from the old generation to enter 
		// a generation for next iteration
		Generation tmpGen(0, 0);
		merge_block.merge(gen, newGen, &tmpGen, POPULATION_SIZE);
		gen = tmpGen;
		
		genNo++;		
	}

	cout << "Final generation: " << endl;
	cout << gen.to_string2() << endl;
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	cout << "Execution time: " << duration << endl;

	return 0;
}