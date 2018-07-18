#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define MAX 150+10
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n,valores[MAX];
unordered_map<string,int> vistos;

// abacaba
vii palindromos(int s,string cadena){
	vii indices;
	for(int i = 0; i <= cadena.size()-s; i++){
		bool palindromo = true;
		int fin = i+s-1;
		for(int j = i; j <= (i+fin)/2; j++,fin--){
			if(cadena[j] != cadena[fin]){palindromo = false;break;}
		}
		if(palindromo) indices.push_back({i,i+s-1});
	}
	return indices;
}
int dp(string cadena){
	cout << cadena << endl;
	if(cadena.size() == 0) return 0;
	if(vistos.find(cadena) != vistos.end()) return vistos[cadena];
	int res = 0;
	for(int i = 1; i <= cadena.size(); i++){
		if(valores[i] != -1){
			vii pals = palindromos(i,cadena);
			for(ii j : pals){
				string nueva = ""+cadena.substr(0,j.first)+cadena.substr(j.second+1,cadena.size()-j.second);
				res = max(res,valores[i]+dp(nueva));
			}
		}
	}
	vistos[cadena] = res;
	return res;
}
int main(){
	optimizar_io;
	string cadena;
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> valores[i];
	cin >> cadena;
	int res = dp(cadena);
	cout << res << endl;
}
