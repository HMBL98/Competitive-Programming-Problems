//VK Cup 2017 - Qualification 2
//C. Online Courses In BSU
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
vector<vi> grafo;
vi visitados;
vi ordenamiento;
vi objetivos;
int n,k;


bool ciclo;
void dfs(int u){
	visitados[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(visitados[grafo[u][i]] == -1) dfs(grafo[u][i]);
		if(visitados[grafo[u][i]] == visitados[u]) ciclo = true;
	}
	ordenamiento.push_back(u);
	visitados[u] = 2;
}
int main(){
	optimizar_io;
	cin >> n >> k;
	grafo.assign(n+1,vi());
	visitados.assign(n+1,-1);
	for(int i = 0; i < k; i++){int tmp;cin >> tmp; objetivos.push_back(tmp);}
	for(int i = 1; i <= n; i++){
		int t; cin >> t;
		for(int j = 0; j < t; j++){
			int tmp; cin >> tmp;
			grafo[i].push_back(tmp);
		}
	}
	ciclo = false;
	for(int i = 0; i < objetivos.size(); i++)  if(visitados[objetivos[i]] == -1) dfs(objetivos[i]);
	if(!ciclo){
		cout << ordenamiento.size() << endl;
		for(int i = 0; i < ordenamiento.size(); i++){
			cout << ordenamiento[i] << " ";
		}
		cout << '\n';
	}else cout << -1 << '\n';
}

