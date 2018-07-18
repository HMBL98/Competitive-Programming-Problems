#include <bits/stdc++.h>
using namespace std;

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX 5000+10

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int match[MAX],seen[MAX],prestige[MAX];
vector<ii> info;
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
        fill(match,match+n2,-1);
        int matches = 0;
        for(int i = info.size()-1; i >= 0; i--){
		int u = info[i].second;
                fill(seen,seen+n1,0);
                if(dfs(u))matches++;
        }
        return matches;
}
int N,M;
int main(){
	optimizar_io;
	cin >> N >> M;
	graph.assign(N,vi());
	for(int i = 0; i < N; i++){
		int w,c,y; cin >> w >> c;
		prestige[i] = w;
		info.push_back({w,i});
		for(int j = 0; j < c; j++){
			cin >> y; y--;
			graph[i].push_back(y);
		}
	}
	sort(info.begin(),info.end());
	int matches = kuhn(N,M);
	double digits = 0;
  	for(int i = 0; i < M; i++){
    		if(match[i] != -1){
			digits += log10((double)prestige[match[i]]); 
		}
  	}
	cout << floor(digits)+1 << "\n";
  	return 0;
}
