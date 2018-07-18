#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> grafo;
int valor[200+10];
int v,x,y,e,q,caso;

int main(){
	while(cin >> v){
		for(int i = 1; i <= v; i++)cin >> valor[i];
		cin >> e;
		grafo.assign(v+1,vii());
		for(int i = 0; i < e; i++){
			cin >> x >> y;
			grafo[x].push_back({y,valor[y]-valor[x]});
		}
		vector<int> dist(v+1,100000); dist[1] = 0;
		for(int i = 1; i <= v-1; i++){
			for(int u = 1; u <= v; u++){
				for(int j = 0; j < grafo[u].size(); j++){
					ii v = grafo[u][j];
					dist[v.first] = min(dist[v.first],dist[u]+valor[v.first]-valor[u]);
				}
			}
		}
		cin >> q;
		cout << "Set #" << ++caso << "\n";
		while(q--){
			cin >> y;
			if(dist[y] < 3) cout << "?\n";
			else cout << dist[y] << "\n";
		}
	}
}
