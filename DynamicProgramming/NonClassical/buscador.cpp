#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

string principal;

int lcs(string a,string b){
	int n1 = a.size();
	int n2 = b.size();
	int dp[n1+1][n2+1];
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(a[i-1] == b[j-1]){
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
				}
			}
		}
	}
	return dp[n1][n2];
}

int main(){
	optimizar_io;
	int p;
	cin >> principal;
	cin >> p;

 	string secundaria;
	int maxima = -1;
	string resultado;
	for(int i = 0; i < p; i++){
		cin >> secundaria;
		int res = lcs(principal,secundaria);
		if(res >= maxima){
			if(res == maxima){
				resultado = (secundaria.size() < resultado.size()) ? secundaria : resultado;
			}else{;
				resultado = secundaria;
			}
			maxima = res;
		}
	}
	cout << resultado << endl;
}
