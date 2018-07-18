//10943 - How do you add?
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000
typedef long long ll;
ll memo[100+10][100+10];
int n,k;

ll dp(ll cuantos,ll total){
	if(cuantos == k) return (total == n) ? 1 : 0;
	if(memo[cuantos][total] != -1) return memo[cuantos][total];
	ll res = 0;
	for(int i = 0; i <= n; i++) if(total+i <= n)res = (res%mod+dp(cuantos+1,total+i)%mod)%mod;
	memo[cuantos][total] = res;
	return res;
}


int main(){
	while(cin >> n >> k,(n||k)){
		for(int i = 0; i < 100+10; i++)for(int j = 0; j < 100+10; j++)memo[i][j] = -1;
		ll res = dp(0,0);
		cout << res << "\n";
	}
}

