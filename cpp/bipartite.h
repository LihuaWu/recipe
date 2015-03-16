#include <vector>

namespace graph {

class Graph;

class Bipartite {
public:
	Bipartite(const Graph& g);
	bool isBipartite() {
		return _isBipartite;

	}
private:
	void bfs(const Graph& g, int v);
	bool _isBipartite;
	std::vector<bool> _color;
	std::vector<bool> _marked;
	std::vector<int> _edgeTo;
	std::vector<int> cycle;
};
} //class Bipartite
