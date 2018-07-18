#include <bits/stdc++.h>
using namespace std;

#define MAXV 100000+10
#define LOGV 30

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> graph;

int seen[MAXV],depth[MAXV],parent[LOGV][MAXV],weigth[LOGV][MAXV],weigth2[LOGV][MAXV],N,M,Q;

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < graph[u].size(); i++){
		ii v = graph[u][i];
		if(!seen[v.first]){
			parent[0][v.first] = u;
			weigth[0][v.first] = v.second;
			weigth2[0][v.first] = v.second;
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
			weigth2[i][j] = min(weigth2[i-1][j],weigth2[i-1][parent[i-1][j]]);
		}
	}
}
int getParent(int u,int k,int &maxi,int &mini){
	for(int i = 0; i < LOGV; i++){
		if(k&1){
			maxi = max(maxi,weigth[i][u]);
			mini = min(mini,weigth2[i][u]);
			u = parent[i][u];
		}
		k >>= 1;
	}
	return u;
}
int lca(int u,int v,int opc){
	int maxi = 0;
	int mini = 1<<20;
	if(depth[u] > depth[v]){
		u = getParent(u,depth[u]-depth[v],maxi,mini);
	}else if(depth[v] > depth[u]){
		v = getParent(v,depth[v]-depth[u],maxi,mini);
	}
	//if(u == v)return u;
	if(u == v)return (opc) ? maxi : mini;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			maxi = max(maxi,max(weigth[i][u],weigth[i][v]));
			mini = min(mini,min(weigth2[i][u],weigth2[i][v]));
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	//return parent[0][u];
	if(opc){
		maxi = max(max(weigth[0][u],maxi),weigth[0][v]);
		return maxi;
	}else{
		mini = min(min(weigth2[0][u],mini),weigth2[0][v]);
		return mini;
	}
}
int main(){
	cin >> N;
	graph.assign(N,vii());
	for(int i = 0; i < N-1; i++){
		int x,y,c; cin >> x >> y >> c;
		x--; y--;
		graph[x].push_back({y,c});
		graph[y].push_back({x,c});
	}
	pre();
	cin >> Q;
	while(Q--){
		int u,v;
		cin >> u >> v;
		u--; v--;
		cout << lca(u,v,0) << " " << lca(u,v,1) << "\n";
	}
}
