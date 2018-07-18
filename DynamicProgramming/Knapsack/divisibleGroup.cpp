#include <bits/stdc++.h>
using namespace std;
#define MAX 200+10
typedef long long ll;

int n,q,d,m,numeros[MAX];
ll memo[MAX][200][15];
// 1 2 3

ll dp(int pos,int suma,int cuantos){
	if(memo[pos][suma][cuantos] != -1) return memo[pos][suma][cuantos];
	if(cuantos == m){
		if(suma == 0) return 1;
		return 0;
	}
	ll res = 0;
	for(int i = pos; i < n; i++)
		res += dp(i+1,(suma%d+numeros[i]%d)%d,cuantos+1);
	memo[pos][suma][cuantos] = res;
	return res;
}
int main(){
	int casos = 0;
	while(scanf("%d %d",&n,&q),(n||q)){
		for(int i = 0; i < n; i++) scanf("%d",&numeros[i]);
		printf("SET %d:\n",++casos);
		for(int i = 1; i <= q; i++){
			memset(memo,-1,sizeof memo);
			scanf("%d %d",&d,&m);
			printf("QUERY %d: %ld\n",i,dp(0,0,0));
		}
	}
}
