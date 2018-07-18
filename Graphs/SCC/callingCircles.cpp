//247 - Calling Circles
#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef vector<int> vi;
vi dfs_low,dfs_num,visitado;
vector<vi> grafo;

int dfsNumberCounter,numSCC,n,m;

map<string,int> si;
map<int,string> is;

vi S;

vector< vector<string> > circles;

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
		vector<string> vs;
		while(1){
			int v = S.back(); S.pop_back(); visitado[v] = 0;
			vs.push_back(is[v]);
			if(u == v) break;
		}
		circles.push_back(vs);
	}

}
int main(){
	optimizar_io;
	int caso = 0;
	while(cin >> n >> m, (n||m)){
		if(caso) cout << '\n';
		grafo.assign(n+1,vi()); dfs_num.assign(n+1,-1); dfs_low.assign(n+1,0);
		visitado.assign(n+1,0);
		dfsNumberCounter = numSCC = 0;

		int idx = 1;
		for(int i = 0; i < m; i++){
			int idx1,idx2;
			string s1,s2; cin >> s1 >> s2;
			if(si[s1])idx1 = si[s1];
			else{
				idx1 = idx++; si[s1] = idx1;
				is[idx1] = s1;
			}
			if(si[s2])idx2 = si[s2];
			else{
				idx2 = idx++; si[s2] = idx2;
				is[idx2] = s2;
			}
			grafo[idx1].push_back(idx2);
		}
		for(int i = 1; i <= n; i++){
			if(dfs_num[i] == -1) dfs(i);
		}
		cout << "Calling circles for data set " << ++caso << ":\n";
		for(int i = 0; i < circles.size(); i++){
			for(int j = 0; j < circles[i].size(); j++){
				if(j) cout << ", ";
				cout << circles[i][j];
			}
			cout << '\n';
		}
		S.clear();
		si.clear();
		is.clear();
		circles.clear();
	}
}

