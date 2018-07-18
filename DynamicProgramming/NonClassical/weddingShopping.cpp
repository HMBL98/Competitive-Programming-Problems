#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,c;
ll n,k;
ll precios[25][25];
ll memo[210][25];
ll backtrack(ll opcion,ll money){
	if(opcion == c){
		return m-money;
	}
	if(memo[money][opcion] != -1){
		return memo[opcion][money];
	}
	ll res = -1;
	for(int i = 1; i <= precios[opcion][0]; i++){
		if(precios[opcion][i] <= money){
			res = max(res,backtrack(opcion+1,money-precios[opcion][i]));
		}
	}
	memo[money][opcion] = res;
	return res;
}
int main(){
	cin >> n;
	while(n--){
		memset(memo,-1,sizeof memo);
		cin >> m >> c;
		//cout << m << " " << c << endl;
		for(int i = 0; i < c; i++){
			cin >> precios[i][0];
			for(int j = 1; j <= precios[i][0]; j++){
				cin >> precios[i][j];
			}
		}
		ll res = backtrack(0,m);
		if(res != -1){
			cout << res << endl;
		}else{
			cout << "no solution" << endl;
		}
	}
}

