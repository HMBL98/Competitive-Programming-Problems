#include <bits/stdc++.h>
using namespace std;

#define MAX 100+10
#define MOD 1000000007
typedef unsigned long long int ll;
int n,k,d;

ll memo[MAX][2];

ll dp(int total,int estado){
	if(total > n)return 0;
	if(total == n && estado == 1) return 1;
	if(memo[total][estado] != -1) return memo[total][estado];
	ll res = 0;
	for(int i = 1; i <= k; i++){
		int e;
		if(estado) e = 1;
		else e = (i >= d) ? 1 : 0;
		res = ((res%MOD) + (dp(total+i,e)%MOD))%MOD;
	}
	memo[total][estado] = res;
	return res;
}
int main(){
	memset(memo,-1,sizeof memo);
	cin >> n >> k >> d;
	ll res = dp(0,0);
	cout << res << endl;
}
