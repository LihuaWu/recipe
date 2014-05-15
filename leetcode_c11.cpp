#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <set>
#include <limits>
#include <stdlib.h>
#include <assert.h>
#include <utility>

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

vector<vector<int> > three_sum_v2(vector<int>& v){
	vector<vector<int> > result;
	vector<int> tmp;
	if (v.size() < 3)
		return result;

	sort(v.begin(), v.end());

	for (auto i = v.begin(); i < prev(v.end(), 2); ++i){
		auto start = next(i);
		auto end = prev(v.end());
		int target = -*i;
		while (start < end){
			int cur = *start + *end;
			if (cur == target){
				tmp.clear();
				tmp.push_back(*i);
				tmp.push_back(*start);
				tmp.push_back(*end);
				result.push_back(tmp);
				++start;
				--end;
			} else if (cur < target){ ++start; }
			else { --end; }
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

int test_three_sum(){
	int a[] = {-1, 0, 1, 2, -1, -4};
	size_t len = sizeof(a)/sizeof(int);
	vector<int> v(a, a + len);
	vector<vector<int> > m = three_sum_v2(v);
	for (auto i : m){
		for (auto j : i){
			cout<<j<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

//do not need to skip
int three_sum_closest(vector<int>& v, int target){
	
	int result = -1;
	size_t offset = numeric_limits<int>::max();

	if (v.size() < 3) return result;

	sort(v.begin(), v.end());

	for (auto a = v.begin(); a < prev(v.end(), 2); ++a){

		auto b = next(a);
		auto c = prev(v.end());

		while (b < c){
			int sum = *a + *b + *c;
			size_t cur_offset = abs(sum - target);
			if (cur_offset < offset) {
				result = sum;
				offset = cur_offset;
			} 
			int cur_b = *b;
			int cur_c = *c;
			
			if (sum < target) { ++b; }
			else --c;
		}
	}
	return result;
}

int test_three_sum_closest(){
	int a[] = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6 };
	size_t len = sizeof(a)/sizeof(int);
	vector<int> v(a, a + len);

	cout<<three_sum_closest(v, -59);
	cout<<endl;
	return 0;
}

//four sum
vector<vector<int> > four_sum(vector<int>& v, int target){
	vector<vector<int> > result;
	if (v.size() < 4) return result;
	unordered_map<int, vector<pair<int, int> > > cached;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i){
		for (int j = i + 1; j < v.size(); ++j){
			cached[v[i] + v[j]].push_back(make_pair(i, j));
		}
	}

	for (size_t c = 0; c < v.size(); ++c){
		for (size_t d = c + 1; d < v.size(); ++d){
			int  remain =  target - v[c] - v[d];
			if (cached.find(remain) == cached.end()) continue;
		
			auto vec = cached[remain];
			for (auto i : vec) {
				if (c <= i.second) continue;

				vector<int> cur_rec({v[i.first], v[i.second], v[c], v[d]});
				result.push_back(cur_rec);
			}
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

int test_four_sum(){
	int target = 0;
	int a[] = {1, 0, -1, 0, -2, 2};
	size_t len = sizeof(a)/sizeof(int);
	vector<int> v(a, a + len);
	auto m = four_sum(v, target);
	for (auto i : m){
		for (auto j : i){
			cout<<j<<"\t";
		}
		cout<<endl;
	}

	return 0;
}


int main(){

	test_four_sum();

//	test_three_sum();
//	test_three_sum_closest();
//	test_two_sum();

	return 0;
}
