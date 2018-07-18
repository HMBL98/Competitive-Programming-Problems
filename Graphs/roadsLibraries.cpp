// Hackerrank Roads and Libraries
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
vector<vi> grafo;
vector<int> visitados;

int q,n,m,c1,c2;


int dfs(int u){
	visitados[u] = 1;
	int res = 1;
	for(int i = 0; i < grafo[u].size(); i++)
		if(visitados[grafo[u][i]] == -1) res += dfs(grafo[u][i]);
	return res;
}
int main(){
	cin >> q;
	while(q--){
		cin >> n >> m >> c1 >> c2;
		grafo.assign(n+1,vi());
		visitados.assign(n+1,-1);
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		ll res = 0;
		for(int i = 1; i <= n; i++){
			if(visitados[i] == -1){
				int vertices = dfs(i);
				res += min((vertices-1)*c2+c1,vertices*c1);
			}
		}
		cout << res << endl;
	}
}

