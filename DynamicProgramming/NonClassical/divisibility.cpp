#include <bits/stdc++.h>
using namespace std;
#define MAX 10000+10
int m,n,k;
int numeros[MAX];
int memo[MAX][MAX];
/*
2+2+2-4 = 2
2-2-2+4 = 2
*/
bool status;
int dp(int suma,int pos){
	suma = ((suma%k)+k)%k;
	if(pos == n-1){
		if(suma == 0) return 1;
		return 0;
	}
	if(memo[suma][pos] != -1) return memo[suma][pos];
	int res = 0;
	res = max(res,dp(suma+numeros[pos+1],pos+1));
	res = max(res,dp(suma-numeros[pos+1],pos+1));
	memo[suma][pos] = res;
	return memo[suma][pos];
}
int main(){
	scanf("%d",&m);
	while(m--){
		memset(memo,-1,sizeof memo);
		scanf("%d %d",&n,&k);
		for(int i = 0; i < n; i++) scanf("%d",&numeros[i]);
		int status = dp(numeros[0],0);
		if(status)
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
}
