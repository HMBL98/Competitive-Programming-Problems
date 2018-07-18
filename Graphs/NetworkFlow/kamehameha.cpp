#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 1000+10

typedef vector<int> vi;
int match[MAX],seen[MAX];
vector<vi> graph;

bool dfs(int u){
	if(seen[u]) return false;
	seen[u] = 1;
  	for(int i = 0; i < (int)graph[u].size(); i++){
    		int v = match[graph[u][i]];
    		if(v == -1 || dfs(v)){
      			match[graph[u][i]] = u;
      			return true;
    		}
  	}
  	return false;
}
int kuhn(int n1, int n2){
	fill(seen,seen+n1,0);
	fill(match, match + n2, -1);
  	int matches = 0;
  	for(int i = 0; i < n1; i++){
    		fill(seen,seen+n1,0);
    		if(dfs(i))matches++;
  	}
  	return matches;
}
int T,N;
map<int,int> X;
map<int,int> Y;
int main(){
	//optimizar_io;
	cin >> T;
	while(T--){
		cin >> N;
		int idx1 = 0;
		int idy1 = 0;
		graph.assign(N,vi());
		for(int i = 0; i < N; i++){
			int x,y; cin >> x >> y;
			int act1,act2;
			if(X.find(x) == X.end()){
				act1 = idx1++;
				X[x] = act1;
			}else act1 = X[x];
			if(Y.find(y) == Y.end()){
				act2 = idy1++;
				Y[y] = act2;
			}else act2 = Y[y];
			graph[act1].push_back(act2);
		}
		cout << kuhn(idx1,idy1) << "\n";
		X.clear(); Y.clear();
	}
  	return 0;
}
