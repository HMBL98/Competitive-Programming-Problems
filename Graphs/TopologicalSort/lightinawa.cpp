//11770 - Lighting Away
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitado,ord;
void dfs(int u,int caso){
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++) if(visitado[grafo[u][i]] == -1) dfs(grafo[u][i],caso);
	if(caso) ord.push_back(u);
}

int t,n,m,caso;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		for(int i = 0; i < m; i++){int x,y; cin >> x >> y; grafo[x].push_back(y);}
		for(int i = 1; i <= n; i++)if(visitado[i] == -1) dfs(i,1);
		visitado.assign(n+1,-1);
		int res = 0;
		for(int i = ord.size()-1; i >= 0; i--)if(visitado[ord[i]] == -1){ res++; dfs(ord[i],0);}
		cout << "Case " << ++caso << ": " << res << endl;
		ord.clear();
	}
}
