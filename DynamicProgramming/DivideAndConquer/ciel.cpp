#include <bits/stdc++.h>
using namespace std;
#define MAX 4000+10
int n,k,suma[MAX][MAX],dp[MAX][MAX];

int costo(int i,int j){
	if(i >= j) return 0;
	int res = suma[j][j];
	if(i > 0) res -= suma[j][i-1];
	if(i > 0) res -= suma[i-1][j];
	if(i > 0) res += suma[i-1][i-1];
	return res/2;
}
void computeDP(int i,int l1,int l2,int p1,int p2){
	if(l1 > l2) return;
	int mid = l1+l2 >> 1;
	int best = -1;
	dp[i][mid] = 1<<30;
	for(int j = p1; j <= p2; j++){
		if(dp[i-1][j]+costo(j,mid-1) < dp[i][mid]){
			dp[i][mid] = dp[i-1][j]+costo(j,mid-1);
			best = j;
		}
	}
	computeDP(i,l1,mid-1,p1,best);
	computeDP(i,mid+1,l2,best,p2);
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char ch;
                        while(ch = getchar(), (ch < '0' || ch > '9'));
			suma[i][j] = ch-'0';
			if(i > 0) suma[i][j] += suma[i-1][j];
			if(j > 0) suma[i][j] += suma[i][j-1];
			if(i > 0 && j > 0) suma[i][j] -= suma[i-1][j-1];
		}
	}
	for(int i = 1; i <= n; i++) dp[1][i] = costo(0,i-1);
	for(int i = 2; i <= k; i++) computeDP(i,0,n,0,n);
	printf("%d\n",dp[k][n]);
}
