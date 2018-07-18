#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
string cadena;
int caracteres;

int sub(char c){
	int mayor = -1;
	int a = -1,b = -1;
	for(int i = 0; i < cadena.size(); i++){
		if(cadena[i] == c){
			if(a == -1){
				a = i;
			}
			if(a != -1 && b == -1){
				b = i;
				mayor = (b-a > mayor) ? b-a : mayor;
				a = b;
				b = -1;
			}
		}
	}
	int size = cadena.size();
	return (mayor != 0) ? mayor : max(a+1,size-a);
}
int main(){
	optimizar_io;
	caracteres = 0;
	cin >> cadena;
	for(int i = 0; i < cadena.size(); i++){
		caracteres |= 1 << cadena[i]-'a';
	}
	int minimo = 1000000;
	for(int i = 0; i < 28; i++){
		if(caracteres & (1<<i)){
			minimo = min(minimo,sub('a'+i));
		}
	}
	cout << minimo << endl;
}
