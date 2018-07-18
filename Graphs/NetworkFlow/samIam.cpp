#include <bits/stdc++.h>
using namespace std;

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
int R,C,N;
int main(){
	while(cin >> R >> C >> N,(R||C||N)){
		graph.assign(R,vi());
		for(int i = 0; i < N; i++){
			int y,x; cin >> y >> x; x--; y--;
			graph[y].push_back(x);
		}
		cout << kuhn(R,C) << "\n";
		for(int i = 0; i < R; i++) cout << i+1 << " " << seen[i] << "\n";
	  	for(int i = 0; i < C; i++){
    			if(match[i] != -1){
				cout << match[i]+1 << " " << i+1 << "\n";
				/*if(seen[match[i]])cout << " c" << i+1;
				else cout << " r" << match[i]+1;*/
	    		}
  		}
		cout << "\n";
	}
  	return 0;

}
