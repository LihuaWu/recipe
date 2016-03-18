#include <stdio.h>

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

#include "../wgraph.h"
#include "../topsort.h"

using namespace graph;

TEST(DirectedGraph, TopSort) {
	std::string fileName = "./test/topsort_data";
	std::ifstream ifs(fileName);
	DirectedGraph g(ifs);
	printf("%s\n", g.ToString().c_str());
	std::vector<int> sorted(g.V(), -1);
	graph::topsort(g, sorted);
	for_each(sorted.begin(), sorted.end(), [](int v) {
			printf("%d ", v); });
	printf("\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
