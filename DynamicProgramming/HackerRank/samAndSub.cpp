#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
string n;
map<string,int> vistos;

int dp(string cadena,int pos){
	if(vistos.find(cadena) != vistos.end()) return 0;
	int res = 0;
	for(int i = pos; i <= cadena.size(); i++){
		//res += stoi(cadena.substr(0,i))+ dp(cadena.substr(i,cadena.size()-i),i);
		res += stoll(cadena.substr(0,i))%MOD;
		res += dp(cadena.substr(i,cadena.size()-i),i)%MOD;
		res = res%MOD;
	}
	vistos[cadena] = res;
	return res;
}
int main(){
	cin >> n;
	int res = dp(n,1);
	cout << res%MOD<< endl;
}
