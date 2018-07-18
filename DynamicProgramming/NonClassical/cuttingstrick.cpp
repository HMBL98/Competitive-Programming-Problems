//10003 - Cutting Sticks
#include <bits/stdc++.h>
using namespace std;

int l,c,cortes[50+10];

int memo[55][55];


int dp(int i,int j){
	if(memo[i][j] != -1) return memo[i][j];
	if(i+1 >= j) return 0;
	int res = 1<<20;
	for(int k = i+1; k < j; k++){
		res = min(res,(cortes[j]-cortes[i])+dp(i,k)+dp(k,j));
	}
	memo[i][j] = res;
	return res;
}
int main(){
	while(cin >> l,l){
		for(int i = 0; i < 55; i++) for(int j = 0; j < 55; j++) memo[i][j] = -1;
		cin >> c;
		cortes[0] = 0;
		for(int i = 1; i <= c; i++) cin >> cortes[i];
		cortes[c+1] = l;
		int res = dp(0,c+1);
		cout << "The minimum cutting is " << res << ".\n";
	}
}

