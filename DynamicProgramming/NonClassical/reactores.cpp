#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int n,k;
int arreglo[17][17];
string cadena;
int memo[65536+1];
int dp(int prendidos){
	if(memo[prendidos] != -1) return memo[prendidos];
	int cuenta = 0;
	for(int i = 0; i < n; i++) if(prendidos&(1<<i))cuenta++;
	if(cuenta == k) return 0;

	int minimo = 1e6;
	for(int i = 0; i < n; i++){
		if(!(prendidos&(1<<i))){
			for(int j = 0; j < n; j++){
				if(i != j && prendidos&(1<<j)){
					int nuevo = arreglo[j][i]+dp(prendidos|(1<<i));
					minimo = min(minimo,nuevo);
				}
			}
		}
	}
	memo[prendidos] = minimo;
	return memo[prendidos];
}

int main(){
	optimizar_io;
	memset(memo,-1,sizeof memo);
	cin >> n >> k;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin >> arreglo[i][j];
	cin >> cadena;
	int prendidos = 0;
	for(int i = 0; i < cadena.size(); i++)
		if(cadena[i] == 'Y') prendidos |= 1<<i;
	//cout << prendidos << endl;
	int res = dp(prendidos);
	cout << res << endl;
}
