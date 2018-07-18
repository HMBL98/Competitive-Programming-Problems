#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10
typedef long long ll;

int n,arreglo[MAX][3];
ll memo[MAX][3];

ll dp(int i,int j){
	if(i == n-1 && j == 1)return 0;
	if(j < 0 || j > 2 || i > n) return 1e10;
	if(memo[i][j] != -1)return memo[i][j];
	ll res = 1e10;

	ll uno = arreglo[i][j] + dp(i+1,j-1);
	ll dos = arreglo[i][j] + dp(i+1,j);
	ll tres = arreglo[i][j] + dp(i+1,j+1);
	ll cuatro = arreglo[i][j] + dp(i,j+1);
	res = min(res,uno); res = min(res,dos), res = min(res,tres);
	res = min(res,cuatro);
	memo[i][j] = res;
	return res;
}

int main(){
	int caso = 0;
	while(cin >> n && n){
		memset(memo,-1,sizeof memo);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 3; j++)cin >> arreglo[i][j];
		ll res = dp(0,1);
		cout << ++caso << ". " <<  res+arreglo[n-1][1] << endl;

	}
}
