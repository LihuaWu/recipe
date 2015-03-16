#include <vector>

namespace graph {

class Graph;

enum EdgeType {TREE, BACK, FORWARD, CROSS};

class DepthFirstSearch {
public:
	DepthFirstSearch(const Graph& g);
	void dfs(const Graph& g, int s);

protected:
	virtual void preProcessVertex(int v) {}
	virtual void postProcessVertex(int v) {}
	virtual void processEdge(int x, int y) {}

	bool _finished; //allow for search termination.
	int _time;
	std::vector<bool> _discovered;
	std::vector<bool> _processed;
	std::vector<int> _entryTime;
	std::vector<int> _exitTime;
	std::vector<int> _parent;

}; //class DepthFirst

class FindCycle : public DepthFirstSearch {
public:
	FindCycle(const Graph& g) : DepthFirstSearch(g) {}
	void processEdge(int x, int y);
private:
	void findPath(int x, int y); 
	EdgeType edgeClassification(int x, int y);

}; // class FindCycle


} //namespace graph
