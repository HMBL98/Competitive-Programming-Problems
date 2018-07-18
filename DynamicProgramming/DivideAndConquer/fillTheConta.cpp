//11413 - Fill the Containers
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,valores[1000+10],dp[1000+10][1000+10];

void compute(ll i,ll l1,ll l2,ll p1,ll p2){
	if(l1 > l2)return;
	ll mit = l1+l2 >> 1;
	dp[i][mit] = 1<<30;
	ll best = -1;
	ll indice = (mit < p2) ? mit : p2;
	for(ll j = p1; j <= indice; j++){
		ll nuevo = max(dp[i-1][j],(valores[mit]-valores[j]));
		if(nuevo < dp[i][mit]){
			dp[i][mit] = nuevo;
			best = j;
		}
	}
	compute(i,l1,mit-1,p1,best);
	compute(i,mit+1,l2,best,p2);
}

int main(){
	while(cin >> n >> m){
		for(ll i = 1; i <= n; i++){
			cin >> valores[i];
			valores[i] = valores[i]+valores[i-1];
		}
		for(ll i = 0; i <= n; i++) dp[1][i] = valores[i];
		for(ll i = 2; i <= m; i++) compute(i,0,n,0,n);
		//for(ll i = 1; i <= m; i++)for(ll j = 1; j <= n; j++) cout << i << " " << j << " " << dp[i][j] << "\n";
		cout << dp[m][n] << "\n";
	}
}

