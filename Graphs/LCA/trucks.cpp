#include <bits/stdc++.h>
using namespace std;

#define MAXV 100000+10
#define LOGV 30

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector< pair<int,ii> > graph1;
vector<vii> graph2;

int p[MAXV],_rank[MAXV],setSize[MAXV],numSets;
void makeSet(int s){
	numSets = s;
	for(int i = 0; i < s; i++){
		p[i] = i;
		_rank[i] = 0;
		setSize[i] = 1;
	}
}
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i,int j){ return findSet(i) == findSet(j);}
void unionSet(int i,int j){
	if(!isSameSet(i,j)){
		numSets--;
		int x = findSet(i), y = findSet(j);
		if(_rank[x] > _rank[y]){ p[y] = x; setSize[x] += setSize[y];}
		else{
			p[x] = y; setSize[y] += setSize[x];
			if(_rank[x] == _rank[y]) _rank[y]++;
		}
	}
}
int sizeOfSet(int i){ return setSize[findSet(i)];}


int seen[MAXV],depth[MAXV],parent[LOGV][MAXV],weigth[LOGV][MAXV],N,M,S;

void dfs(int u){
	seen[u] = 1;
	for(int i = 0; i < graph2[u].size(); i++){
		ii v = graph2[u][i];
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
			weigth[i][j] = min(weigth[i-1][j],weigth[i-1][parent[i-1][j]]);
		}
	}
}
int getParent(int u,int k,int &maxi){
	for(int i = 0; i < LOGV; i++){
		if(k&1){
			maxi = min(maxi,weigth[i][u]);
			u = parent[i][u];
		}
		k >>= 1;
	}
	return u;
}
int lca(int u,int v){
	int maxi = 1<<20;
	if(depth[u] > depth[v]){
		u = getParent(u,depth[u]-depth[v],maxi);
	}else if(depth[v] > depth[u]){
		v = getParent(v,depth[v]-depth[u],maxi);
	}
	//if(u == v)return u;
	if(u == v)return maxi;
	for(int i = LOGV-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			maxi = min(maxi,min(weigth[i][u],weigth[i][v]));
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	//return parent[0][u];
	maxi = min(min(weigth[0][u],maxi),weigth[0][v]);
	return maxi;
}
int main(){
	while(cin >> N >> M >> S){
		for(int i = 0; i < M; i++){
			int x,y,c; cin >> x >> y >> c;
			x--; y--;
			graph1.push_back({c,{x,y}});
		}
		graph2.assign(N,vii());
		makeSet(N);
		sort(graph1.begin(),graph1.end());
		for(int i = graph1.size()-1; i >= 0; i--){
			pair<int,ii> act = graph1[i];
			if(!isSameSet(act.second.first,act.second.second)){
				unionSet(act.second.first,act.second.second);
				graph2[act.second.first].push_back({act.second.second,act.first});
				graph2[act.second.second].push_back({act.second.first,act.first});
			}

		}
		pre();
		while(S--){
			int u,v; cin >> u >> v; u--; v--;
			cout << lca(u,v) << "\n";
		}
		graph1.clear();
		for(int i = 0; i < N; i++){
			seen[i] = 0;
			depth[i] = 0;
		}
	}
}
