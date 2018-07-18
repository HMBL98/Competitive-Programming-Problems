//BAT1 - BATMAN1
#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define MAX 20+5

int t,n,m,k,cost[MAX][MAX],rat[MAX][MAX],val[MAX];
int memo[MAX][1000+10][2];

int dp(int i,int total,int opc){
	if(i >= n || total < 0) return -1<<20;
	if(memo[i][total][opc] != -1)return memo[i][total][opc];
	int tomar = 0,notomar = 0;
	if(!opc) rep(j,0,m)tomar = max(tomar,rat[i][j]+max(dp(i+1,total-val[i]-cost[i][j],0),dp(i,total-val[i]-cost[i][j],1)));
	else rep(j,0,m)tomar = max(tomar,rat[i][j]+max(dp(i+1,total-cost[i][j],0),dp(i,total-cost[i][j],1)));
	notomar = dp(i+1,total,0);
	memo[i][total][opc] = max(tomar,notomar);
	return memo[i][total][opc];
}
int main(){
	cin >> t;
	while(t--){
		memset(memo,-1,sizeof memo);
		cin >> n >> m >> k;
		rep(i,0,n) cin >> val[i];
		rep(i,0,n)rep(j,0,m)cin >> cost[i][j];
		rep(i,0,n)rep(j,0,m)cin >> rat[i][j];
		cout << dp(0,k,0) << "\n";
	}
}
