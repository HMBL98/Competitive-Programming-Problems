#include <bits/stdc++.h>
using namespace std;
#define MAX 1000+10
int t,n,g;
int pesos[MAX],valores[MAX];
int memo[MAX][MAX];

int dp(int peso,int pos){
	if(pos == n)return 0;
	if(memo[peso][pos] != -1) return memo[peso][pos];
	int tomar = -1,notomar = -1;
	if(pesos[pos] <= peso){
		tomar = valores[pos] + dp(peso-pesos[pos],pos+1);
	}
	notomar = dp(peso,pos+1);
	memo[peso][pos] = max(tomar,notomar);
	return memo[peso][pos];
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%d %d",&valores[i],&pesos[i]);
		scanf("%d",&g);
		int res = 0;
		for(int i = 0; i < g; i++){
			int cap; scanf("%d",&cap);
			res += dp(cap,0);
		}
		printf("%d\n",res);
	}
}
