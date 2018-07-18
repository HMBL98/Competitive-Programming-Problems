#include <bits/stdc++.h>
using namespace std;

int main(){
	int a = 5, b = 3;
	cout << a << " " << b << "\n";
	a ^= b ^= a ^= b;
	cout << a << " " << b << "\n";
}
