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
			grafo[x].push_back({y,(valor[y]-valor[x])*(valor[y]-valor[x])*(valor[y]-valor[x])});
		}
		vector<int> dist(v+1,100000); dist[1] = 0;
		for(int i = 0; i < v-1; i++){
			for(int u = 0; u < v; u++){
				for(int j = 0; j < (int)grafo[u+1].size(); j++){
					ii asd = grafo[u+1][j];
					dist[asd.first] = min(dist[asd.first],dist[u+1]+asd.second);
				}
			}
		}
		bool negativeCycle = false;
		for(int u = 0; u < v; u++){
			for(int j = 0; j < grafo[u].size(); j++){
				ii act = grafo[u][j];
				if(dist[act.first] > dist[u]+act.second) negativeCycle = true;
			}
		}
		cin >> q;
		cout << "Set #" << ++caso << "\n";
		while(q--){
			cin >> y;
			if(dist[y] < 3 || dist[y] == 100000 || negativeCycle) cout << "?\n";
			else cout << dist[y] << "\n";
		}
	}
}
