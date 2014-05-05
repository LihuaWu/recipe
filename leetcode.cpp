#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>

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


int main(){
	int a[] = {1,2,2,3,4,5,6,6,6,9};
	size_t len = sizeof(a)/sizeof(int);
	test_remove(a, len);

	int b[] = {2,2,2,2,2,2,2};
	len = sizeof(b)/sizeof(int);
	test_remove(b, len);

	int c[] = {2,3,4,5,6,7,8};
	len = sizeof(c)/sizeof(int);
	test_remove(c, len);

	int d[] = {}
	len = sizeof(c)/sizeof(int);
	test_remove(c, len);

	return 0;
}
