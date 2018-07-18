#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

#define MAX 100000+10
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<int> vi;

vector<vpll> graph;

ll dist[MAX],dist2[MAX];
int p[MAX],n,m;
vi res;

void path(int u){
	if(u == p[u]) res.push_back(u);
	else{
		res.push_back(u);
		path(p[u]);
	}
}
int main(){
	optimizar_io;
	cin >> n >> m;
	graph.assign(n,vpll());
	for(int i = 0; i < m; i++){
		ll x,y,c; cin >> x >> y >> c;
		graph[x].push_back({y,c});
		graph[y].push_back({x,c});
	}
	for(int i = 0; i < n; i++) dist[i] = dist2[i] = 1LL<<60;
	priority_queue< pll, vector<pll>, greater<pll> > pq;
	dist[1] = 0; pq.push(pll(0,1));
	while(!pq.empty()){
		pll act = pq.top(); pq.pop();
		ll d = act.first, u = act.second;
		if(d > dist[u]) continue;
		for(int i = 0; i < (int)graph[u].size(); i++){
			pll v = graph[u][i];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first] = dist[u]+v.second;
				pq.push(pll(dist[v.first],v.first));
			}
		}
	}
        priority_queue< pll, vector<pll>, greater<pll> > pq2;
        dist2[0] = 0; p[0] = 0; pq2.push(pll(0,0));
        while(!pq2.empty()){
                pll act = pq2.top(); pq2.pop();
                ll d = act.first, u = act.second;
                if(d > dist2[u]) continue;
                for(int i = 0; i < (int)graph[u].size(); i++){
                        pll v = graph[u][i];
                        if(dist[u]-dist[v.first] != v.second && dist2[u]+v.second < dist2[v.first]){
                                dist2[v.first] = dist2[u]+v.second;
				p[v.first] = u;
                                pq2.push(pll(dist2[v.first],v.first));
                        }
                }
        }
	if(dist2[1] == 1LL<<60) cout << "impossible\n";
	else{
		//cout << dist2[1] << "\n";
		path(1);
		reverse(res.begin(),res.end());
		cout << res.size() << " ";
		for(int i = 0; i < res.size(); i++){
			if(i) cout << " ";
			cout << res[i];
		}
		cout << "\n";
	}
}
