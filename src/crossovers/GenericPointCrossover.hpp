#include "../config.hpp"
#include "../utils/Randomizer.hpp"
#include <cassert>
#include <set>
#include <vector>

using namespace std;

template <typename T>
void genericPointCrossover(vector<T> *vals1, vector<T> *vals2, uint pointsNo, double crossover_point_min, double crossover_point_max) {
	assert(vals1->size() > 1);
	assert(vals1->size() == vals2->size());
	assert(pointsNo < vals1->size());

	set<uint> sPoints;
	while(sPoints.size() != pointsNo) {
		int point = (int) (Randomizer::getRandomValue(crossover_point_min, crossover_point_max) * vals1->size());
		assert(point >= 0 && point < vals1->size());
		if (point == 0) point = 1;
		if (point == vals1->size()) point = vals1->size() - 1;
		sPoints.insert(point);
	}
	vector<uint> points(begin(sPoints), end(sPoints));
	sort(begin(points), end(points));

	bool swap = false;
	int i = 0;
	while (i < vals1->size()) {
		if (swap) {
			T val = (*vals1)[i];
			(*vals1)[i] = (*vals2)[i];
			(*vals2)[i] = val;
		}
		if (points[0] == i) {
			swap = !swap;
			points.erase(begin(points));
		}
		i++;
	}
}

