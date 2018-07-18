#include <bits/stdc++.h>
using namespace std;

#define MAX 100000+10

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii graph[MAX];

long long dist[MAX],dist2[MAX];
int p[MAX],n,m;
set<int> used;

void path(int u){
	if(p[u] == u){
		used.insert(u);
	}else{
		path(p[u]);
		used.insert(u);
	}
}
int main(){
	optimizar_io;
	while(cin >> n >> m,(n||m)){
		for(int i = 0; i < m; i++){
			int x,y,c; cin >> x >> y >> c;
			graph[x].push_back({y,c});
			graph[y].push_back({x,c});
		}
		for(int i = 0; i < MAX; i++) dist[i] = 1LL<<60;
		priority_queue< ii, vector<ii>, greater<ii> > pq;
		dist[1] = 0; p[1] = 1; pq.push(ii(0,1));
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
		/*for(int i = 1; i <= n; i++){
			cout << i << "\t";
			for(int j = 0; j < graph[i].size(); j++) cout << graph[i][j].first << "," << graph[i][j].second << "\t";
			cout << "\n";
		}*/
		path(n);
		/*for(int i = 1; i <= n; i++){ 
                        cout << i << "\t";
                        for(int j = 0; j < graph[i].size(); j++) cout << graph[i][j].first << "," << graph[i][j].second << "\t";
                        cout << "\n";
                }*/
		for(int i = 0; i < MAX; i++) dist2[i] = 1LL<<60;
                priority_queue< ii, vector<ii>, greater<ii> > pq2;
                dist2[1] = 0; pq2.push(ii(0,1));
                while(!pq2.empty()){
                        ii act = pq2.top(); pq2.pop();
                        int d = act.first, u = act.second;
                        if(d > dist2[u]) continue;
                        for(int i = 0; i < (int)graph[u].size(); i++){
                                ii v = graph[u][i];
				if(used.find(v.first) == used.end() || (used.find(v.first) != used.end() && v.second != abs(dist[v.first]-dist[u]) ) ){
		                       	if(dist2[u]+v.second < dist2[v.first]){
	        	               		dist2[v.first] = dist2[u]+v.second;
	                	                pq2.push(ii(dist2[v.first],v.first));
					}
				}
                        }
                }
		if(dist2[n] == 1LL<<60) cout << "Do'oh!\n";
		else cout << dist2[n] << "\n";
		for(int i = 0; i <= n; i++) graph[i].clear();
		used.clear();
	}
}
