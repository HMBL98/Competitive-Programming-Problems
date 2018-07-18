#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi cantidad,visitado;
int t,n,m,total;


void dfs(int u){
	visitado[u] = 1;
	total += cantidad[u];
	for(int i = 0; i< grafo[u].size(); i++) if(visitado[grafo[u][i]] == -1) dfs(grafo[u][i]);
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		grafo.assign(n,vi());
		cantidad.assign(n,0);
		visitado.assign(n,-1);
		for(int i = 0; i < n; i++){
			cin >> cantidad[i];
		}
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		bool status = true;
		for(int i = 0; i < n; i++){
			if(visitado[i] == -1){
				total = 0;
				dfs(i);
				if(total != 0){
					status = false;
					break;
				}
			}
		}
		if(status)cout << "POSSIBLE\n";
		else cout << "IMPOSSIBLE\n";

	}
}
