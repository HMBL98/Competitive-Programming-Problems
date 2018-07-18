#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++) if(__gcd(i,j) == 1)res++;
	cout << res << "\n";
}

