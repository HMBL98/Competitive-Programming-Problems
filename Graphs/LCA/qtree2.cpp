#include <bits/stdc++.h>
using namespace std;

#define MAXV 100000+10
#define LOGV 30

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> graph;

int seen[MAXV],depth[MAXV],dist[MAXV],parent[LOGV][MAXV],T,N,M,Q;
vector<int> kth;

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < (int)graph[u].size(); i++){
		ii v = graph[u][i];
		if(!seen[v.first]){
			parent[0][v.first] = u;
			dist[v.first] = dist[u]+v.second;
			depth[v.first] = depth[u]+1;
			dfs(v.first);
		}
	}
}
void path(int u,int v,bool s){
	if(u == v){
		if(s) kth.push_back(u+1);
	}else{
		if(s) kth.push_back(u+1);
		path(parent[0][u],v,s);
		if(!s) kth.push_back(u+1);
	}
}
void pre(){
	dfs(0);
	for(int i = 1; i < LOGV; i++){
		for(int j = 0; j < N; j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
}
int getParent(int u,int k){
	for(int i = 0; i < LOGV; i++){
		if(k&1)u = parent[i][u];
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
	if(u == v)return u;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}
int main(){
	optimizar_io;
	cin >> T;
	while(T--){
		cin >> N;
		graph.assign(N,vii());
		for(int i = 0; i < N-1; i++){
			int x,y,c; cin >> x >> y >> c;
			x--; y--;
			graph[x].push_back({y,c});
			graph[y].push_back({x,c});
		}
		pre();
		while(true){
			string opc; cin >> opc;
			if(opc.compare("DIST") == 0){
				int x,y; cin >> x >> y;
				x--; y--;
				cout << dist[x]+dist[y]-2*dist[lca(x,y)] << "\n";
			}else if(opc.compare("KTH") == 0){
				int x,y,c; cin >> x >> y >> c;
				x--;y--;
				int tmp = lca(x,y);
				kth.clear();
				path(x,tmp,true);
				path(y,tmp,false);
				//for(int i = 0; i < kth.size(); i++) cout << kth[i] << " ";
				//cout << "\n";
				cout << kth[c-1] << "\n";
			}else break;
		}
		for(int i = 0; i < N; i++){
			seen[i] = depth[i] = dist[i] = 0;
		}
		cout << "\n";
	}

}
