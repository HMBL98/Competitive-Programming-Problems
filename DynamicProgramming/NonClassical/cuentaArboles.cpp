#include <bits/stdc++.h>
using namespace std;

#define MAX 10001+10
#define MOD 1000000
typedef unsigned long long int ulli;
ulli catalan[MAX];

int main(){
	int n;
	cin >> n;
	catalan[0] = catalan[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < i; j++ ){
			catalan[i] += ((catalan[j]%MOD)*(catalan[i-j-1]%MOD))%MOD;
			catalan[i] = catalan[i]%MOD;
		}
	}
	cout << catalan[n] << endl;
}
