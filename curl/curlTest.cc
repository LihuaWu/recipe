#include <stdio.h>

#include "Curl.h"

int main(int argc, char**argv) {

	curl::Curl c;
	std::string url(argv[1]);
	c.get(url);
	if(c.status()) {
		printf("get succeed with chunk size: %d\n", c.data().size);
	}


	return 0;
}
