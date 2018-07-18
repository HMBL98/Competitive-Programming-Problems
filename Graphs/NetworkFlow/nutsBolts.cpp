#include <bits/stdc++.h>
using namespace std;

#define MAX 1000+10
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
int res[MAX][MAX],p[MAX],t,bolts,nuts,source,sink,f,mf,caseno;
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
	cin >> t;
	while(t--){
		cin >> bolts >> nuts;
		source = 0; sink = bolts+nuts+1;
		for(int i = 0; i <= bolts+nuts+2; i++)for(int j = 0; j <= bolts+nuts+2; j++) res[i][j] = 0;
		graph.assign(sink+1,vi());
		for(int i = 1; i <= bolts; i++) for(int j = bolts+1; j <= bolts+nuts; j++){
			int tmp; cin >> tmp;
			if(tmp){
				res[i][j] = 1;
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
		for(int i = 1; i <= bolts; i++){
			res[0][i] = 1;
			graph[0].push_back(i);
			graph[i].push_back(0);
		}
		for(int i = bolts+1; i <= bolts+nuts; i++){
			res[i][sink] = 1;
			graph[i].push_back(sink);
			graph[sink].push_back(i);
		}
		mf = 0;
		while(1){
			f = 0;
			for(int i = 0; i <= bolts+nuts+1; i++)p[i] = -1;
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
		cout << "Case " << ++caseno << ": a maximum of " << mf << " nuts and bolts can be fitted together\n";
	}
}
