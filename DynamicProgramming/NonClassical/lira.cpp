#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int n,b,m,numeros[60];
int memo[100][60000];

int dp(int pos,int total){
	if(memo[pos][total] != -1) return memo[pos][total];
	if(total < 0 || total > m)return -10000000;
	if(pos == n){
		return total;
	}
	int tomar = dp(pos+1,total+numeros[pos]);
	int notomar = dp(pos+1,total-numeros[pos]);
	memo[pos][total] = max(tomar,notomar);
	return memo[pos][total];
}
int main(){
	optimizar_io;
	memset(memo,-1,sizeof memo);
	cin >> n;
	for(int i = 0; i < n; i++)cin >> numeros[i];
	cin >> b >> m;
	int res = dp(0,b);
	if(res < 0 ) cout << "-1" << endl;
	else cout << res << endl;
}
