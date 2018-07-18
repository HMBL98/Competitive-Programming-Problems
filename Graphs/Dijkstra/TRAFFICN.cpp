//TRAFFICN - Traffic Network
#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vi;

vector<vii> graph;
vector<vii> graph2;
vector< pair<ii,ll> > edges;
ll dist[MAX],dist2[MAX],src,dest,n,m,k,t;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m >> k >> src >> dest;
		graph.assign(n,vii());
		graph2.assign(n,vii());
		edges.clear();
		src--; dest--;
		for(int i = 0; i < m; i++){
			ll x,y,c; cin >> x >> y >> c; x--; y--;
			graph[x].push_back({y,c});
			graph2[y].push_back({x,c});
		}
		for(int i = 0; i < k; i++){
			ll x,y,c; cin >> x >> y >> c; x--; y--;
			edges.push_back({{x,y},c});
		}
		for(int i = 0; i < n+10; i++) dist[i] = 1LL<<60;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		dist[src] = 0; pq.push(ii(0,src));
		while(!pq.empty()){
			ii act = pq.top(); pq.pop();
			ll d = act.first, u = act.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < (int)graph[u].size(); i++){
				ii v = graph[u][i];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first],v.first));
				}
			}
		}

		for(int i = 0; i < n+10; i++) dist2[i] = 1LL<<60;
                priority_queue< ii, vector<ii>, greater<ii> > pq2;
                dist2[dest] = 0; pq2.push(ii(0,dest));
                while(!pq2.empty()){
                        ii act = pq2.top(); pq2.pop();
                        ll d = act.first, u = act.second;
                        if(d > dist2[u]) continue;
                        for(int i = 0; i < (int)graph2[u].size(); i++){
                                ii v = graph2[u][i];
                                if(dist2[u]+v.second < dist2[v.first]){
                                        dist2[v.first] = dist2[u]+v.second;
                                        pq2.push(ii(dist2[v.first],v.first));
                                }
                        }
                }
		ll res = dist[dest];
		for(int i = 0; i < k; i++){
			pair<ii,ll> act = edges[i];
			res = min(res,dist[act.first.first]+act.second+dist2[act.first.second]);
			res = min(res,dist2[act.first.first]+act.second+dist[act.first.second]);
		}
		if(res == 1LL<<60) cout << -1 << "\n";
		else cout << res << "\n";
	}
}
