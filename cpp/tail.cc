
#include <stdio.h>

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	auto printUsage = [](char* moduleName) {
		char Usage[100];
		snprintf(Usage, 100, "Usage: %s file number.", moduleName);
		printf("%s\n", Usage);
	};

	if (argc != 3) {
		printUsage(argv[0]);
		return -1;
	}

	string fileName(argv[1]);
	size_t lineCount;
	istringstream iss(argv[2]);
	iss >> lineCount;

	ifstream ifs(fileName);
	ifs.seekg(0, ifs.end);
	int fileSize = ifs.tellg();


	int curLineCount = 0;
	string output;
	for (int i = 0; i < fileSize; ++i) {
		ifs.seekg(-i - 1, ifs.end);
		char c ;
		ifs.get(c);

		if (c == '\n') {
			++curLineCount;
			if (curLineCount > lineCount) {
				break;
			}
		}
		output.push_back(c);
	}

	reverse(output.begin(), output.end());

	printf("%s", output.c_str());

	return 0;
}
