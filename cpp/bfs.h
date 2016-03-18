#pragma once
#include <limits>
#include <vector>

namespace graph {

class Graph;

class BreadFirstPaths {
public:
	BreadFirstPaths(const Graph& g, int s);

	bool hasPathTo(int v) {return marked[v];}
	int distanceTo(int v) {return distTo[v];}
	bool check(const Graph& g, int s);

private:
	void bfs(const Graph& g, int s);

	const int MAX = std::numeric_limits<int>::max();
	std::vector<bool> marked;
	std::vector<int> edgeTo; 
	std::vector<int> distTo;


}; //class BreadFirstPaths

}//namespace graph
