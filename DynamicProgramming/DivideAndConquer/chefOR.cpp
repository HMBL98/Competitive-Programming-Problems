#include <bits/stdc++.h>
using namespace std;

#define MAX 5000+10
typedef long long ll;
int T,n,k;
ll arreglo[MAX],dp[MAX][MAX],costo[MAX][MAX];

void computeDP(ll i, ll l1, ll l2,ll p1, ll p2){
	if(l1 > l2)return;
	ll mid = l1+l2 >> 1;
	ll best = -1;
	dp[i][mid] = 1<<30; dp[i][mid] *= -1;
	ll indice = (mid < p2) ? mid : p2; 
	for(int j = p1; j <= indice; j++){
		ll nuevo = dp[i-1][j] + costo[j+1][mid];
		if(nuevo > dp[i][mid]){
			dp[i][mid] = nuevo;
			best = j;
		}
	}
	computeDP(i,l1,mid-1,p1,best);
	computeDP(i,mid+1,l2,best,p2);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i = 1; i <= n; i++) scanf("%lld",&arreglo[i]);
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++)
				costo[i][j] = arreglo[j]|costo[i][j-1];
		for(int i = 1; i <= n; i++) dp[1][i] = costo[1][i];
		for(int i = 2; i <= k; i++) computeDP(i,1,n,1,n);
		printf("%lld\n",dp[k][n]);
	}
}
