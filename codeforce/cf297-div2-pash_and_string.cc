#include <iostream>

#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
int main() {
	string s;
	cin >> s;
	int m; 
	cin >> m; 
	size_t size = s.size();

	int cnt[size];
	int sum[size];

	fill(cnt, cnt + size, 0);
	fill(sum, sum + size, 0);

	for (int i = 0; i < m; ++i) {
		int ai;
		cin >> ai;
		cnt[ai - 1] += 1;
	}
	partial_sum(cnt, cnt + size, sum);
//	for_each(cnt, cnt + size, [](int c) {printf("%d ", c); });
//	printf("\n");
//	for_each(sum, sum + size, [](int c) {printf("%d ", c); });
//	printf("\n");

	for (int i = 0; i < size / 2; i += 1) {
		if ((sum[i] &1) != 0) {
			swap(s[i], s[size - i - 1]);
		}
	}
	cout << s;
	return 0;
}
