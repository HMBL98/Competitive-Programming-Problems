#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 100+10
int n,values[MAX],memo[MAX][MAX];

int dp(int l,int r){
	if(memo[l][r] != -1)return memo[l][r];
	if(l == r)return 0;
	if(l+1 == r)return (values[l]-values[l-1])*(values[r]-values[r-1]);
	int res = 1<<20;
	for(int i = l; i < r; i++){
		int tmp = ((values[i]-values[l-1])%100)*((values[r]-values[i])%100);
		res = min(res,tmp+dp(l,i)+dp(i+1,r));
	}
	memo[l][r] = res;
	return res;
}
int main(){
	optimizar_io;
	while(cin >> n){
		for(int i = 0; i < MAX; i++)for(int j = 0; j < MAX; j++) memo[i][j] = -1;
		values[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> values[i];
			values[i] += values[i-1];
		}
		cout << dp(1,n) << "\n";
	}
}
