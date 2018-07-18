#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int T,p,q;
long long menor,mayor;

void backtrack(string numero){
	if(numero.size() == p){
		long long n = stoll(numero);
		long long dos = pow(2,q);
		if(n%dos == 0){
			menor = (n < menor) ? n : menor;
			mayor = (n > mayor) ? n : mayor;
		}
		return;
	}else{
		string tmp;
		for(int i = 1; i <= 2; i++){
			tmp = numero;
			if(i == 1){
				tmp += "1";
			}else{
				tmp += "2";
			}
			backtrack(tmp);
		}
	}
}
int main(){
	optimizar_io;
	int caso = 0;
	cin >> T;
	while(T--){
		menor = LONG_MAX;
		mayor = -1;
		cin >> p >> q;
		string tmp = "";
		backtrack(tmp);
		cout << "Case " << ++caso << ": ";
		if(menor == LONG_MAX && mayor == -1){
			cout << "impossible" << endl;
		}else{
			if(menor == mayor){
				cout << menor << endl;
			}else{
				cout << menor << " " << mayor << endl;
			}
		}
	}
}
