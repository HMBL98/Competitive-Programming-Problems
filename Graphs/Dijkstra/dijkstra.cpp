#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> graph;

int dist[MAX],p[MAX],n,m,src,dest;

void path(int u){
	if(u == p[u]) cout << u << "\n";
	else{
		cout << u << " ";
		path(p[u]);
	}
}

int main(){
	cin >> n >> m >> src >> dest;
	graph.assign(n,vii());
	for(int i = 0; i < m; i++){
		int x,y,c; cin >> x >> y >> c;
		graph[x].push_back({y,c});
		graph[y].push_back({x,c});
	}
	for(int i = 0; i < MAX; i++) dist[i] = 1<<20;
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	dist[src] = 0; p[src] = src; pq.push(ii(0,src));
	while(!pq.empty()){
		ii act = pq.top(); pq.pop();
		int d = act.first, u = act.second;
		if(d > dist[u]) continue;
		for(int i = 0; i < (int)graph[u].size(); i++){
			ii v = graph[u][i];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first] = dist[u]+v.second;
				p[v.first] = u;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
	path(dest);
	if(dist[dest] == 1<<20) cout << -1 << "\n";
	else cout << dist[dest] << "\n";
}
