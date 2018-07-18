#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int t,n;
int numeros[MAX];
//int minimo;

int memo[50000+10][100];
/*void backtrack(int uno,int dos,int pos){
	if(pos == n){
		//cout << uno << " " << dos << endl;
		minimo = min(minimo,abs(dos-uno));
		return;
	}
	backtrack(uno+numeros[pos],dos,pos+1);
	backtrack(uno,dos+numeros[pos],pos+1);
}*/
int dp(int total,int pos){
	if(pos == n)return total;
	if(memo[total][pos] != -1) return memo[total][pos];
	int a = 1e6,b = 1e6;
	if(numeros[pos] <= total) a = dp(total-numeros[pos],pos+1);
	b = dp(total,pos+1);
	memo[total][pos] = min(a,b);
	return memo[total][pos];
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(memo,-1,sizeof memo);
		int minimo;
		scanf("%d",&n);
		int promedio = 0;
		int total = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&numeros[i]);
			promedio += numeros[i];
			total += numeros[i];
		}
		promedio /= 2;
		minimo = dp(promedio,0);
		int primero = promedio-minimo;
		int segundo = total-primero;
		printf("%d\n",abs(segundo-primero));

	}
}
