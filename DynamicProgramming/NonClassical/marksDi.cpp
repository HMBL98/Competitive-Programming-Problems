#include <bits/stdc++.h>
using namespace std;
int k,n,t,p;
int memo[100][100];
int dp(int total,int pos){
	if(memo[total][pos] != -1) return memo[total][pos];
	if(pos == n){
		if(total == 0) return 1;
		return 0;
	}
	int res = 0;
	for(int i = p; i <= total; i++){
		res += dp(total-i,pos+1);
	}
	memo[total][pos] = res;
	return memo[total][pos];
}
int main(){
	scanf("%d",&k);
	while(k--){
		memset(memo,-1,sizeof memo);
		scanf("%d %d %d",&n,&t,&p);
		int res = dp(t,0);
		printf("%d\n",res);
	}
}
