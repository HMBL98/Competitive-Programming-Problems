#include <bits/stdc++.h>
using namespace std;


#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define MAXV 100000+10
#define LOGV 30

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> graph;

ll seen[MAXV],depth[MAXV],parent[LOGV][MAXV],dist[MAXV];

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < graph[u].size(); i++){
		ii v = graph[u][i];
		if(!seen[v.first]){
			depth[v.first] = depth[u]+1;
			parent[0][v.first] = u;
			dist[v.first] =  dist[u]+v.second;
			dfs(v.first);
		}
	}
}
int getParent(int u,int k){
	for(int i = 0; i < LOGV; i++){
		if(k&1) u = parent[i][u];
		k >>= 1;
	}
	return u;
}
int lca(int u,int v){
	if(depth[u] > depth[v]){
		u = getParent(u,depth[u]-depth[v]);
	}else if(depth[v] > depth[u]){
		v = getParent(v,depth[v]-depth[u]);
	}
	if(u == v) return u;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}

ll n,x,y,c,q;
int main(){
	optimizar_io;
	while(cin >> n,n){
		graph.assign(n,vii());
		for(int i = 0; i < n; i++){
			seen[i] = 0;
			depth[i] = 0;
			dist[i] = 0;
		}
		for(int i = 1; i <= n-1; i++){
			cin >> y >> c;
			graph[i].push_back({y,c});
			graph[y].push_back({i,c});
		}
		dfs(0);
		for(int i = 1; i < LOGV; i++){
			for(int j = 0; j < n; j++){
				parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}
		cin >> q;
		for(int i = 0; i < q; i++){
			if(i) cout << " ";
			cin >> x >> y;
			cout << dist[x]+dist[y]-2*dist[lca(x,y)];
		}
		cout << "\n";
	}

}
