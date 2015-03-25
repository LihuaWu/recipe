#pragma once

#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <utility>

namespace graph {

class DirectedGraph {
public:
	DirectedGraph(std::ifstream& is) {
		is >> _vertexNumber >> _edgeNumber;
		_edges.resize(_vertexNumber);
		int v, w;
		float weight;
		for (int i = 0; i < _edgeNumber; ++i) {
			is >> v >> w >> weight;
			addEdge(v, w, weight);
		}
	}

	int V() const { return _vertexNumber; }
	int E() const { return _edgeNumber; }

	std::list<std::pair<int, double>> edges(int v) const {
		return _edges[v];
	}

	std::string ToString() const {
		std::ostringstream oss;
		oss << _vertexNumber << " vertices, " << _edgeNumber << " edges\n"; 
		for (int v = 0; v < _vertexNumber; v++) {
			oss << v << ": ";
			for (auto w : _edges[v]) {
				oss << w.first << "-" << w.second << " ";
			}
			oss<<std::endl;
		}
		return oss.str();
	}

	void addEdge(int v, int w, double weight) {
		_edges[v].push_back(std::make_pair(w, weight));
	}

private:
	int _edgeNumber;
	int _vertexNumber;
	std::vector<std::list<std::pair<int, double>>> _edges; //a->b with weight
}; //class Graph

} //namespace graph
