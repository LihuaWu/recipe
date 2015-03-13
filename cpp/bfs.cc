#include <stdio.h>

#include <sstream>
#include <queue>
#include <algorithm>
#include <functional>

#include "graph.h"
#include "bfs.h"

namespace graph {

void BreadFirstPaths::bfs(const Graph& g, int s) {
	std::queue<int> q;
	std::fill(distTo.begin(), distTo.end(), MAX);

	distTo[s] = 0;
	marked[s] = true;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		std::list<int> adj = std::move(g.Adj(v));
		for (int w: adj) {
			if (!marked[w]) {
				edgeTo[w] = v;
				distTo[w] = distTo[v] + 1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

bool BreadFirstPaths::check(const Graph& G, int s) {
	if (distTo[s] != 0) {
		std::ostringstream oss;
		oss << "distance of source " << s << " to itself = " << distTo[s];
		printf("%s\n", oss.str().c_str());
		return false;
	}

	for (int v = 0; v < G.V(); ++v) {
		for (int w : G.Adj(v)) {
			if (hasPathTo(v) != hasPathTo(w)) {
				std::ostringstream oss;
				oss << "edge " << v << '-' <<  w << std::endl;
				oss << "hasPathTo(" << v << ") = " << hasPathTo(v) << std::endl;
				oss << "hasPathTo(" << w << ") = " << hasPathTo(w) << std::endl;
				printf("%s\n", oss.str().c_str());
				return false;
			}
			if (hasPathTo(v) && (distTo[w] > distTo[v] + 1)) {
				std::ostringstream oss;
				oss << "edge " << v << '-' <<  w << std::endl;
				oss << "distanceTo(" << v << ") = " << distTo[v] << std::endl;
				oss << "distanceTo(" << w << ") = " << distTo[w] << std::endl;
				printf("%s\n", oss.str().c_str());
				return false;


			}
		}
	}

	for (int w = 0; w < G.V(); w++) {
		if (!hasPathTo(w) || w == s) continue;
		int v = edgeTo[w];
		if (distTo[w] != distTo[v] + 1) {
			std::ostringstream oss;
			oss << "shortest path edge " << v << '-' <<  w << std::endl;
			oss << "distanceTo(" << v << ") = " << distTo[v] << std::endl;
			oss << "distanceTo(" << w << ") = " << distTo[w] << std::endl;
			printf("%s\n", oss.str().c_str());
			return false;

		}
	}
	for_each(distTo.begin(), distTo.end(), [](int c) {printf("%d ", c); });
	printf("\n");
	return true;
}

BreadFirstPaths::BreadFirstPaths(const Graph& g, int s) {
	marked.resize(g.V());
	distTo.resize(g.V());
	edgeTo.resize(g.V());

	std::fill(distTo.begin(), distTo.end(), MAX);
	bfs(g, s);
}

} //namespace graph
