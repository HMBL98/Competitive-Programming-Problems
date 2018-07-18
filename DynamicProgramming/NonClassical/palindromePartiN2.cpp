#include <bits/stdc++.h>
using namespace std;

#define MAX 1000+10
int N;

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
int dp(string cadena){
	int n = cadena.size();
	int memo[n];
	for(int i = n-1; i >= 0; i--){
		memo[i] = INT_MAX;
		if(esPalindromo[i][n-1]){
			memo[i] = 0;
		}else{
			for(int j = n-2; j >= i; j--)
				if(esPalindromo[i][j])
					memo[i] = min(memo[i],1+memo[j+1]);
		}
	}
	return memo[0];
}
int main(){
	string cadena;
	cin >> N;
	while(N--){
		cin >> cadena;
		palindromos(cadena);
		int res = dp(cadena);
		cout << res+1 << endl;
	}

}
