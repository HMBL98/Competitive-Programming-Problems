#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> grafo;

int c,v,e,x,y,z;

int main(){
	cin >> c;
	while(c--){
		cin >> v >> e;
		grafo.assign(v,vii());
		for(int i = 0; i < e; i++){
			cin >> x >> y >> z;
			grafo[x].push_back({y,z});
		}
		vi dist(v,1000000); dist[0] = 0;
		for(int i = 0; i < v-1; i++){
			for(int u = 0; u < v; u++){
				for(int j = 0; j < (int)grafo[u].size(); j++){
					ii v = grafo[u][j];
					dist[v.first] = min(dist[v.first],dist[u]+v.second);
				}
			}
		}
		bool negativeCycle = false;
		for(int u = 0; u < v; u++){
			for(int j = 0; j < grafo[u].size(); j++){
				ii v = grafo[u][j];
				if(dist[v.first] > dist[u]+v.second) negativeCycle = true;
			}
		}
		if(negativeCycle)
			cout << "possible\n";
		else 
			cout << "not possible\n";
	}
}
