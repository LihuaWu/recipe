#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <vector>
#include <limits>

using namespace std;

size_t remove_dup_elem(int* arr, int arr_len){
	// pre condition
	assert(arr != NULL);
	assert(arr_len > 0);

	int tail, cur, copy;
	tail = cur = 0;
	copy = arr[0];
	for (size_t i = 0; i < arr_len; ++i){
		int tmp = arr[i];
		if (copy == tmp){
			++cur;
		}else {
			++tail;
			arr[tail] = tmp;
			copy = tmp;
			++cur;
		}

	}
	return tail + 1;
}

int remove_dup_elem2(int* arr, int arr_len){ 
 	// pre condition
	assert(arr != NULL);
	assert(arr_len >= 0);
	if (arr_len == 0) return 0;
	int tail = 0; 
 	for (size_t i = 0; i < arr_len; ++i){   
   		if (arr[i] != arr[tail]){   
   			arr[++tail] = arr[i];   
   		}    
 	} 
	return tail + 1;
}

int test_remove(int* a, size_t len){
	copy(a, a + len, ostream_iterator<int>(cout, "\t"));
	cout<<endl;

	len = remove_dup_elem(a, len);

	copy(a, a + len, ostream_iterator<int>(cout, "\t"));
	cout<<endl;
}


int test_remove(){
	int a[] = {1,2,2,3,4,5,6,6,6,9};
	size_t len = sizeof(a)/sizeof(int);
	test_remove(a, len);

	int b[] = {2,2,2,2,2,2,2};
	len = sizeof(b)/sizeof(int);
	test_remove(b, len);

	int c[] = {2,3,4,5,6,7,8};
	len = sizeof(c)/sizeof(int);
	test_remove(c, len);

	int d[] = {};
	len = sizeof(d)/sizeof(int);
	test_remove(d, len);

	return 0;
}

int min(int a, int b){
	return a < b ? a : b;
}

//Triangle
int triangle(const vector<vector<int> > &tri){
	vector<int> v(tri[tri.size() - 1]);
	for (int i = tri.size() - 2; i >= 0; --i){
		size_t len = tri[i].size();
		for (int j = 0; j < len; ++j){
			v[j] = min(v[j], v[j+1]) + tri[i][j];
		}
	}
	return v[0];
}

int test_triangle(){
	vector<vector<int> > v(4, vector<int>(4, 0));
	v[0][0] = 2;
	v[1][0] = 3; v[1][1] = 4;
	v[2][0] = 6; v[2][1] = 5; v[2][2] = 7;
	v[3][0] = 4; v[3][1] = 1; v[3][2] = 8; v[3][3] = 3;

	cout<<triangle(v)<<endl;
}

int max(int a, int b){
	return a > b ? a : b;
}

int max_sub_array(int *arr, size_t len){
	int result = numeric_limits<int>::min(), balance = 0;
	for (int i = 0; i < len; ++i){
		balance = max(balance + arr[i], arr[i]);
		result = max(result, balance);
	}
	return result;
}

int test_max_sub_arr(){
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout<<max_sub_array(a, (sizeof a)/sizeof(int))<<endl;
}

int main(){
	test_max_sub_arr();
}
