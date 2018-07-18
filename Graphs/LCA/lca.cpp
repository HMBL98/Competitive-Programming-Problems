#include <bits/stdc++.h>
using namespace std;

#define MAXV 100000+10
#define LOGV 30

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> graph;

int seen[MAXV],depth[MAXV],parent[LOGV][MAXV],weigth[LOGV][MAXV],N,M,Q;

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < graph[u].size(); i++){
		ii v = graph[u][i];
		if(!seen[v.first]){
			parent[0][v.first] = u;
			weigth[0][v.first] = v.second;
			depth[v.first] = depth[u]+1;
			dfs(v.first);
		}
	}
}
void pre(){
	dfs(0);
	for(int i = 1; i < LOGV; i++){
		for(int j = 0; j < N; j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
			weigth[i][j] = max(weigth[i-1][j],weigth[i-1][parent[i-1][j]]);
		}
	}
}
int getParent(int u,int k,int &maxi){
	for(int i = 0; i < LOGV; i++){
		if(k&1){
			maxi = max(maxi,weigth[i][u]);
			u = parent[i][u];
		}
		k >>= 1;
	}
	return u;
}
int lca(int u,int v){
	int maxi = 0;
	if(depth[u] > depth[v]){
		u = getParent(u,depth[u]-depth[v],maxi);
	}else if(depth[v] > depth[u]){
		v = getParent(v,depth[v]-depth[u],maxi);
	}
	if(u == v)return u;
	//if(u == v)return maxi;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			maxi = max(maxi,max(weigth[i][u],weigth[i][v]));
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
	//maxi = max(max(weigth[0][u],maxi),weigth[0][v]);
	//return maxi;
}
int main(){
	cin >> N >> M;
	graph.assign(N,vii());
	for(int i = 0; i < M; i++){
		int x,y,c; cin >> x >> y >> c;
		graph[x].push_back({y,c});
		graph[y].push_back({x,c});
	}
	pre();
	cin >> Q;
	while(Q--){
		int u,v;
		cin >> u >> v;
		cout << lca(u,v) << "\n";
	}
}
