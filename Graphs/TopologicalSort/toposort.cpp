#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vector<vi> grafo;
vi ordenamiento;
vi visitado;

int n,m;
bool hay_ciclo;


void dfs(int u){
	visitado[u] = 1;
	for(int i = grafo[u].size()-1; i >= 0; i--){
		if(visitado[grafo[u][i]] == -1) dfs(grafo[u][i]);
		if(visitado[u] == visitado[grafo[u][i]]) hay_ciclo = true;
	}
	visitado[u] = 2;
	ordenamiento.push_back(u);
}
int main(){
	optimizar_io;
	cin >> n >> m;
	grafo.assign(n+1,vi());
	visitado.assign(n+1,-1);
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		grafo[x].push_back(y);
	}
	for(int i = 1; i <= n; i++)sort(grafo[i].begin(),grafo[i].end());
	hay_ciclo = false;
	for(int i = n; i >= 1; i--)if(visitado[i] == -1) dfs(i);
	if(!hay_ciclo){
		for(int i = ordenamiento.size()-1; i >= 0; i--) cout << ordenamiento[i] << " ";
		cout << endl;
	}else{
		cout << "Sandro fails." << endl;
	}
}
