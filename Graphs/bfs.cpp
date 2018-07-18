//Breadth First Search: Shortest Reach
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> grafo;
vi visitado;

int q,n,m;

int main(){
	cin >> q;
	while(q--){
		cin >> n >> m;
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		for(int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		int s; cin >> s;
		queue<int> q; q.push(s);
		visitado[s] = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int i = 0; i < grafo[u].size(); i++){
				if(visitado[grafo[u][i]] == -1){
					visitado[grafo[u][i]] = visitado[u]+1;
					q.push(grafo[u][i]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(i != s){
				if(visitado[i] != -1) cout << visitado[i]*6 << " ";
				else cout << -1 << " ";
			} 
		}
		cout << '\n';
	}
}
