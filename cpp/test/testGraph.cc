#include <stdio.h>

#include <string>
#include <sstream>
#include <fstream>

#include <gtest/gtest.h>

#include "../graph.h"
#include "../bfs.h"

using namespace graph;

TEST(Graph, demouse) {
	std::string fileName = "./test/graph_data";
	std::ifstream ifs(fileName);
	Graph g(ifs);
	printf("%s\n", g.ToString().c_str());
    EXPECT_EQ(1,1);
}

TEST(Graph, BreadFirstPaths) {
	std::string fileName = "./test/graph_data";
	std::ifstream ifs(fileName);
	Graph g(ifs);

	BreadFirstPaths bfs(g, 0);
	bool check = bfs.check(g, 0);
	EXPECT_EQ(check, true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

