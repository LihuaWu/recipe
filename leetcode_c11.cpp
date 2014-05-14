#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <set>

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

vector<vector<int> >
three_sum(vector<int>& v){
	vector<vector<int> > result;
	vector<int> tmp;
	if (v.size() < 3)
		return result;

	sort(v.begin(), v.end());

	int cur_v = v[0] - 1;
	for (auto i = v.begin(); i < prev(v.end(), 2); ++i){
		if (cur_v == *i) {
			continue; //skip same a
		} else {
			cur_v = *i;
		}
		auto start = next(i);
		auto end = prev(v.end());
		int target = -*i;
		while (start < end){
			int cur = *start + *end;
			if (cur == target){
				int cur_s = *start;
				int cur_e = *end;

				tmp.clear();
				tmp.push_back(*i);
				tmp.push_back(*start);
				tmp.push_back(*end);
				result.push_back(tmp);


				while (*++start == cur_s); //skip same b
				while (*--end == cur_e); //skip same c

			}else if (cur < target){
				++start;
			}else {
				--end;
			}
		}
	}
	return result;
}

int test_three_sum(){
	int a[] = {-1, 0, 1, 2, -1, -4};
	size_t len = sizeof(a)/sizeof(int);
	vector<int> v(a, a + len);
	vector<vector<int> > m = three_sum(v);
	for (auto i : m){
		for (auto j : i){
			cout<<j<<"\t";
		}
		cout<<endl;
	}
	return 0;
}


int main(){

	test_three_sum();

//	test_two_sum();

	return 0;
}
