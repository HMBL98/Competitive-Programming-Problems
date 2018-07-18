// uva 200 - Rare Order
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi ordenamiento;
vi visitados;
vi usados;

void dfs(int u){
	visitados[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(visitados[grafo[u][i]] == -1) dfs(grafo[u][i]);
	}
	ordenamiento.push_back(u);
}
int main(){
	grafo.assign(30,vi());
	visitados.assign(30,-1);
	usados.assign(30,0);
	vector<string> cadenas;
	string cadena;
	while(cin >> cadena) if(cadena[0] == '#') break; else cadenas.push_back(cadena);
	/*for(int i = 0; i < cadenas.size(); i++){
		for(int j = 0; j < cadenas[i].size(); j++){
			usados[cadenas[i][j]-'A'] = 1;
		}
	}*/
	for(int i = 0; i < cadenas.size()-1; i++){
		if(cadenas[i][0] == cadenas[i+1][0]){
			for(int j = 0; j < cadenas[i].size() && j < cadenas[i+1].size(); j++){
				if(cadenas[i][j] != cadenas[i+1][j]) {
					grafo[cadenas[i][j]-'A'].push_back(cadenas[i+1][j]-'A');
					usados[cadenas[i][j]-'A'] = 1;
					usados[cadenas[i+1][j]-'A'] = 1;
					break;
				}
			}
		}else{
			grafo[cadenas[i][0]-'A'].push_back(cadenas[i+1][0]-'A');
			usados[cadenas[i][0]-'A'] = 1;
			usados[cadenas[i+1][0]-'A'] = 1;
		}
	}
	for(int i = 0; i < 26; i++) if(visitados[i] == -1)dfs(i);
	for(int i = ordenamiento.size()-1; i >= 0; i--){
		if(usados[ordenamiento[i]]){
			cout << (char)(ordenamiento[i]+'A');
		}
	}
	cout << '\n';
}
