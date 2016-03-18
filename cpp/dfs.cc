#include <stdio.h>

#include "graph.h"
#include "dfs.h"

using namespace graph;

DepthFirstSearch::DepthFirstSearch(const Graph& G) {
	_discovered.resize(G.V());
	_processed.resize(G.V());
	_entryTime.resize(G.V());
	_exitTime.resize(G.V());
	_parent.resize(G.V());
	_time = 0;
	_finished = false;
}

void DepthFirstSearch::dfs(const Graph& g, int v) {
	printf("cur vertex: %d\n", v);
	if (_finished) return;
	_discovered[v] = true;
	_time += 1;
	_entryTime[v] = _time;
	preProcessVertex(v);
	printf("processing vertex: %d\n", v);

	std::list<int> adj = std::move(g.Adj(v));
	for (auto y: adj) {
		printf("%d with adj : %d\n", v, y);
		if (!_discovered[y]) {
			_parent[y] = v;
			processEdge(v, y);
			dfs(g, y);

		} else if (!_processed[y]) {
			processEdge(v, y);
		}
		if (_finished) return;
	}

	postProcessVertex(v);
	_time += 1;
	_exitTime[v] = _time;
	_processed[v] = true;
}

void FindCycle::findPath(int x, int y) {
	int t = y;
	printf("cycle path: ");
	while (t != x) {
		printf("%d ", t);
		t = _parent[t];
	}
	printf("%d\n", t);
}

EdgeType FindCycle::edgeClassification(int x, int y) {
	if (_parent[y] == x) return TREE; 
	if (_discovered[y]) return BACK;

}

void FindCycle::processEdge(int x, int y) {
	printf("processing edge: %d - %d - %d\n", x, y, _parent[x]);
	//process each undirected edge exact once to prevent spurious cycle(x,y,x)
	EdgeType edgeType = edgeClassification(x, y);
	if (edgeType == BACK && (_parent[x] != y)) {
		printf("cycle from %d to %d\n", y, x);
		findPath(y, x);
	//	_finished = true;
	}	
}
