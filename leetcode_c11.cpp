#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;


//two sum
vector<int> two_sum(vector<int>& v, int target){
	unordered_map<int, int> lm;
	unordered_map<int, int> rm;
	vector<int> result;

	for (int i = 0; i < v.size(); ++i){
		lm[v[i]] = i;
	}

	for (int i = v.size() - 1; i >= 0; --i){
		rm[v[i]] = i;

	}

	for (size_t i = 0; i < v.size(); ++i){
		int remain = target - v[i];
		if (lm.find(remain) != lm.end()){
			size_t second = lm[remain];
			if (second == i)
				second = rm[remain];
			if (second == i)
				continue;
			size_t small_v = min(i, second);
			size_t big_v = max(i, second);
			result.push_back(small_v + 1);
			result.push_back(big_v + 1);
			break;
		}
	}

	return result;
}

int test_two_sum(){
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	vector<int> b = two_sum(v, 6);
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, "\t"));
	cout<<endl;
}

int main(){
	test_two_sum();
	return 0;
}
