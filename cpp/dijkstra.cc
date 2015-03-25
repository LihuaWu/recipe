#include <vector>
#include <queue>
#include <limits>

#include "dijkstra.h"

using namespace graph;

void printPath(const std::vector<int>& pathTo, int start, int end) {
	if (start != end) {
		printPath(pathTo, pathTo[start], end);
		printf("%d ", start);
	} else {
		printf("%d ", end);
	}
}

void graph::dijkstra(const DirectedGraph& g, int start) {
	std::vector<bool> visited(g.V());
	std::vector<double> distanceTo(g.V(), std::numeric_limits<double>::max());
	std::vector<int> pathTo(g.V(), -1);

	distanceTo[start] = 0;
	int v = start;
	double distance;
	while (!visited[v]) {
		visited[v] = true;
		for (auto & w: g.edges(v)) {
			int otherEdge = w.first;
			double weight = w.second;
			if (distanceTo[otherEdge] > distanceTo[v] + weight) {
				distanceTo[otherEdge] = distanceTo[v] + weight;
				pathTo[otherEdge] = v;
			}
		}

		distance = std::numeric_limits<double>::max();
		v = 0;
		for (int i = 0; i < g.V(); ++i) {
			if ((!visited[i] && (distance > distanceTo[i]))) {
				distance = distanceTo[i];
				v = i;
			}
		}
	}

	for (int i = 0; i < g.V(); ++i) {
		printf("%d %lf ", i, distanceTo[i]);
		printf("with path: ");
		printPath(pathTo, i, start);
		printf("\n");

	}
}
