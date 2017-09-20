#ifndef DEBUG
	#include <iostream>
	#define DEBUG(msg) if(false) std::cout << msg << std::endl
#endif

#ifdef USE_REAL_VALUES
	#define GENOTYPE_TYPE double
#else
	#define GENOTYPE_TYPE int
#endif
