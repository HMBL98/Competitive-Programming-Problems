#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vector<vi> grafo;
vector<int> vistos;
int v;

int main(){
	optimizar_io;
	while(cin >> v,v){
		grafo.assign(v+1,vi());
		vistos.assign(v+1,-1);
		int x,y;
		while(cin >> x >> y,(x||y)){
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		queue<int> q;	q.push(1);
		vistos[1] = 1;
		bool bipartite = true;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < grafo[u].size(); i++){
				if(vistos[grafo[u][i]] == -1){
					vistos[grafo[u][i]] = !vistos[u];
					q.push(grafo[u][i]);
				}
				if(vistos[u] == vistos[grafo[u][i]]) bipartite = false;
			}
		}
		if(bipartite) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
