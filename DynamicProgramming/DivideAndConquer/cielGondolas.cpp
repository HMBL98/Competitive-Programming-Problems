#include <bits/stdc++.h>
using namespace std;
#define MAX 4000+10
int n,k,suma[MAX][MAX],dp[MAX][MAX];

void computeDP(int g,int i,int j,int l,int r){
	if(i > j) return;
	int mid = i+j >> 1;
	int best = l;
	int indice = (mid < r) ? mid : r;
	for(int k = l; k <= indice; k++){
		int nuevo = dp[k-1][g-1]+(suma[mid][mid]-suma[mid][k-1]-suma[k-1][mid]+suma[k-1][k-1]);
		if(nuevo < dp[mid][g]){
			dp[mid][g] = nuevo;
			best = k;
		}
	}
	computeDP(g,i,mid-1,l,best);
	computeDP(g,mid+1,j,best,r);
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			char ch;
			while(ch = getchar(), (ch < '0' || ch > '9'));
			suma[i][j] = ch - '0';
			suma[i][j] += suma[i - 1][j] + suma[i][j - 1] - suma[i - 1][j - 1];
		}
	}
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = 1<<30;
    	dp[0][0] = 0;
	for(int i = 1; i <= k; i++) computeDP(i,1,n,1,n);
	printf("%d\n",dp[n][k]/2);
}
