#include <bits/stdc++.h>
using namespace std;

vector<int> grado;
vector<int> visitados;
int T;
string cadena;

void dfs(int pos,int nodo){
	visitados[nodo] = 1;
	int cuantos = 1;
	for(int i = pos+1; i < cadena.size(); i++){
		if(cadena[pos] == cadena[i]) break;
		if(visitados[cadena[i]-'A'] == -1) cuantos++,dfs(i,cadena[i]-'A');
	}
	grado[nodo] = cuantos;
}

int main(){
	cin >> T;
	int caso = 0;
	while(T--){
		grado.assign(27,0);
		visitados.assign(27,-1);
		cin >> cadena;
		dfs(0,cadena[0]-'A');
		cout << "Case " << ++caso << "\n";
		grado[cadena[0]-'A']--;
		sort(cadena.begin(),cadena.end());
		for(int i = 0; i < cadena.size(); i+=2){
			cout << cadena[i] << " = " << grado[cadena[i]-'A'] << "\n";
		}
	}

}
