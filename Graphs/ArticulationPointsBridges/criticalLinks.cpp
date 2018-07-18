//796 - Critical Links
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<int> vi;

vector<ii> bridges;
vector<vi> grafo;

vi dfs_low,dfs_num,dfs_parent,articulation_vertex;
int n,dfsRoot,rootChildren,dfsNumberCounter;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int i = 0; i < (int)grafo[u].size(); i++){
		int v = grafo[u][i];
		if(dfs_num[v] == -1){
			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;

			dfs(v);

			if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = true;
			if(dfs_low[v] > dfs_num[u]){
				if(u < v) bridges.push_back({u,v});
				else bridges.push_back({v,u});
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}
}

int main(){
	optimizar_io;
	while(cin >> n){
		grafo.assign(n,vi());
		dfs_num.assign(n,-1);
		dfs_low.assign(n,0);
		dfs_parent.assign(n,0);
		articulation_vertex.assign(n,0);
		for(int i = 0; i < n; i++){
			int u,v,m; char p1,p2;
			cin >> u;
			cin >> p1 >> m >> p2;
			for(int j = 0; j < m; j++){
				cin >> v;
				grafo[u].push_back(v);
				grafo[v].push_back(u);
			}
		}
		dfsNumberCounter = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == -1){
				dfsRoot = i;
				rootChildren = 0;
				dfs(i);
			}
		}
		cout << bridges.size() << " critical links" << '\n';
		sort(bridges.begin(),bridges.end());
		for(int i = 0; i < bridges.size(); i++) cout << bridges[i].first << " - " << bridges[i].second << '\n';
		bridges.clear();
		cout << '\n';
	}
}
