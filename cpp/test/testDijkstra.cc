#include <stdio.h>

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

#include "../wgraph.h"
#include "../dijkstra.h"

using namespace graph;

TEST(DirectedGraph, TopSort) {
	std::string fileName = "./test/dijkstra_data";
	std::ifstream ifs(fileName);
	DirectedGraph g(ifs);
	printf("%s\n", g.ToString().c_str());
	dijkstra(g, 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
