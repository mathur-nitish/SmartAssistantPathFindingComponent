#ifndef GRIDPATHFINDER_H
#define GRIDPATHFINDER_H

#include "NECESSARY_HEADER.h"
using coordinates = std::pair<int, int>;

struct pair_hash {
	size_t operator()(const coordinates& p) const {
		return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
	}
};

class GridPathFinder {

private:
	
	vector<vector<int>> grid;
	vector<vector<bool>> visited;
	bool isValid(int x, int y) const;

public:
	GridPathFinder(vector<vector<int>> grid);
	vector<coordinates> get_shortestDistance(coordinates st, coordinates en);
	vector<coordinates> get_shortestDistanceOpti(coordinates st, coordinates en);
};

#endif


