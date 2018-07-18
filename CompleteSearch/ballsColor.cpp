#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int t;
string cadena;
int main(){
	optimizar_io;
	cin >> t;
	while(t--){
		cin >> cadena;
		int rojoDerecha;
		int verdeIzquierda = -1;
		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] == 'R') rojoDerecha = i;
			if(verdeIzquierda == -1 && cadena[i] == 'G') verdeIzquierda = i;
		}
		int minimoR = 0;
		int minimoV = 0;
		for(int i = rojoDerecha; i >= 0; i--){
			if(cadena[i] == 'G') minimoR++;
		}
		for(int i = verdeIzquierda; i < cadena.size(); i++){
			if(cadena[i] == 'R') minimoV++;
		}
		cout << min(minimoV,minimoR) << endl;
	}
}
