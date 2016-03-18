#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int num;
	cin >> num; 

	int cnt[26];
	fill(cnt, cnt + 26, 0);	

	int ret = 0;
	for (int i = 0; i < 2 * num - 2; ++i) {
		char c;
		cin >> c;
//		for_each(cnt, cnt + 26, [](int c) {printf("%d ", c); });
//		printf("\n");
		if ((i & 1) != 0) {
			int idx = c  - 'A';  	
			if (cnt[idx] > 0) { cnt[idx] -= 1; } 
			else { ret += 1; }
		} else {
			int idx = c  - 'a';  	
			cnt[idx] += 1;
		}
	}
	cout << ret;

	return 0;
}
