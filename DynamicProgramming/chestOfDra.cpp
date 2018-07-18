//11420 - Chest of Drawers
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll memo[70][70][3];
int n,s;

ll dp(int pos,int cuantos,int anterior){
	if(memo[pos][cuantos][anterior] != -1) return memo[pos][cuantos][anterior];
	if(pos >= n) return (cuantos == s) ? 1 : 0;

	ll tomar = 0,notomar = 0;

	if(anterior){
		if(pos == n-1) tomar = dp(pos+1,cuantos+2,1);
		else tomar = dp(pos+1,cuantos+1,1);
	}else{
		if(pos == n-1) tomar = dp(pos+1,cuantos+1,1);
		else tomar = dp(pos+1,cuantos,1);
	}
	notomar = dp(pos+1,cuantos,0);

	memo[pos][cuantos][anterior] = tomar+notomar;
	return tomar+notomar;
}

int main(){
	while(cin >> n >> s){
		if(n < 0 && s < 0)break;
		for(int i = 0; i < 70; i++)for(int j = 0; j < 70; j++)for(int k = 0; k < 3; k++)memo[i][j][k] = -1;
		ll res = dp(0,0,0);
		cout << res << "\n";
	}
}

