#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k;
ll memo[10000+10];

ll dp(int total){
	if(total == n) return 1;
	if(memo[total] != -1)return memo[total];
	ll res = 0;
	for(int i = 1; i <= k; i++){
		if(total+i <= n ) res += dp(total+i);
	}
	memo[total] = res;
	return res;
}
int main(){
	memset(memo,-1,sizeof memo);
	cin >> n >> k;
	ll res = dp(0);
	cout << res << endl;
	
}
