#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitado,valor;

int t,n,m,fin;

int dfs(int u){
	visitado[u] = 1;
	int next = -1;
	int maximo = -1;

	for(int i = 0; i < grafo[u].size(); i++){
		if(visitado[grafo[u][i]] == -1){
			if(valor[grafo[u][i]] > maximo){
				next = grafo[u][i];
				maximo = valor[grafo[u][i]];
			}
		}
	}
	if(grafo[u].size() == 0){
		fin = u;
		return 0;
	}
	return (maximo+dfs(next));
}

int main(){
	int caso = 0;
	cin >> t;
	while(t--){
		cin >> n >> m;
		grafo.assign(n,vi());
		visitado.assign(n,-1);
		valor.assign(n,0);
		for(int i = 0; i < n; i++) cin >> valor[i];
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
		}
		int res = dfs(0);
		cout << "Case " << ++caso << ": " <<  res << " " << fin << '\n';
	}
}
