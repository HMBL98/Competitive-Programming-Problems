#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitado,ordenamiento;
bool ciclo;
int n,m;


void dfs(int u){
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		if(visitado[grafo[u][i]] == -1) dfs(grafo[u][i]);
		else if(visitado[grafo[u][i]] == visitado[u]) ciclo = true;
	}
	visitado[u] = 2;
	ordenamiento.push_back(u);
}

int main(){
	while(cin >> n >> m,(n||m)){
		ciclo = false;
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
		}
		for(int i = 1; i <= n; i++) if(visitado[i] == -1) dfs(i);
		if(ciclo){
			cout << "IMPOSSIBLE\n";
		}else{
			for(int i = ordenamiento.size()-1; i >= 0; i--) cout << ordenamiento[i] << '\n';
		}
		ordenamiento.clear();
	}
}
