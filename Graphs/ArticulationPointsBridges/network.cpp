#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 500

typedef vector<int> vi;
vector<vi> graph;

int low[MAX],num[MAX],p[MAX],articulation_vertex[MAX];
int n,counter,dfsRoot,rootChildren;

void dfs(int u){
	low[u] = num[u] = counter++;
	for(int i = 0; i < (int)graph[i].size(); i++){
		int v = graph[u][i];
		if(num[v] == -1){
			p[v] = u;
			if(u == dfsRoot) rootChildren++;

			dfs(v);

			if(low[v] >= num[u]) articulation_vertex[u] = true;
			//if(low[v] > num[u]) cout << "Edge " << u << " " << v << " is a bridge" << "\n";
			low[u] = min(low[u],low[v]);
		}else if(v != p[u]){ // a back edge and not direct cycle
			low[u] = min(low[u], num[v]); // update dfs_low[u]
		}
	}
}

int main(){
	optimizar_io;
	while(cin >> n, n){
		graph.assign(n+1,vi());
		counter = rootChildren = dfsRoot = 0; 
		for(int i = 0; i < MAX; i++){
			num[i] = -1;
			low[i] = 0;
			p[i] = 0;
			articulation_vertex[i] = 0;
		}
		string s;
		cin.clear();
		cin.ignore();
		while(getline(cin,s)){
			if(s[0] == '0') break;
			int u,v;
			stringstream ss(s); ss >> u;
			while(ss >> v) graph[u].push_back(v),graph[v].push_back(u);
		}
		dfsRoot = 1;
		dfs(1);
		int res = 0;
		//cout << rootChildren << endl;
		for(int i = 1; i <= n; i++)if(articulation_vertex[i]) res++;
		if(rootChildren < 2) res--;
		cout << res << '\n';
	}
}
