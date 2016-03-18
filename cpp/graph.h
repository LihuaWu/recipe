#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>

namespace graph {

class Graph {
public:
	Graph(int v, bool directed); 
	Graph(std::ifstream& is, bool directed);
//	Graph(const Graph& g);

	int V() const {return _vertex;}
	int E() const {return _edge; }

	void AddEdge(int v, int w);

	std::list<int> Adj(int v) const;

	int degree(int v) {
		isValidVertex(v);
		return adj[v].size();
	}

	std::string ToString(); 

private:
	void isValidVertex(int v) const {
		if (v >= _vertex || v < 0) {
			std::ostringstream oss;
			oss << "vertex " << v << " is not between 0 and " << _vertex-1;
			throw std::out_of_range(oss.str());
		}
	}

	bool _directed; //directed or undirected.
	int _vertex; //vertex count
	int _edge; //edge count
	std::vector<std::list<int>> adj; //adjacent list info.



}; //class Graph

}//namespace graph
