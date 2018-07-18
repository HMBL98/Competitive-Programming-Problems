#include <bits/stdc++.h>
using namespace std;

// O(VE^2) Edmonds Karp’s algorithm
#define MAX 5000+10

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
int F,P;

int main(){
	optimizar_io;
	cin >> F >> P;
	source = 0; sink = F*2;
	graph.assign(sink+1,vi());
	for(int i = 0; i < 10; i++){
		int tmp; cin >> tmp;
		graph[source].push_back(tmp*2-1);
		graph[tmp*2-1].push_back(source);
		res[source][tmp*2-1] = 1<<25;
		res[tmp*2-1][source] = 1<<25;
		//cout << source << " " << tmp*2-1 << "\n";
	}
	for(int i = 1; i <= 2*F; i+=2){
		int tmp; cin >> tmp;
		graph[i].push_back(i+1);
		graph[i+1].push_back(i);
		res[i][i+1] = tmp;
		res[i+1][i] = 0;
		//cout << i << " " << i+1 << "\n";
	}
	for(int i = 0; i < P; i++){
		int x,y,c; cin >> x >> y >> c;
		graph[2*x].push_back(2*y-1);
		graph[2*y-1].push_back(2*x);
		res[2*x][2*y-1] = c;
		res[2*y-1][2*x] = 0;
		//cout << 2*x << " " << 2*y-1 << "\n";
	}
	mf = 0;
	while(1){
		f = 0;
		for(int i = 0; i <= sink; i++) p[i] = -1;
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
		augment(sink,1<<25);
		if(f == 0)break;
		mf += f;
	}
	if(mf >= 100000000) cout << 100000000 << "\n";
	else cout << mf << "\n";
}
