//11341 - Term Strategy
#include <bits/stdc++.h>
using namespace std;

int datos[15][110],memo[15][110],n,t,m;

int dp(int pos,int total){
	if(pos >= n)return 0;
	if(memo[pos][total] != -1)return memo[pos][total];
	int maximo = -100000000;
	for(int i = 1; i <= m; i++){
		if(datos[pos][i-1] >= 5 && total-i >= 0){
			int tmp = datos[pos][i-1] + dp(pos+1,total-i);
			maximo = max(maximo,tmp);
		}
	}
	memo[pos][total] = maximo;
	return maximo;
}


int main(){
	cin >> t;
	while(t--){
		for(int i = 0; i < 15; i++)for(int j = 0; j < 110; j++)memo[i][j] = -1;
		cin >> n >> m;
		for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cin >> datos[i][j];
		int res = dp(0,m);
		if(res < 5*n) cout << "Peter, you shouldn't have played billiard that much.\n";
		else cout << "Maximal possible average mark - " << fixed << setprecision(2) <<  (double)res/(double)n+1e-9 << ".\n";
	}
}
