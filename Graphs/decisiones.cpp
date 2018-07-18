#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;

vector<vi> grafo;
vi valor,visitado;
int n,m;
int fin;

int dfs(int u){
	visitado[u] = 1;
	int next = -1;
	int mayor = -1;
	int res = valor[u];
	for(int i = 0; i < (int)grafo[u].size(); i++){
		if(visitado[grafo[u][i]] == -1 && valor[grafo[u][i]] > mayor ){
			next = grafo[u][i];
			mayor = valor[grafo[u][i]];
		}
	}
	if(next != -1) res += dfs(next);
	else fin = u;
	return res;
}
int main(){
	optimizar_io;
	cin >> n >> m;
	
	visitado.assign(n+1,-1);
	grafo.assign(n+1,vi());
	valor.assign(n+1,0);
	for(int i = 0; i < n; i++) cin >> valor[i];
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		grafo[x].push_back(y);
	}
	int res = dfs(0);
	cout << res << " " << fin << "\n";
}
