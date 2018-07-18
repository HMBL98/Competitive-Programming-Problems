//247 - Calling Circles
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi dfs_low,dfs_num,visitado;
vector<vi> grafo;

int dfsNumberCounter,numSCC;

vi S;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visitado[u] = 1;
	for(int i = 0; i < grafo[u].size(); i++){
		int v = grafo[u][i];
		if(dfs_num[v] == -1) dfs(v);
		if(visitado[v]) dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		cout << "SCC " << ++numSCC << " ";
		while(1){
			int v = S.back(); S.pop_back(); visitado[v] = 0;
			cout << v << " ";
			if(u == v) break;
		}
		cout << '\n';
	}

}
int main(){
	int n; cin >> n;
	grafo.assign(n,vi()); dfs_num.assign(n,-1); dfs_low.assign(n,0);
	visitado.assign(n,0);
	dfsNumberCounter = numSCC = 0;
}

