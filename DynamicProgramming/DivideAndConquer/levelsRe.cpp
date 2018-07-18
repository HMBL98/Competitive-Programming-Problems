#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000+10
#define MAX_K 50+10
int n,k;
double arreglo[MAX_N];double dp[MAX_K][MAX_N];

double costo(int a,int b){
	double numerador = 0;
	double res = 0;
	for(int i = a; i <= b; i++){
		numerador += arreglo[i];
		res += (double)numerador/(double)arreglo[i];
	}
	return res;
}
void computeDP(int i,int l1,int l2,int p1,int p2){
	if(l1 > l2)return;
	int mid = l1+l2 >> 1;
	int best = -1;
	dp[i][mid] = 1<<30;
	int indice = (mid < p2) ? mid : p2;
	for(int j = p1; j <= indice; j++){
		double nuevo = dp[i-1][j] + costo(j+1,mid);
		//cout << i << " " << mid << " " << i-1 << " " << j << " " << j+1 << " " << mid << " " << nuevo <<endl;
		if(nuevo < dp[i][mid]){
			dp[i][mid] = nuevo;
			best = j;
		}
	}
	computeDP(i,l1,mid-1,p1,best);
	computeDP(i,mid+1,l2,best,p2);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 1; i <= n; i++) scanf("%lf",&arreglo[i]);
	for(int i = 1; i <= n; i++) dp[1][i] = costo(1,i);
	for(int i = 2; i <= k; i++) computeDP(i,1,n,1,n);
	//for(int i = 0; i <= k; i++)for(int j = 0; j <= n; j++)cout << i << " " << j << " " << dp[i][j] << endl;
	printf("%lf\n",dp[k][n]);
}
