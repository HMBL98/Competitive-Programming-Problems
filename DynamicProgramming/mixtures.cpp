#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int N,values[MAX];

int dp(int l,int r){
	int res = 1<<20;
	for(int i = l; i < r-1; i++){
		int tmp = values[i]*values[i+1];
		values[][]
		
	}
}
int main(){
	while(cin >> N){
		for(int i = 0; i < N; i++)cin >> values[i];
		cout << dp(0,N) << "\n";
	}
}
