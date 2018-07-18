#include <bits/stdc++.h>
using namespace std;

#define MAX 1000+10
int memo[MAX][MAX],x[MAX],y[MAX],n,m;

int dp(int i,int j){
	if(memo[i][j] != -1) return memo[i][j];
	if(i == 0 && j == 0) return 0;
	if(j == 0) return dp(i-1,0)+x[i];
	if(i == 0) return dp(0,j-1)+y[j];
	memo[i][j] = min(dp(i-1,j)+x[i]*(j+1),dp(i,j-1)+y[j]*(i+1));
	return memo[i][j];
}

int main(){
	memset(memo,-1,sizeof memo);
	cin >> n >> m;
	n--,m--;
	for(int i = 1; i <= n; i++)cin >> x[i];
	for(int i = 1; i <= m; i++)cin >> y[i];
	sort(x+1,x+n+1); sort(y+1,y+m+1);
	reverse(x+1,x+n+1); reverse(y+1,y+m+1);
	int res = dp(n+1,m+1);
	cout << res << endl;
}
