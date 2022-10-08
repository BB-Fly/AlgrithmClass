#pragma once
#include <vector>

struct road{
	int targ,dist;
	road(int x, int y = 1) :targ(x), dist(y) {}
	road(std::vector<int>& vec):targ(vec[1]),dist(vec[2]){}
};

class Dijkstra {
private:
	std::vector<std::vector<road>>graph;

	template<class T>
	void toGraph(std::vector<std::vector<T>>& edg, bool isDirected) {
		for (int i = 0; i < edg.size(); i++) {
			graph[edg[i][0]].push_back(edg[i][1]);
			if (!isDirected) graph[edg[i][1]].push_back(edg[i][0]);
		}
	}

	template<class T>
	void toGraph(std::vector<std::vector<T>>) {

	}

public:
	template<class T>
	Dijkstra(std::vector<std::vector<T>>& edg,bool isDirected=false, bool isgraph=false) {
		if (!isgraph) toGraph(edg, isDirected);
		else toGraph(edg);
	}
};