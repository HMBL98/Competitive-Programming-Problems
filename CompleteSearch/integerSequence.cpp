#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

vector<int> coeficientes;
int C,n,d,k;
ll polinomio(int x){
	ll res = 0;
	for(int i = 0; i <= n; i++){
		//cout << coeficientes[i] << "*" << pow(x,i) << endl;
		res += coeficientes[i]*pow(x,i);
	}
	return res;
}
int main(){
	optimizar_io;
	coeficientes.assign(21,0);
	cin >> C;
	while(C--){
		cin >> n;
		for(int i = 0; i <= n; i++){
			cin >> coeficientes[i];
		}
		cin >> d;
		cin >> k;
		int res = d;
		int pos = 1;
		int i = 2;
		while(k > res){
			res += d*i;
			pos++;
			i++;
		}
		cout << polinomio(pos) << endl;
	}
}
