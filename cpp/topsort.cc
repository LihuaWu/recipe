#include <stdio.h>

#include <vector>
#include <queue>

#include "wgraph.h"

namespace graph {

void inDegrees(const DirectedGraph& g, std::vector<int>& indegrees)  {
	for (int i = 0; i < g.V(); ++i) {
		for (auto& w: g.edges(i)) {
			indegrees[w]++;
		}
	}
}

void topsort(const DirectedGraph& g, std::vector<int>& sorted) {
	std::vector<int> indegrees(g.V(), 0);
	inDegrees(g, indegrees);
	std::queue<int> q;
	int order = 0;

	for (int i = 0; i < g.V(); ++i) {
		if (indegrees[i] == 0) {q.push(i);}
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		sorted[v] = order++;
		for (auto& w: g.edges(v)) {
			indegrees[w.first]--;
			if (indegrees[w.first] == 0) {
				q.push(w.first);
			}
		}
	}

	if (order != g.V()) {
		printf("not a DAG, only %d vertices found\n", order);
	}
}

} // namespace graph
