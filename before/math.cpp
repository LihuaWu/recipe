#include <iostream>

using namespace std;

int i = 0;

int dive_in(int x){
	i++;
	if (x > 0) {
		cout<<x<<" ";
		return dive_in(x);
	}
	return 0;
}

int main() {
	dive_in(6);
	cout<<endl<<endl;
	cout<<i<<endl;
}
