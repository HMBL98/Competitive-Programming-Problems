#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitados;
int v,e,T;

int main(){
	cin >> T;
	while(T--){
		cin >> v >> e;
		grafo.assign(v+1,vi());
		for(int i = 0; i < e; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		visitados.assign(v+1,-1);

		bool bipartite = true;
		int res = 0;
		for(int i = 0; i < v; i++){
			if(visitados[i] == -1){
				queue<int> q;
				q.push(i);
				visitados[i] = 1;
				int color1 = 0,color2 = 0;
				color1++;
				while(!q.empty()){
					int u = q.front(); q.pop();
					for(int j = 0; j < grafo[u].size(); j++){
						if(visitados[grafo[u][j]] == -1){
							visitados[grafo[u][j]] = !visitados[u];
							q.push(grafo[u][j]);
							if(!visitados[u] == 1) color1++;
							else color2++;
						}
						if(visitados[grafo[u][j]] == visitados[u]) bipartite = false;
					}
				}
				if(min(color1,color2) == 0) res += max(color1,color2);
				else res += min(color1,color2);
			}
		}
		if(bipartite){
			cout << res << endl;
		}else{
			cout << -1 << endl;
		}
	}
}
