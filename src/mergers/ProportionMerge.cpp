#include "ProportionMerge.hpp"

namespace GA {
	ProportionMerge::ProportionMerge(double proportion) : proportion(proportion) {
		assert(proportion <= 1);
		assert(proportion >= 0);
	}
	ProportionMerge::~ProportionMerge() {
		if (g1 != NULL) delete g1;
		if (g2 != NULL) delete g2;
	}

	void ProportionMerge::merge(const Generation& gen1, const Generation& gen2, Generation* out, int count) {
		g1 = new Generation(gen1);
		//sort((*(g1->getIndividuals())).begin(), (*(g1->getIndividuals())).end());
		g1->sortIndividualsByFitness();
		g2 = new Generation(gen2);
		//sort((*(g2->getIndividuals())).begin(), (*(g2->getIndividuals())).end());
		g2->sortIndividualsByFitness();

		assert(out != NULL);
		assert(g1 != NULL && g2 != NULL);
		assert(g1->size() > 0 && g2->size() > 0);
		assert(g1->size() == g2->size());
		assert(count <= g1->size());

		int count1 = (int) (count * proportion);
		int count2 = count - count1;

		for (int i = count - 1; i >= count2; i--) {
			Individual* tmpI = &(*(g1->getIndividuals()))[i];
		 	(out->getIndividuals())->push_back(*tmpI);
		}
		for (int i = count - 1; i >= count1; i--) {
			Individual* tmpI = &(*(g2->getIndividuals()))[i];
		 	(out->getIndividuals())->push_back(*tmpI);
		}
		//sort((*(out->getIndividuals())).begin(), (*(out->getIndividuals())).end());
		out->sortIndividualsByFitness();

	}
}