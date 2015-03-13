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
	Graph(int v); 
	Graph(std::ifstream& is);
//	Graph(const Graph& g);

	size_t V() {return _vertex;}
	size_t E() {return _edge; }

	void AddEdge(size_t v, size_t w);

	std::list<int> Adj(size_t v);

	size_t degree(size_t v) {
		isValidVertex(v);
		return adj[v].size();
	}

	std::string ToString(); 

private:
	void isValidVertex(size_t v) {
		if (v >= _vertex) {
			std::ostringstream oss;
			oss << "vertex " << v << " is not between 0 and " << _vertex-1;
			throw std::out_of_range(oss.str());
		}
	}

	size_t _vertex; //vertex count
	size_t _edge; //edge count
	std::vector<std::list<int>> adj; //adjacent list info.



}; //class Graph

}//namespace graph
