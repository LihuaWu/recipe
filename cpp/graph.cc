#include <stdio.h>
#include <stdexcept>

#include "graph.h"

namespace graph {

Graph::Graph(int v) {
	if (v < 0) {
		throw std::invalid_argument("numbers of vertices must be greater than zero."); 
	}
	_vertex = v;
	_edge = 0;
	adj.resize(v);
}

Graph::Graph(std::ifstream& is) {
	int edge;
	_edge = 0;
	is >> _vertex >> edge;
	if (_vertex < 0) {
		throw std::invalid_argument("numbers of vertices must be greater than zero."); 
	}
	adj.resize(_vertex);

	int v, w;
//	printf("vertices is : %d edge is : %d\n", _vertex, edge);
	for (int i = 0; i < edge; ++i) {
		is >> v >> w;
//		printf("i is : %d v is : %d and w is : %d.\n", i, v, w);
		AddEdge(v, w);
	}
}

void Graph::AddEdge(int v, int w) {
	isValidVertex(v);
	isValidVertex(w);
	++_edge;
	adj[v].push_back(w);
	adj[w].push_back(v);
}

std::list<int> Graph::Adj(int v) const {
	isValidVertex(v);
	return adj[v];
}

std::string Graph::ToString() {
	std::ostringstream oss;
	oss << _vertex << " vertices, " << _edge << " edges\n"; 
	for (int v = 0; v < _vertex; v++) {
		oss << v << ": ";
		for (auto w : adj[v]) {
			oss << w << " ";
		}
		oss<<std::endl;
	}
	return oss.str();
}

} //namespace graph
