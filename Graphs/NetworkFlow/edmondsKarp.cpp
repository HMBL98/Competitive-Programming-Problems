#include <bits/stdc++.h>
using namespace std;

// O(VE^2) Edmonds Karp’s algorithm
#define MAX 1000+10

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int res[MAX][MAX],p[MAX],source,sink,f,mf;
typedef vector<int> vi;
vector<vi> graph;

void augment(int v,int minEdge){
	if(v == source){ f = minEdge; return;}
	else if(p[v] != -1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}
int main(){
	optimizar_io;
	// set up 'graph',‘res’, ‘source’, and ‘sink’ with appropriate values
	graph.assign(MAX,vi());
	mf = 0;
	while(1){
		f = 0;
		for(int i = 0; i < MAX; i++) p[i] = -1;
		queue<int> q; q.push(source);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == sink) break;
			for(int i = 0; i < graph[u].size(); i++){
				int v = graph[u][i];
				if(res[u][v] > 0 && p[v] == -1){
					p[v] = u; q.push(v);
				}
			}
		}
		augment(sink,1<<20);
		if(f == 0)break;
		mf += f;
	}
	cout << mf << "\n";
}
