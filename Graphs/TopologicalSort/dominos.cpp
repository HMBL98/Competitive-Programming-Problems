#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitado,ord;

int t,n,m;

void dfs(int u){
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++)if(visitado[grafo[u][i]] == -1) dfs(grafo[u][i]);
	ord.push_back(u);
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
		}
		for(int i = 1; i <= n; i++)if(visitado[i] == -1) dfs(i);
		int res = 0;
		visitado.assign(n+1,-1);
		for(int i = ord.size()-1; i >= 0; i--)if(visitado[ord[i]] == -1){res++;dfs(ord[i]);}
		cout << res << "\n";
		ord.clear();
	}
}
