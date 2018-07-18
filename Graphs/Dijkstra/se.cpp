#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> graph;

int dist[MAX],t,n,m,src,dest,caso;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m >> src >> dest;
		graph.assign(n,vii());
		for(int i = 0; i < m; i++){
			int x,y,c; cin >> x >> y >> c;
			graph[x].push_back({y,c});
			graph[y].push_back({x,c});
		}
		for(int i = 0; i < MAX; i++) dist[i] = 1<<20;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		dist[src] = 0; pq.push(ii(0,src));
		while(!pq.empty()){
			ii act = pq.top(); pq.pop();
			int d = act.first, u = act.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < (int)graph[u].size(); i++){
				ii v = graph[u][i];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first],v.first));
				}
			}
		}
		cout << "Case #" << ++caso << ": ";
		if(dist[dest] == 1<<20) cout << "unreachable\n";
		else cout << dist[dest] << "\n";
	}
}
