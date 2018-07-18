#include <bits/stdc++.h>
using namespace std;
int n,m;
struct fraccion{
	int numerador;
	int denominador;
};
void backtrack(fraccion izq,fraccion mit,fraccion der){
	double a = (double)mit.numerador/(double)mit.denominador;
	double target = (double)n/(double)m;
	if(n == mit.numerador && m == mit.denominador){
		cout << endl;
		return;
	}else if(target > a){
		cout << "R";
		izq = mit;
		mit.numerador += der.numerador;
		mit.denominador += der.denominador;
		backtrack(izq,mit,der);
	}else{
		cout << "L";
		der = mit;
		mit.numerador += izq.numerador;
		mit.denominador += izq.denominador;
		backtrack(izq,mit,der);
	}
}
int main(){
	while(cin >> n >> m){
		if(n == 1 && m == 1) break;
		fraccion izq,mit,der;
		izq.numerador = 0; izq.denominador = 1;
		mit.numerador = 1; mit.denominador = 1;
		der.numerador = 1; der.denominador = 0;
		backtrack(izq,mit,der);
	}
}
