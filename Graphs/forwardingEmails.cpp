#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<int> vi;
vector<vi> grafo;
vi visitado;
vi tam;
int t,n;

int dfs(int u){
	visitado[u] = 1;
	int tamanio = 0;
	if(grafo[u].size() == 1 && visitado[grafo[u][0]] == -1) tamanio += 1+dfs(grafo[u][0]);
	visitado[u] = -1;
	tam[u] = tamanio;
	return tamanio;
}
int main(){
	//optimizar_io;
	cin >> t;
	int caso = 0;
	while(t--){
		cin >> n;
		grafo.assign(n+1,vi());
		visitado.assign(n+1,-1);
		tam.assign(n+1,-1);
		for(int i = 0; i < n; i++){
			int x,y; cin >> x >> y;
			grafo[x].push_back(y);
		}
		int mayor = -1;
		int idx;
		for(int i = 1; i <= n; i++){
			if(tam[i] == -1)dfs(i);
			if(tam[i] > mayor){
				mayor = tam[i];
				idx = i;
			}
		}
		cout << "Case " << ++caso << ": " << idx << '\n';
	}
}
