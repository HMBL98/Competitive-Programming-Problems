#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 3;
	bitset<4> foo;
	foo[n] = 1;
	cout << foo << endl;
	if(foo[n] == 1){
		cout << "visited" << endl;
	}
	int a = 0;
	a |= 1 << n;
	cout << a << endl;

}
