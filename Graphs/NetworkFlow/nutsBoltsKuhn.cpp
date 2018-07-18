#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 550

typedef vector<int> vi;
bool seen[MAX];
vector<vi> graph;
int match[MAX];

bool dfs(int u){
	if(seen[u]) return false;
	seen[u] = true;
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
	fill(seen,seen+n1, false);
	fill(match, match + n2, -1);
  	int matches = 0;
  	for(int i = 0; i < n1; i++){
    		fill(seen,seen+n1,false);
    		if(dfs(i))matches++;
  	}
  	return matches;
}

int main(){
	optimizar_io;
	int n1,n2,t,caseno = 0;;
	cin >> t;
	while(t--){
		cin >> n1 >> n2;
		graph.assign(n1,vi());
		for(int i = 0; i < n1; i++)for(int j = 0; j < n2; j++){
			int tmp; cin >> tmp;
			if(tmp)graph[i].push_back(j);
		}
                cout << "Case " << ++caseno << ": a maximum of " << kuhn(n1,n2) << " nuts and bolts can be fitted together\n";
	}
  	return 0;
}
