#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vector<vi> grafo;
vi visitado;
int n,m;

int dfs(int u){
	visitado[u] = 1;
	int res = 1;
	for(int i = 0; i < grafo[u].size(); i++)
		if(visitado[grafo[u][i]] == -1) res += dfs(grafo[u][i]);
	return res;
}

int main(){
	optimizar_io;
	cin >> n >> m;
	grafo.assign(n+1,vi());
	visitado.assign(n+1,-1);
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
	vi resultados;
	for(int i = 1; i <= n; i++) if(visitado[i] == -1){
		int res = dfs(i);
		resultados.push_back(res);
	}
	long long res = 0;
	for(int i = 0; i < resultados.size()-1; i++){
		long long tmp = 0;
		for(int j = i+1; j < resultados.size(); j++){
			tmp += resultados[i]*resultados[j];
		}
		res += tmp;
	}
	cout << res << '\n';
}
