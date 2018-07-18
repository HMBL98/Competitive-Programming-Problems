#include <bits/stdc++.h>
using namespace std;

#define MAX 1000+10
int N;

int memo[MAX][MAX];

bool esPalindromo[MAX][MAX];

void palindromos(string cadena){
	for(int i = cadena.size()-1; i >= 0; i--)
		for(int j = i; j < cadena.size(); j++)
			if(i == j) esPalindromo[i][j] = true;
			else if(cadena[i] == cadena[j])
				esPalindromo[i][j] = ((j-i == 1) ? true : esPalindromo[i+1][j-1]);
			else
				esPalindromo[i][j] = false;
}
int dp(int i,int j){
	if(i == j || esPalindromo[i][j]) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	int res = 1e6;
	for(int k = i; k <= j-1; k++){
		res = min(res,1+dp(i,k)+dp(k+1,j));
	}
	memo[i][j] = res;
	return res;
}
int main(){
	string cadena;
	cin >> N;
	while(N--){
		cin >> cadena;
		palindromos(cadena);
		memset(memo,-1,sizeof memo);
		int res = dp(0,cadena.size()-1);
		cout << res+1 << endl;
	}

}
