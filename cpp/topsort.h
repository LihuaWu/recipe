#pragma once

#include <vector>

#include "wgraph.h"

namespace graph {

void inDegrees(const DirectedGraph& g, std::vector<int>& indegrees); 
void topsort(const DirectedGraph& g, std::vector<int>& sorted); 

}// namespace graph 
