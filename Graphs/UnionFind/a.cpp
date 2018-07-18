#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 100000;
	cout << n << " " << n << "\n";
	for(int i = 1; i < n; i++){
		cout << i << " " << i+1 << " " << 1000000000 << "\n";
	}
	for(int i = 1; i <= n; i++){
		cout<< i << " " << n-i+1 << "\n";
	}
}
