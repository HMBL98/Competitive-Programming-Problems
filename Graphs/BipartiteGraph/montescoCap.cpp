#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vector<int> visitados;
vector<vi> grafo;
int m,n;

int main(){
	optimizar_io;
	cin >> m;
	while(m--){
		cin >> n;
		grafo.assign(n+1,vi());
		visitados.assign(n+1,-1);
		for(int i = 1; i <= n; i++){
			int cuantos;
			cin >> cuantos;
			for(int j = 0; j < cuantos; j++){
				int des;cin >> des;
				grafo[i].push_back(des);
				grafo[des].push_back(i);
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++){
			if(visitados[i] == -1){
				bool status = true;
				int color1 = 0, color2 = 0;
				queue<int> q; q.push(i);
				visitados[i] = 1;
				color1++;
				while(!q.empty()){
					int u = q.front(); q.pop();
					for(int j = 0; j < grafo[u].size(); j++){
						if(visitados[grafo[u][j]] == -1 ){
							visitados[grafo[u][j]] = !visitados[u];
							q.push(grafo[u][j]);
							if(!visitados[u] == 1) color1++;
							else color2++;
						}
						if(visitados[grafo[u][j]] == visitados[u]){
							status = false;
						}
					}
				}
				if(status) res += max(color1,color2);
			}
		}
		cout << res << endl;
	}
}
