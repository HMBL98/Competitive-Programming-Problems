#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int monedas[] = {1,5,10,25,50};
ll memo[40000][6];

/*ll dp(int total,int pos){
	if(pos > 4) return 0;
	if(total == 0) return 1;
	if(total < 0) return 0;
	if(memo[total][pos] != -1) return memo[total][pos];
	memo[total][pos] = dp(total,pos+1)+dp(total-monedas[pos],pos);
	return memo[total][pos];
}*/
ll dp(int total,int pos){
	if(memo[total][pos] != -1) return memo[total][pos];
	if(total == 0) return 1;
	ll res = 0;
	for(int i = pos; i < 5; i++){
		if(monedas[i] <= total)res += dp(total-monedas[i],i);
	}
	memo[total][pos] = res;
	return memo[total][pos];
}

int main(){
	int n;
	memset(memo,-1,sizeof memo);
	while(scanf("%d",&n) != EOF){
		ll res = dp(n,0);
		if(res != 1)
			printf("There are %ld ways to produce %d cents change.\n",res,n);
		else
			printf("There is only 1 way to produce %d cents change.\n",n);

	}
}
