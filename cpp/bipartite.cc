#include <vector>
#include <queue>

#include "graph.h"
#include "bipartite.h"

namespace graph {

Bipartite::Bipartite(const Graph& G) {
	_isBipartite = true;
	_color.resize(G.V());
	_edgeTo.resize(G.V());
	for (int v = 0; v < G.V(); v++) {
		if (!_marked[v]) {
			bfs(G, v);
		}
	}
}

Bipartite::bfs(const Graph& g, int v) {
	std::queue<int> q;
	_marked[v] = true;
	q.push(v);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		std::list<int> adj = std::move(g.Adj(v));
		for (auto w: adj) {
			if (!_marked[w]) {
				_edgeTo[w] = v;
				_color[w] = !_color[v];
				q.push(w);
			} else if (_color[w] == _color[v]) {
				_isBipartite = false;
				return;
			}
		}
	}
}



} //namespace graph
