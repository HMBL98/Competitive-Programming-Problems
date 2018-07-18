//5220 - Internet Bandwidth
#include <bits/stdc++.h>
using namespace std;

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
int n,c,caso;
int main(){
	optimizar_io;
	while(cin >> n,n){
		for(int i = 0; i <= n; i++)for(int j = 0; j <= n; j++) res[i][j] = 0;
		cin >> source >> sink >> c; source--; sink--;
		graph.assign(n,vi());
		for(int i = 0; i < c; i++){
			int x,y,ca; cin >> x >> y >> ca;
			x--; y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
			res[x][y] += ca;
			res[y][x] += ca;
		}
		mf = 0;
		while(1){
			f = 0;
			for(int i = 0; i <= n; i++) p[i] = -1;
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
		cout << "Network " << ++caso << "\n";
		cout << "The bandwidth is " << mf << ".\n\n";
	}
}
