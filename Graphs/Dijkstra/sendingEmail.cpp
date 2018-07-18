#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> grafo;
vi dist;
int t,n,m,s,d,caso;

int main(){
	//optimizar_io;
	cin >> t;
	while(t--){
		cin >> n >> m >> s >> d;
		grafo.assign(n,vii());
		for(int i = 0; i < m; i++){
			int x,y,c; cin >> x >> y >> c;
			grafo[x].push_back({y,c});
			grafo[y].push_back({x,c});
		}
		dist.assign(n,1<<20); dist[s] = 0;
		priority_queue< ii, vector<ii>, greater<ii> > pq; 
		pq.push(ii(0,s));
		while(!pq.empty()){
			ii act = pq.top(); pq.pop();
			int d = act.first, u = act.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < grafo[u].size(); i++){
				ii v = grafo[u][i];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first],v.first));
				}
			}
		}
		cout << "Case #" << ++caso << ": ";
		if(dist[d] == 1<<20) cout << "unreachable\n";
		else cout << dist[d] << "\n";
	}
}
