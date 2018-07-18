#include <bits/stdc++.h>
using namespace std;

#define MAX 50+10
typedef long long ll;
ll n,m,valores[MAX],memo[1000][1000];
ll dp(ll pos,ll total){
	if(memo[pos][total] != -1) return memo[pos][total];
	if(pos == m) return 0;
	if(total == 0) return 1;
	ll res = 0;
	for(int i = pos; i < m; i++){
		if(valores[i] <= total) res += dp(i,total-valores[i]);
	}
	memo[pos][total] = res;
	return res;
}
int main(){
	memset(memo,-1,sizeof memo);
	scanf("%lld %lld",&n,&m);
	for(int i = 0; i < m; i++)scanf("%lld",&valores[i]);
 	ll maneras = dp(0,n);
	printf("%lld\n",maneras);
}
