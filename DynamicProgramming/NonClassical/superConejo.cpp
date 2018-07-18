#include <bits/stdc++.h>
using namespace std;
#define MAX 1000+10
bool status = false;

int n,m,arreglo[MAX][MAX],memo[MAX][MAX];

bool posible(int i,int j){
	if(i < 0 || i >= n || j < 0 || j >= m || arreglo[i][j] == -1) return 0;
	return 1;
}
int dp(int i,int j){
	if(!posible(i,j)) return -(1<<30);
	if(i == n-1 && j == m-1){
		status = true;
		return (arreglo[n-1][m-1] == -2) ? -1 : arreglo[n-1][m-1];
	}
	if(memo[i][j]) return memo[i][j];
	int uno = -(1<<30),dos = -(1<<30),tres = -(1<<30),res = -(1<<30);
	int suma = (arreglo[i][j] == -2) ? -1 : arreglo[i][j];

	if(posible(i+2,j-1)){
		uno = suma+dp(i+2,j-1);
		if(uno < 0) uno = 0; 
	}
	if(posible(i-1,j+2)){
		dos = suma+dp(i-1,j+2);
		if(dos < 0) dos = 0;
	}
	if(posible(i+1,j+1)){
		tres = suma+dp(i+1,j+1);
		if(tres < 0) tres = 0;
	}
	res = max(res,uno); res = max(res,dos); res = max(res,tres);
	memo[i][j] = res;
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arreglo[i][j];
	int res = dp(0,0);
	if(!status)cout << -1 << endl;
	else cout << res << endl;
}

