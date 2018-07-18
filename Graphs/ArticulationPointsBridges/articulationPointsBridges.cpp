#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int low[MAX],num[MAX],p[MAX],articulation_vertex[MAX];
vector<vii> graph;

int counter,rootChildren,dfsRoot,V;


void dfs(int u){
	low[u] = num[u] = counter++; // dfs_low[u] <= dfs_num[u]
	for(int j = 0; j < (int)graph[u].size(); j++){
		ii v = graph[u][j];
		if(num[v.first] == -1){ // a tree edge
			p[v.first] = u;
			if(u == dfsRoot) rootChildren++; // special case if u is a root

			dfs(v.first);

			if(low[v.first] >= num[u]) // for articulation point
				articulation_vertex[u] = true; // store this information first
			if(low[v.first] > num[u]) // for bridge
				printf(" Edge (%d, %d) is a bridge\n", u, v.first);
			low[u] = min(low[u],low[v.first]); // update dfs_low[u]
		}else if(v.first != p[u]) // a back edge and not direct cycle
			low[u] = min(low[u],num[v.first]); // update dfs_low[u]
	}
}
// inside int main()
int main(){
	counter = 0; memset(num,-1,sizeof num); memset(low,0,sizeof low); 
	memset(p,0,sizeof p); memset(articulation_vertex,0,sizeof articulation_vertex);
	printf("Bridges:\n");
	for (int i = 0; i < V; i++)
		if (num[i] == -1){
			dfsRoot = i; rootChildren = 0; dfs(i);
			articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case
	printf("Articulation Points:\n");
	for (int i = 0; i < V; i++)
		if (articulation_vertex[i])
			printf(" Vertex %d\n", i);
}
