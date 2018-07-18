#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
vector<vi> grafo;
vi visitados;
vi ordenamiento;
vector<string> vs;

bool ciclo;
int n;

void dfs(int u){
	visitados[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(visitados[grafo[u][i]] == -1) dfs(grafo[u][i]);
		if(visitados[grafo[u][i]] == visitados[u]) ciclo = true;
	}
	visitados[u] = 2;
	ordenamiento.push_back(u);

}
int main(){
	optimizar_io;
	cin >> n;
	grafo.assign(27,vi());
	visitados.assign(27,-1);
	for(int i = 0; i < n; i++){
		string tmp; cin >> tmp;
		vs.push_back(tmp);
	}
	bool status = false;
	if(n==1)status = true;
	for(int i = 0; i < n-1; i++){
		if(vs[i][0] == vs[i+1][0]){
			for(int j = 1; j < vs[i].size() && j < vs[i+1].size(); j++){
				if(vs[i][j] != vs[i+1][j]){ status = true;grafo[vs[i][j]-'a'].push_back(vs[i+1][j]-'a');break;}
			}
			if(!status){
				if(vs[i].size() < vs[i+1].size()) status = true;
				else status = false;
			}
		}else{
			status = true;
			grafo[vs[i][0]-'a'].push_back(vs[i+1][0]-'a');
		}
	}
	ciclo = false;
	for(int i = 0; i < 26; i++) if(visitados[i] == -1) dfs(i);
	if(!ciclo){
		if(!status) cout << "Impossible" << '\n';
		else{
			reverse(ordenamiento.begin(),ordenamiento.end());
			for(int i = 0; i < ordenamiento.size(); i++){
				char c = ordenamiento[i]+'a';
				cout << c;
			}
			cout << '\n';
		}
	}else cout << "Impossible" << '\n';
}
