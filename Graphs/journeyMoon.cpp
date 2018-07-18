//Journey to the Moon hackerrank
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vector<vi> grafo;
vi visitado;
int n,p;

int dfs(int u){
	visitado[u] = 1;
	int res = 1;
	for(int i = 0; i < grafo[u].size(); i++)
		if(visitado[grafo[u][i]] == -1) res += dfs(grafo[u][i]);
	return res;
}

int main(){
	optimizar_io;
	cin >> n >> p;
	grafo.assign(n,vi());
	visitado.assign(n,-1);
	for(int i = 0;  i < p; i++){
		int u,v; cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	vector<long long> res;
	vector<long long> sumas;
	for(int i = 0; i < n; i++) if(visitado[i] == -1){
		int tmp = dfs(i);
		res.push_back(tmp);
		if(sumas.size() == 0) sumas.push_back(tmp);
		else sumas.push_back(tmp+sumas[sumas.size()-1]);

	}
	long long resultado = 0;
	for(int i = 0; i < res.size()-1; i++){
		resultado += res[i]*(sumas[sumas.size()-1]-sumas[i]);
	}
	cout << resultado << '\n';
}

